/* Header file for maze generation and solving functionality */

#ifndef SRC_MAZE_H_
#define SRC_MAZE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Cell types in maze grid */
enum {PATH, WALL, START, EXIT, SOLUTION};

/* Represents a point in the maze with x and y coordinates. 
 * It is doubly linked to potentially represent a path. */
typedef struct Point {
    int x; /* x coordinate */
    int y; /* y coordinate */
    struct Point *prev; /* pointer to previous point in path */
    struct Point *next; /* pointer to next point in path */
} Point;

/* A Queue data structure, implemented as a doubly linked list, 
 * used for storing and managing points in a path. */
typedef struct {
    Point* head; /* pointer to first point in queue */
    Point* tail; /* pointer to last point in queue */
    uint16_t size; /* number of points in queue */
} Queue;

/* Maze structure with dimensions, start and exit points, 
 * and a grid representing the maze layout. */
typedef struct {
    uint8_t rows;   /* number of rows in maze */
    uint8_t cols;   /* number of columns in maze */
    Point start;    /* start point */
    Point exit;     /* exit point */
    uint8_t** grid; /* pointer to 2D array representing maze */
} Maze;

/* Global maze and path variables */
extern Maze maze;
extern Queue path;

/* Function prototypes */
void initMaze(Maze* maze, uint8_t rows, uint8_t cols, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY);
void resetMaze(Maze* maze, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY);
void initQueue(Queue* queue);
void resetQueue(Queue* queue);
void queuePush(Queue* queue, uint8_t x, uint8_t y);
void carveMaze(Maze* maze, uint8_t x, uint8_t y);
void generateMaze(Maze* maze);
void solveMaze(Maze* maze, Queue* path);

#endif /* SRC_MAZE_H_ */
