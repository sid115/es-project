#include "maze.h"

Maze maze;
Path path;

void initMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY) {
    uint8_t r, c; /* index variables */

    /* check input */
    if (rows == 0) exit(1);                                                                 /* number of rows must be greater than 0 */
    if (cols == 0) exit(1);                                                                 /* number of cols must be greater than 0 */
    if (startX == exitX && startY == exitY) exit(1);                                        /* start and exit must be different */
    if (startX >= cols || startY >= rows) exit(1);                                          /* start point has to be inside the maze */
    if (exitX >= cols || exitY >= rows) exit(1);                                            /* exit point has to be inside the maze */
    if (!((startX == 0 || startX == cols-1) || (startY == 0 || startY == rows-1))) exit(1); /* start point has to be on edge of maze */
    if (!((exitX == 0 || exitX == cols-1) || (exitY == 0 || exitY == rows-1))) exit(1);     /* exit point has to be on edge of maze */
    if ((startX == 0 || startX == cols-1) && (startY == 0 || startY == rows-1)) exit(1);    /* start point must not be on corner of maze */
    if ((exitX == 0 || exitX == cols-1) && (exitY == 0 || exitY == rows-1)) exit(1);        /* exit point must not be on corner of maze */

    maze->rows = rows;
    maze->cols = cols;
    maze->start.x = startX;
    maze->start.y = startY;
    maze->start.prevX = -1;
    maze->start.prevY = -1;
    maze->exit.x = exitX;
    maze->exit.y = exitY;
    maze->exit.prevX = -1;
    maze->exit.prevY = -1;

    /* allocate memory */
    maze->grid = (uint8_t**) malloc(rows * sizeof(uint8_t*));
    for (r = 0; r < rows; r++) {
        maze->grid[r] = (uint8_t*) malloc(cols * sizeof(uint8_t));
    }

    /* initialize maze grid as WALLs */
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            maze->grid[r][c] = WALL;
        }
    }
}

void initPath(Path* path, uint16_t length) {
    path->p = (Point *) malloc(length * sizeof(Point));
    
    if (path == NULL) exit(1);
    
    for (uint16_t i = 0; i < length; i++) {
        path->p[i].x = 0;
        path->p[i].y = 0;
        path->p[i].prevX = -1;
        path->p[i].prevY = -1;
    }
    path->size = length;
}

void pathPush(Path* path, Point* point) {
    static uint16_t cnt = 0; /* counter for path array */

    path->p[cnt] = *point;
    cnt++;
}

void carveMaze(Maze *maze, uint8_t x, uint8_t y) {
    int x1, y1;
    int x2, y2;
    int dx, dy;
    int dir, count;

    dir = rand() % 4;
    count = 0;

    while (count < 4) {
        dx = 0; dy = 0;
        switch (dir) {
            case 0:  dx = 1;  break;
            case 1:  dy = 1;  break;
            case 2:  dx = -1; break;
            default: dy = -1; break;
        }

        x1 = x + dx;
        y1 = y + dy;
        x2 = x1 + dx;
        y2 = y1 + dy;
        
        if (x2 > 0 && x2 < maze->cols && y2 > 0 && y2 < maze->rows /* inbounce? */
           && maze->grid[y1][x1] == WALL && maze->grid[y2][x2] == WALL) { /* wall? */
            maze->grid[y1][x1] = PATH;
            maze->grid[y2][x2] = PATH;
            x = x2; y = y2;
            dir = rand() % 4;
            count = 0;
        } else {
            dir = (dir + 1) % 4;
            count += 1;
        }
    }
}

void flipPath(Path* path) {
    uint16_t left = 0;
    uint16_t right = path->size - 1;
    Point temp;

    while (left < right) {
        /* swap elements at left and right indices */
        temp = path->p[left];
        path->p[left] = path->p[right];
        path->p[right] = temp;

        /* move left index to the right and right index to the left */
        left++;
        right--;
    }
}

void generateMaze(Maze* maze) {
    uint8_t x, y;
    
    /* RNG */
    srand(time(0));
    
    /* carve the maze */
    for(y = 1; y < maze->rows; y += 2) {
        for(x = 1; x < maze->cols; x += 2) {
            carveMaze(maze, x, y);
        }
    }
    
    /* set start and exit. */
    maze->grid[maze->start.y][maze->start.x] = START;
    maze->grid[maze->exit.y][maze->exit.x] = EXIT;
}

