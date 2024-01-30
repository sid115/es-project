/**
 * Header file for maze generation, solving, and related utility functions.
 *
 * This file provides the definitions and function prototypes for managing and interacting with 
 * mazes. It includes the necessary structures and functions to create, reset, solve, and manipulate
 * mazes for various applications, such as games, simulations, and algorithm demonstrations.
 *
 * Key structures:
 *  - Point: Represents a coordinate in the maze with x and y values, and links to previous and next points.
 *  - Queue: A doubly linked list structure, used for storing and handling points in a maze-solving path or other sequences.
 *  - Maze: Represents the maze structure, including dimensions, start and exit points, and the grid layout.
 *
 * Functions included:
 *  - initMaze: Initializes a Maze structure with specified dimensions and start/exit points.
 *  - resetMaze: Resets and reconfigures a Maze with new start and exit points, and clears its paths.
 *  - initQueue: Initializes a Queue structure for path storage and management.
 *  - resetQueue: Clears and resets a Queue to its initial state.
 *  - queuePush: Adds a new point to a Queue.
 *  - carveMaze: Carves paths in the maze grid from a given position.
 *  - generateMaze: Generates the layout of a maze by iteratively carving paths.
 *  - solveMaze: Solves the maze using Breadth-First Search (BFS) and stores the solution path.
 *
 * These functions provide a comprehensive toolkit for creating and solving mazes, allowing for
 * customization and flexibility in maze design and solving strategies. The Maze structure can be
 * used for both 2D grid-based mazes and more complex layouts, while the Queue structure provides 
 * efficient path tracking and manipulation capabilities.
 */

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
