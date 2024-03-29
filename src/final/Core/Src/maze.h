#ifndef SRC_MAZE_H_
#define SRC_MAZE_H_

#include <stdarg.h> /* for variadic functions */
#include <stdbool.h>
#include <stdint.h> /* for uint8_t */
#include <stdio.h>
#include <stdlib.h>

/* cell types */
enum {PATH, WALL, START, EXIT, SOLUTION};

typedef struct {
    int x;
    int y;
    int prevX; /* to track path */
    int prevY; /* to track path */
} Point;

typedef struct {
    Point* p;
    uint16_t size;
    uint16_t count;
} Path;

typedef struct {
    uint8_t rows;   /* number of rows in maze */
    uint8_t cols;   /* number of columns in maze */
    Point start;    /* start point */
    Point exit;     /* exit point */
    uint8_t** grid; /* pointer to 2D array representing maze */
} Maze;

extern Maze maze;
extern Path path;

void initMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY);
void resetMaze(Maze* maze, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY);
void initPath(Path* path, uint16_t pathSize);
void resetPath(Path* path);
void pathPush(Path* path, Point* point);
void carveMaze(Maze* maze, uint8_t x, uint8_t y);
void generateMaze(Maze* maze);
void solveMaze(Maze* maze, Path* path);

#endif /* SRC_MAZE_H_ */
