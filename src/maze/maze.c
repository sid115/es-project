#include <stdarg.h> /* for variadic functions */
#include <stdbool.h>
#include <stdint.h> /* for uint8_t */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   /* for srand() */

#define PATH_FILEPATH "path.txt" /* path to path.txt as string */
#define MAZE_FILEPATH "maze.txt" /* path to maze.txt as string */

/* error messages */
#define ERR_NO_ROWS           "Number of rows is 0."
#define ERR_NO_COLS           "Number of columns is 0."
#define ERR_START_NOT_IN_MAZE "The start point is not inside the maze."
#define ERR_EXIT_NOT_IN_MAZE  "The exit point is not inside the maze."
#define ERR_START_NOT_ON_EDGE "The start point is not on an edge of the maze."
#define ERR_EXIT_NOT_ON_EDGE  "The exit point is not on an edge of the maze."
#define ERR_START_ON_CORNER   "The start point is on a corner of the maze."
#define ERR_EXIT_ON_CORNER    "The exit point is on a corner of the maze."
#define ERR_START_IS_EXIT     "The start and exit point are the same."
#define ERR_USAGE             "Usage: ./maze rows cols startY startX exitY exitX"
#define ERR_FILE              "Error opening file."

/* cell types */
#define PATH     0
#define WALL     1
#define START    2
#define EXIT     3
#define SOLUTION 4

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t prevX; /* to track path */
    uint8_t prevY; /* to track path */
} Point;

typedef struct {
    uint8_t rows;   /* number of rows in maze */
    uint8_t cols;   /* number of columns in maze */
    Point start;    /* start point */
    Point exit;     /* exit point */
    uint8_t** grid; /* pointer to 2D array representing maze */
} Maze;

void initializeMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY);
void carveMaze(Maze *maze, uint8_t x, uint8_t y);
void flipPath(Point* path, uint16_t pathSize);
void generateMaze(Maze* maze);
void solveMaze(Maze* maze, Point* path, const uint16_t pathSize);
void writeMaze(Maze* maze, const char* filepath);
void writePath(Point* path, uint16_t pathSize, const char* filepath);
void freeMaze(Maze* maze);
void err(const char* message, ...);

int main(int argc, char *argv[]) {
    /* check args */
    if (argc != 7) err(ERR_USAGE); /* number of args has to be 7 */

    /* convert args to ints */
    uint8_t rows   = atoi(argv[1]);
    uint8_t cols   = atoi(argv[2]);
    uint8_t startY = atoi(argv[3]);
    uint8_t startX = atoi(argv[4]);
    uint8_t exitY  = atoi(argv[5]);
    uint8_t exitX  = atoi(argv[6]);

    /* check input */
    if (rows == 0) err(ERR_NO_ROWS);                                                                           /* number of rows must be greater than 0 */
    if (cols == 0) err(ERR_NO_COLS);                                                                           /* number of cols must be greater than 0 */
    if (startX == exitX && startY == exitY) err(ERR_START_IS_EXIT);                                            /* start and exit must be different */
    if (startX >= cols || startY >= rows) err(ERR_START_NOT_IN_MAZE);                                          /* start point has to be inside the maze */
    if (exitX >= cols || exitY >= rows) err(ERR_EXIT_NOT_IN_MAZE);                                             /* exit point has to be inside the maze */
    if (!((startX == 0 || startX == cols-1) || (startY == 0 || startY == rows-1))) err(ERR_START_NOT_ON_EDGE); /* start point has to be on edge of maze */
    if (!((exitX == 0 || exitX == cols-1) || (exitY == 0 || exitY == rows-1))) err(ERR_EXIT_NOT_ON_EDGE);      /* exit point has to be on edge of maze */
    if ((startX == 0 || startX == cols-1) && (startY == 0 || startY == rows-1)) err(ERR_START_ON_CORNER);      /* start point must not be on corner of maze */
    if ((exitX == 0 || exitX == cols-1) && (exitY == 0 || exitY == rows-1)) err(ERR_EXIT_ON_CORNER);           /* exit point must not be on corner of maze */

    /* start */
    Maze maze;
    const uint16_t pathSize = rows * cols; // TODO: can be adjusted to sqrt(rows * cols)? allocate size dynamically?
    Point* path = malloc(pathSize * sizeof(Point)); /* solution */

    initializeMaze(&maze, rows, cols, startX, startY, exitX, exitY);
    generateMaze(&maze);
    solveMaze(&maze, path, pathSize);

    writeMaze(&maze, MAZE_FILEPATH); // TODO: delete for implementation on uC
    writePath(path, pathSize, PATH_FILEPATH); // TODO: instead of writing to a file, just pass path to animate function

    freeMaze(&maze);
    free(path);

    return 0;
}

void initializeMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY) {
    uint8_t r, c; /* index variables */

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

void carveMaze(Maze *maze, uint8_t x, uint8_t y) {
    uint8_t x1, y1;
    uint8_t x2, y2;
    uint8_t dx, dy;
    uint8_t dir, count;

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
        
        if(x2 > 0 && x2 < maze->cols && y2 > 0 && y2 < maze->rows /* inbounce? */
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

void flipPath(Point* path, uint16_t pathSize) {
    if (path == NULL) return;

    /* TODO: allocate with number of non 0s instead of pathSize?  */
    Point* temp = (Point*) malloc(pathSize * sizeof(Point)); /* temp array */
    uint16_t i = 0;
    uint16_t index = 0; /* index of temp array */
    for (i = pathSize - 1; i >= 0; i--) {
        if (path[i].x == 0 && path[i].y == 0) { /* only write non 0s */
            temp[index++] = path[i];
        }
    }

    /* fill rest with 0s (see TODO) */
    for (i = index; i < pathSize; i++) {
        temp[i].x = 0;
        temp[i].y = 0;
    }

    path = temp;
    free(temp);
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

void solveMaze(Maze* maze, Point* path, const uint16_t pathSize) {
    if (maze == NULL || maze->grid == NULL || path == NULL) return;

    uint16_t i = 0; /* index var */
    Point current;
    uint8_t x, y = 0; /* copy of current */
    Point next;
    uint16_t cnt = 0; /* counter for path array */

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
                path[cnt].x = x;
                path[cnt].y = y;
                cnt++;
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

    //flipPath(path, pathSize); // TODO: seg fault

    /* clean up */
    for (i = 0; i < maze->rows; i++) {
        free(visited[i]);
    }
    free(visited);
    free(queue);
}

void writeMaze(Maze* maze, const char* filepath) {
    FILE* file = fopen(filepath, "w");
    int r, c; /* index variables */

    if (file == NULL) err(ERR_FILE);

    for (r = 0; r < maze->rows; r++) {
        for (c = 0; c < maze->cols; c++) {
            fprintf(file, "%d", maze->grid[r][c]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void writePath(Point* path, uint16_t pathSize, const char* filepath) {
    FILE* file = fopen(filepath, "w");
    int i; /* index variable */

    if (file == NULL) err(ERR_FILE);

    for (i = 0; i < pathSize; i++) {
        fprintf(file, "%d %d\n", path[i].x, path[i].y);
    }

    fclose(file);
}

void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
}

void err(const char* errMessage, ...) {
    va_list messages;

    va_start(messages, errMessage); /* init arg list */
    const char* optMessage = va_arg(messages, char*); /* get next arg (if any) */
    va_end(messages); /* clean up arg list */

    printf("%s\n", errMessage);

    if (optMessage) {
        printf("%s\n", optMessage);
    }

    exit(EXIT_FAILURE);
}