void solveMaze(Maze* maze, Path* path) {
    if (maze == NULL || maze->grid == NULL || path == NULL) exit(1);

    uint16_t i = 0; /* index var */
    Point current;
    uint8_t x, y = 0; /* copy of current */
    Point next;

    bool** visited = malloc(maze->rows * sizeof(bool*)); /* keep track of visited cells */
    for (i = 0; i < maze->rows; i++) {
        visited[i] = calloc(maze->cols, sizeof(bool));
    }

    /* initialize queue */
    Point* queue = malloc(maze->rows * maze->cols * sizeof(Point));
    uint16_t front = 0; /* start of queue where elements are removed */
    uint16_t rear = 0; /* end of queue where new elements are added */

    /* enqueue start point */
    Point start = {maze->start.x, maze->start.y, -1, -1};
    pathPush(path, &start);
    queue[rear++] = start;
    visited[maze->start.y][maze->start.x] = true;

    while (front < rear) {
        /* dequeue point */
        current = queue[front++];

        /* exit found */
        if (maze->grid[current.y][current.x] == EXIT) {
            x = current.x;
            y = current.y;

            /* trace back path, mark it and write it to solution path */
            while (!(x == start.x && y == start.y)) {
                maze->grid[y][x] = SOLUTION;
                pathPush(path, &(Point){x, y, -1, -1}); // TODO: prevX, prevY needed?
                for (i = 0; i < rear; i++) {
                    if (queue[i].x == x && queue[i].y == y) {
                        x = queue[i].prevX;
                        y = queue[i].prevY;
                        break;
                    }
                }
            }

            maze->grid[maze->start.y][maze->start.x] = START;
            maze->grid[current.y][current.x] = EXIT;

            break; /* exit found and path traced */
        }

        /* visit adjacent cells */
        Point directions[4] = {
            {current.x + 1, current.y, current.x, current.y}, /* right */
            {current.x - 1, current.y, current.x, current.y}, /* left */
            {current.x, current.y + 1, current.x, current.y}, /* down */
            {current.x, current.y - 1, current.x, current.y}  /* up */
        };

        for (i = 0; i < 4; i++) {
            next = directions[i];
            if (next.x >= 0 && next.x < maze->cols && next.y >= 0 && next.y < maze->rows) {
                if (!visited[next.y][next.x] && (maze->grid[next.y][next.x] == PATH || maze->grid[next.y][next.x] == EXIT)) {
                    queue[rear++] = next;  /* enqueue valid adjacent cell */
                    visited[next.y][next.x] = true;
                }
            }
        }
        if (rear >= maze->rows * maze->cols) break; /* prevents writing beyond allocated memory */
    }

    flipPath(path);
    trimPath(path);

    /* clean up */
    for (i = 0; i < maze->rows; i++) {
        free(visited[i]);
    }
    free(visited);
    free(queue);
}

void trimPath(Path* path) {
    uint16_t newSize = 0;
    uint16_t i = 0; /* index var */

    /* count the non-zero elements in the array */
    for (i = 0; i < path->size; i++) {
        if (path->p[i].x != 0 && path->p[i].y != 0) {
            newSize++;
        }
    }

    if (newSize == 0) {
        path->size = 0;
    } else {
        /* create temp array to hold non-zero elements */
        Path newPath;
        initPath(&newPath, newSize);

        /* copy non-zero elements to new path */
        uint16_t newIndex = 0;
        for (i = 0; i < path->size; i++) {
            if (path->p[i].x != 0 && path->p[i].y != 0) {
                newPath.p[newIndex] = path->p[i];
                newIndex++;
            }
        }

        /* copy the contents of newPath to path */
        for (i = 0; i < newSize; i++) {
            path->p[i] = newPath.p[i];
        }
        path->size = newSize;
    }
}

void freeMaze(Maze* maze) {
    for (uint16_t i = 0; i < maze->rows; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
}

void freePath(Path* path) {
    free(path->p);
}
