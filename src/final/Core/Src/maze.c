#include "maze.h"
#include "prng.h"

Maze maze;
Path path;

void initMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY) {
    uint8_t r; /* index variable */

    /* check input */
    if (rows <= 0) exit(1); /* number of rows must be greater than 0 */
    if (cols <= 0) exit(1); /* number of cols must be greater than 0 */

    /* allocate memory */
    maze->grid = (uint8_t**) malloc(rows * sizeof(uint8_t*));
    for (r = 0; r < rows; r++) {
        maze->grid[r] = (uint8_t*) malloc(cols * sizeof(uint8_t));
    }

    /* set attrs */
    maze->rows = rows;
    maze->cols = cols;
    resetMaze(maze, startX, startY, exitX, exitY);
}

void resetMaze(Maze* maze, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY) {
    uint8_t r, c; /* index variables */

    /* check input */
    if (exitX >= maze->cols || exitY >= maze->rows) exit(1);                                            /* exit point has to be inside the maze */
    if (!((startX == 0 || startX == maze->cols-1) || (startY == 0 || startY == maze->rows-1))) exit(1); /* start point has to be on edge of maze */
    if (!((exitX == 0 || exitX == maze->cols-1) || (exitY == 0 || exitY == maze->rows-1))) exit(1);     /* exit point has to be on edge of maze */
    if ((startX == 0 || startX == maze->cols-1) && (startY == 0 || startY == maze->rows-1)) exit(1);    /* start point must not be on corner of maze */
    if ((exitX == 0 || exitX == maze->cols-1) && (exitY == 0 || exitY == maze->rows-1)) exit(1);        /* exit point must not be on corner of maze */

    /* set attrs */
    maze->start.x = startX;
    maze->start.y = startY;
    maze->start.prevX = -1;
    maze->start.prevY = -1;
    maze->exit.x = exitX;
    maze->exit.y = exitY;
    maze->exit.prevX = -1;
    maze->exit.prevY = -1;

    /* init maze grid as WALLs */
    for (r = 0; r < maze->rows; r++) {
        for (c = 0; c < maze->cols; c++) {
            maze->grid[r][c] = WALL;
        }
    }
}

void initPath(Path* path, uint16_t length) {
    path->p = (Point *) malloc(length * sizeof(Point));
    
    if (path == NULL) exit(1);
    
    path->size = length;
    resetPath(path);
}

void resetPath(Path* path) {
    for (uint16_t i = 0; i < path->size; i++) {
        path->p[i].x = 0;
        path->p[i].y = 0;
        path->p[i].prevX = -1;
        path->p[i].prevY = -1;
    }

    path->count = 0;
}

void pathPush(Path* path, Point* point) {
    path->p[path->count] = *point;
    path->count++;

    if (path->count == path->size) exit(1);
}

void carveMaze(Maze *maze, uint8_t x, uint8_t y) {
    int x1, y1; /* coords of next cell */
    int x2, y2; /* coords of cell after next cell */
    int dx, dy; /* direction deltas */
    int dir = 0; /* direction. 0 = right; 1 = down; 2 = left; else = up */
    int count = 0; /* counts directions failed */

    /* get initial direction */
    dir = getRand(&rng) % 4;

    /* try all 4 directions */
    while (count < 4) {
        /* reset directions */
        dx = 0; dy = 0;

        /* translate dir to direction deltas */
        switch (dir) {
            case 0:  dx = 1;  break; /* right */
            case 1:  dy = 1;  break; /* down */
            case 2:  dx = -1; break; /* left */
            default: dy = -1; break; /* up */
        }

        /* calculate new positions based on direction */
        x1 = x + dx;
        y1 = y + dy;
        x2 = x1 + dx;
        y2 = y1 + dy;
        
        /* check if next two cells are in bounds and are walls */
        if (x2 >= 0 && x2 < maze->cols /* next cell in bounds? */
         && y2 >= 0 && y2 < maze->rows /* next next cell in bounds? */
         && maze->grid[y1][x1] == WALL /* next cell wall? */
         && maze->grid[y2][x2] == WALL) { /* next next cell wall? */   

            /* carve path */
            maze->grid[y1][x1] = PATH;
            maze->grid[y2][x2] = PATH;

            /* move to new position */
            x = x2; y = y2;

            /* get new direction and reset counter */
            dir = getRand(&rng) % 4;
            count = 0;
        } else {
            /* change direction and increment counter if carving not possible */
            dir = (dir + 1) % 4;
            count++;
        }
    }
}

void generateMaze(Maze* maze) {
    uint8_t x, y;
    
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

    Point current; /* current point in maze */
    Point next; /* next point to move to */
    Point directions[4]; /* possible points to reach from current */
    uint16_t i = 0; /* index var */

    /* keep track of visited cells */
    bool** visited = malloc(maze->rows * sizeof(bool*));
    for (i = 0; i < maze->rows; i++) {
        visited[i] = calloc(maze->cols, sizeof(bool));
    }

    /* queue stores next possible points during BFS */
    Point* queue = malloc(maze->rows * maze->cols * sizeof(Point));
    uint16_t front = 0; /* start of queue where elements are removed */
    uint16_t rear = 0; /* end of queue where new elements are added */

    /* enqueue start point and mark it as visited */
    pathPush(path, &maze->start);
    queue[rear++] = maze->start;
    visited[maze->start.y][maze->start.x] = true;

    /* BFS loop */
    while (front < rear) {
        /* dequeue point */
        current = queue[front++];

        /* exit found? */
        if (maze->grid[current.y][current.x] == EXIT) {
            /* backtrack */
            while (!(current.x == maze->start.x && current.y == maze->start.y)) {
                maze->grid[current.y][current.x] = SOLUTION; /* mark point as solution */
                pathPush(path, &(Point){current.x, current.y, -1, -1}); /* add point to solution path */

                /* find previous point in path */
                for (i = 0; i < rear; i++) {
                    if (queue[i].x == current.x && queue[i].y == current.y) {
                        current.x = queue[i].prevX;
                        current.y = queue[i].prevY;
                        break;
                    }
                }
            }

            /* mark start and exit in maze */
            maze->grid[maze->start.y][maze->start.x] = START;
            maze->grid[maze->exit.y][maze->exit.x] = EXIT;

            break; /* exit found and path traced */
        }

        /* add adjacent cells to queue if they are valid */
        directions[0] = (Point){current.x + 1, current.y, current.x, current.y}; /* right */
        directions[1] = (Point){current.x - 1, current.y, current.x, current.y}; /* left */
        directions[2] = (Point){current.x, current.y + 1, current.x, current.y}; /* down */
        directions[3] = (Point){current.x, current.y - 1, current.x, current.y}; /* up */

        for (i = 0; i < 4; i++) {
            next = directions[i];
            if (next.x >= 0 && next.x < maze->cols && next.y >= 0 && next.y < maze->rows) { /* in bounds? */
                if (!visited[next.y][next.x] && (maze->grid[next.y][next.x] == PATH || maze->grid[next.y][next.x] == EXIT)) {
                    queue[rear++] = next;  /* enqueue valid adjacent cell */
                    visited[next.y][next.x] = true;
                }
            }
        }
        /* break if writing beyond allocated memory */
        if (rear >= maze->rows * maze->cols) break;
    }

    /* clean up */
    for (i = 0; i < maze->rows; i++) {
        free(visited[i]);
    }
    free(visited);
    free(queue);
}
