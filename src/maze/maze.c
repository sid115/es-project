#include <stdarg.h> /* for variadic functions */
#include <stdint.h> /* for uint8_t */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   /* for srand() */

#define FILEPATH "maze.txt" /* path to maze.txt as string */

/* error messages */
#define ERR_NO_ROWS           "Number of rows is 0."
#define ERR_NO_COLS           "Number of columns is 0."
#define ERR_START_NOT_IN_MAZE "The start point is not inside the maze."
#define ERR_EXIT_NOT_IN_MAZE  "The exit point is not inside the maze."
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
    uint8_t rows;   /* number of rows in maze */
    uint8_t cols;   /* number of columns in maze */
    uint8_t startX; /* x coordinate of start point */
    uint8_t startY; /* y coordinate of start point */
    uint8_t exitX;  /* x coordinate of exit point */
    uint8_t exitY;  /* y coordinate of exit point */
    uint8_t** grid; /* pointer to 2D array representing maze */
} Maze;

void initializeMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY);
void carveMaze(Maze *maze, uint8_t x, uint8_t y);
void generateMaze(Maze* maze);
void solveMaze(Maze* maze);
void writeMaze(Maze* maze, const char* filepath);
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
    if (rows == 0) err(ERR_NO_ROWS);                                /* number of rows must be greater than 0 */
    if (cols == 0) err(ERR_NO_COLS);                                /* number of cols must be greater than 0 */
    if (startX == exitX && startY == exitY) err(ERR_START_IS_EXIT); /* start and exit must be different */
    if (startX > cols || startY > rows) err(ERR_START_NOT_IN_MAZE); /* start point has to be inside the maze */
    if (exitX > cols || exitY > rows) err(ERR_EXIT_NOT_IN_MAZE);    /* exit point has to be inside the maze */

    /* start */
    Maze maze;
    initializeMaze(&maze, rows, cols, startX, startY, exitX, exitY);
    generateMaze(&maze);
    solveMaze(&maze); /* TODO */
    writeMaze(&maze, FILEPATH);
    freeMaze(&maze);
    return 0;
}

void initializeMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY) {
    uint8_t r, c; /* index variables */

    maze->rows = rows;
    maze->cols = cols;
    maze->startX = startX;
    maze->startY = startY;
    maze->exitX = exitX;
    maze->exitY = exitY;

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
    maze->grid[maze->startY][maze->startX] = START;
    maze->grid[maze->exitY][maze->exitX] = EXIT;
}

void solveMaze(Maze* maze) {
    /* TODO */
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
