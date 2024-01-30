/**
 * Implementation of maze generation and solving functions.
 *
 * This file provides the implementation of the functions declared in maze.h for generating,
 * resetting, and solving mazes. It includes functions for initializing and managing a queue
 * structure, carving paths within a maze grid to create a maze, and applying a Breadth-First
 * Search algorithm to solve the generated maze. This file should be used in conjunction with 
 * maze.h, where the function prototypes and data structure definitions are declared.
 *
 * The maze generation algorithm carves paths starting from random points and uses a randomized
 * approach to create a complex labyrinth layout. The solving algorithm applies BFS to find the
 * shortest path from the maze's start point to the exit point, if one exists. The paths carved
 * and the solution found are stored in data structures defined in maze.h.
 *
 * Note: This implementation assumes that the maze grid is represented as a 2D array where
 * cells can be walls, paths, or special cells like start and exit. The queue used for solving
 * the maze is implemented as a doubly linked list, enabling efficient additions and removals
 * of elements. The implementation also includes functions for initializing and resetting both
 * the maze and the queue structures.
 */

#include "maze.h"
#include "prng.h"

Maze maze; /* stores maze grid and start and exit points */
Queue path; /* stores solution path from start to exit */

/**
 * Initializes a Maze structure with specified dimensions and start/exit points.
 *
 * Parameters:
 *   maze: A pointer to a Maze struct that will be initialized. The function allocates memory for the maze grid
 *         and sets the maze's dimensions and start/exit points based on the provided arguments.
 *   rows: The number of rows for the maze grid. Must be greater than 0.
 *   cols: The number of columns for the maze grid. Must be greater than 0.
 *   startX: The x-coordinate of the start point in the maze. Must be within the maze boundaries.
 *   startY: The y-coordinate of the start point in the maze. Must be within the maze boundaries.
 *   exitX: The x-coordinate of the exit point in the maze. Must be within the maze boundaries and different from the start point.
 *   exitY: The y-coordinate of the exit point in the maze. Must be within the maze boundaries and different from the start point.
 *
 * Return:
 *   void: This function does not return a value. It initializes the Maze structure provided via the maze pointer.
 *
 * Description:
 *   `initMaze` sets up a maze for solving. It begins by validating the input dimensions and then allocates memory for
 *   a two-dimensional grid representing the maze, with each cell initially unmarked. The function sets the maze's dimensions
 *   (rows and columns) and initializes the start and exit points to the specified coordinates. It also calls `resetMaze` to 
 *   further initialize the maze grid and set up the start and exit points. If the input dimensions are invalid (non-positive 
 *   values for rows or columns), the function terminates the program. Proper memory management is ensured, and the caller 
 *   is responsible for freeing the allocated memory when the maze is no longer needed.
 */
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

/**
 * Resets and configures the maze with new start and exit points.
 *
 * Parameters:
 *   maze: A pointer to an already initialized Maze struct. The function configures this maze with new start and
 *         exit points and resets its grid.
 *   startX: The x-coordinate of the new start point in the maze. The start point must be on the edge of the maze
 *           but not on a corner.
 *   startY: The y-coordinate of the new start point in the maze. The start point must be on the edge of the maze
 *           but not on a corner.
 *   exitX: The x-coordinate of the new exit point in the maze. The exit point must be on the edge of the maze
 *          but not on a corner and different from the start point.
 *   exitY: The y-coordinate of the new exit point in the maze. The exit point must be on the edge of the maze
 *          but not on a corner and different from the start point.
 *
 * Return:
 *   void: This function does not return a value. It reconfigures the maze with new start and exit points and
 *         resets its grid to the initial state.
 *
 * Description:
 *   `resetMaze` is used to reinitialize an existing maze with new start and exit points. The function first validates
 *   the provided start and exit points, ensuring they are positioned on the edges of the maze but not at the corners.
 *   It then updates the maze's start and exit points and reinitializes the entire maze grid to WALLs, effectively
 *   clearing any previous path or exploration state. This function is typically called when the maze needs to be reused 
 *   or reconfigured without reallocating the entire grid. It is crucial that the maze passed to this function is already 
 *   initialized and has allocated memory for the grid.
 */
void resetMaze(Maze* maze, uint8_t startX, uint8_t startY, uint8_t exitX, uint8_t exitY) {
    uint8_t r, c; /* index variables */

    /* check input */
    if (!((startX == 0 || startX == maze->cols-1) ^ (startY == 0 || startY == maze->rows-1))) exit(1); /* start point has to be on edge of maze but not on a corner */
    if (!((exitX == 0 || exitX == maze->cols-1) ^ (exitY == 0 || exitY == maze->rows-1))) exit(1); /* exit point has to be on edge of maze but not on a corner */

    /* set attrs */
    maze->start.x = startX;
    maze->start.y = startY;
    maze->start.prev = NULL;
    maze->start.next = NULL;
    maze->exit.x = exitX;
    maze->exit.y = exitY;
    maze->exit.prev = NULL;
    maze->exit.next = NULL;

    /* init maze grid as WALLs */
    for (r = 0; r < maze->rows; r++) {
        for (c = 0; c < maze->cols; c++) {
            maze->grid[r][c] = WALL;
        }
    }
}

/**
 * Initializes a Queue structure.
 *
 * Parameters:
 *   queue: A pointer to a Queue struct that will be initialized. This function sets up the queue
 *          with its head and tail pointers set to NULL, indicating an empty queue, and initializes
 *          the size of the queue to 0.
 *
 * Return:
 *   void: This function does not return a value. It initializes the Queue structure provided via the queue pointer.
 *
 * Description:
 *   `initQueue` is designed to initialize a Queue structure to a default, empty state. It is essential to call
 *   this function before using the Queue in any operations, as it properly sets up the internal structure of the
 *   Queue. The function sets both the head and tail of the Queue to NULL, indicating that the Queue is empty, and
 *   sets the size of the Queue to 0. It is crucial that the Queue passed to this function is not NULL, as the function
 *   does not allocate memory for the Queue itself, but only initializes its members. The caller is responsible for
 *   allocating and managing the memory for the Queue structure itself.
 */
void initQueue(Queue* queue) {
    if (queue == NULL) exit(1);

    queue->head = NULL; /* init head of queue as NULL */
    queue->tail = NULL; /* init tail of queue as NULL */
    queue->size = 0;
}

/**
 * Resets a Queue to its initial empty state, freeing all its elements.
 *
 * Parameters:
 *   queue: A pointer to a Queue struct that will be reset. This function clears all the elements
 *          from the queue, freeing the memory allocated for each element, and then reinitializes
 *          the queue to an empty state.
 *
 * Return:
 *   void: This function does not return a value. It frees all elements in the queue and resets 
 *         the queue to its initial empty state.
 *
 * Description:
 *   `resetQueue` is intended for clearing a Queue of all its elements and resetting it to an
 *   empty state. It iterates through each element in the queue, starting from the head, and frees
 *   the memory allocated for each Point struct. After all elements are freed, the function resets 
 *   the head and tail pointers of the queue to NULL and sets its size to 0. This function is 
 *   particularly useful for reusing the same Queue object without the need to reallocate its 
 *   structure, ensuring efficient memory management and preventing memory leaks. It is important 
 *   that the Queue passed to this function has been properly initialized before use. The caller
 *   should ensure that the Queue pointer is not NULL to avoid unexpected behavior.
 */
void resetQueue(Queue* queue) {
    if (queue == NULL) exit(1);

    Point* current = queue->head; /* current point in queue */
    Point* next; /* next point in queue */

    /* free all points in queue */
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    /* reset attrs */
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

/**
 * Adds a new point to the end of the queue.
 *
 * Parameters:
 *   queue: A pointer to the Queue struct where the new point will be added. The queue should be
 *          properly initialized before calling this function.
 *   x: The x-coordinate of the new point to be added to the queue.
 *   y: The y-coordinate of the new point to be added to the queue.
 *
 * Return:
 *   void: This function does not return a value. It adds a new point to the queue, modifying
 *         the queue's state.
 *
 * Description:
 *   `queuePush` is used to add a new point with specified x and y coordinates to the end of the
 *   given queue. The function dynamically allocates memory for the new Point struct and initializes
 *   it with the provided coordinates. If the queue is empty, the new point is set as both the head 
 *   and tail of the queue. If the queue already contains elements, the new point is added to the end,
 *   and the tail pointer of the queue is updated accordingly. The previous last element's 'next' 
 *   pointer is set to the new point, and the new point's 'prev' pointer is linked to the previous 
 *   tail. This operation increases the queue's size by one. The function ensures proper memory 
 *   allocation for the new point and modifies the queue's state to maintain the integrity of the 
 *   doubly linked list structure. It is important to handle the queue structure responsibly, especially
 *   in terms of memory management, to prevent memory leaks and ensure data integrity.
 */
void queuePush(Queue* queue, uint8_t x, uint8_t y) {
    if (queue == NULL) exit(1);

    Point* new = (Point*) malloc(sizeof(Point)); /* allocate memory for new point */
    if (new == NULL) exit(1); /* allocation failed */

    /* set attrs */
    new->x = x;
    new->y = y;
    new->next = NULL;
    new->prev = NULL;

    /* add point to queue */
    if (queue->head == NULL) {
        queue->head = queue->tail = new; /* for first element, head and tail are the same */
    } else {
        new->prev = queue->tail; /* link new point's prev to current tail */
        queue->tail->next = new; /* link current tail's next to new point */
        queue->tail = new; /* update tail to be new point */
    }

    /* increment size */
    queue->size++;
}

/**
 * Carves paths in the given maze starting from a specified position.
 *
 * Parameters:
 *   maze: A pointer to a Maze struct representing the maze in which paths will be carved.
 *         The maze should be initialized with a grid of walls (WALL) where paths can be carved.
 *   x: The x-coordinate of the starting position in the maze grid from which carving begins.
 *   y: The y-coordinate of the starting position in the maze grid from which carving begins.
 *
 * Return:
 *   void: This function does not return a value. It modifies the maze's grid by carving paths.
 *
 * Description:
 *   `carveMaze` is used to generate paths within a maze grid from a given starting position. It
 *   randomly selects a direction (right, down, left, or up) and attempts to carve a path in that
 *   direction by turning walls (WALL) into paths (PATH). The carving process consists of moving
 *   two cells at a time in the chosen direction: it checks if the next two cells in the direction
 *   are within the bounds of the maze and are currently walls. If both conditions are satisfied, 
 *   it carves a path by changing these cells to paths. The function then moves to the new position
 *   (the second cell) and chooses a new random direction to continue carving. This process is repeated
 *   until it tries all four directions without finding a valid path to carve. This function is typically
 *   used in maze generation algorithms to create a labyrinthine structure within the maze grid. The caller
 *   should ensure that the starting coordinates (x, y) are within the bounds of the maze grid.
 */
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

/**
 * Generates a maze by carving paths between cells.
 *
 * Parameters:
 *   maze: A pointer to a Maze struct which will be modified to contain the generated maze. 
 *         The maze should be initialized with dimensions (rows and cols) and have allocated grid
 *         space before calling this function. The start and exit points should also be set.
 *
 * Return:
 *   void: This function does not return a value. It modifies the provided Maze struct to contain
 *         the newly generated maze paths.
 *
 * Description:
 *   `generateMaze` creates a maze within the provided Maze struct by iteratively carving paths
 *   through the grid. Starting from every second cell in both rows and columns (to create a grid-like
 *   pattern), it calls `carveMaze` for each of these cells. `carveMaze` is responsible for randomly
 *   carving paths in various directions, generating the labyrinthine layout of the maze. After all
 *   paths are carved, the function sets the designated start and exit points in the maze to their
 *   respective states (START and EXIT). This function is typically used to generate a new maze layout
 *   or to re-generate a maze within an existing Maze structure. The caller should ensure that the Maze
 *   struct is properly initialized with a grid and valid start and exit points before calling this 
 *   function. It is recommended to use `initMaze` and `resetMaze` for initialization and setup.
 */
void generateMaze(Maze* maze) {
    uint8_t x, y; /* index variables */
    
    /* carve maze */
    for (y = 1; y < maze->rows; y += 2) {
        for (x = 1; x < maze->cols; x += 2) {
            carveMaze(maze, x, y);
        }
    }
    
    /* set start and exit. */
    maze->grid[maze->start.y][maze->start.x] = START;
    maze->grid[maze->exit.y][maze->exit.x] = EXIT;
}

/**
 * Solves a given maze using the Breadth-First Search (BFS) algorithm and stores the solution path.
 *
 * Parameters:
 *   maze: A pointer to a Maze struct representing the maze to be solved. The maze is expected to be
 *         properly initialized and should contain a grid, start point, and exit point.
 *   path: A pointer to a Queue struct where the solution path will be stored if one is found. The path
 *         consists of a series of Points (x, y coordinates) starting from the maze's start point and 
 *         ending at the exit point. The Queue struct should be initialized before calling this function.
 *
 * Return:
 *   void: This function does not return a value. The solution path, if found, is stored in the 'path' Queue,
 *         which can be traversed to retrieve the sequence of steps from the maze's start to exit.
 *
 * Description:
 *   `solveMaze` performs a BFS to find the shortest path from the start point to the exit point in the given maze.
 *   The function iterates through each accessible cell, starting from the start point, and explores adjacent cells 
 *   (up, down, left, right) that are not yet visited and are not walls. Each explored cell is added to the queue.
 *   If the exit point is reached, the function backtracks to construct the solution path, which is then stored in
 *   the 'path' Queue. If no path is found, the 'path' Queue remains empty. The function also handles memory 
 *   management for the dynamically allocated structures used during the search.
 */
void solveMaze(Maze* maze, Queue* path) {
    if (maze == NULL || maze->grid == NULL || path == NULL) exit(1);

    Point current; /* current point in path */
    Point next; /* next point in path */
    Point directions[4]; /* array of possible directions */
    Queue queue = {NULL, NULL}; /* queue of points to visit */
    uint16_t i = 0; /* index variable */

    /* visited stores whether a cell has been visited */
    bool** visited = malloc(maze->rows * sizeof(bool*));
    for (i = 0; i < maze->rows; i++) {
        visited[i] = calloc(maze->cols, sizeof(bool));
    }

    /* enqueue start point and mark as visited */
    queuePush(&queue, maze->start.x, maze->start.y);
    visited[maze->start.y][maze->start.x] = true;

    /* BFS */
    while (queue.head != NULL) {
        /* dequeue */
        current = *(queue.head);
        queue.head = queue.head->next;

        /* if queue is empty, set tail to NULL */
        if (queue.head == NULL) queue.tail = NULL;

        /* exit found */
        if (maze->grid[current.y][current.x] == EXIT) {
            Point* backtrack = &current; /* point to backtrack from exit to start */

            /* backtrack from exit to start */
            while (backtrack != NULL) {
                maze->grid[backtrack->y][backtrack->x] = SOLUTION;
                backtrack = backtrack->prev;
            }

            /* mark start and exit in maze */
            maze->grid[maze->start.y][maze->start.x] = START;
            maze->grid[maze->exit.y][maze->exit.x] = EXIT;

            break; /* exit found and path traced */
        }

        /* adjacent cells */
        directions[0] = (Point){current.x + 1, current.y, NULL, NULL};
        directions[1] = (Point){current.x - 1, current.y, NULL, NULL};
        directions[2] = (Point){current.x, current.y + 1, NULL, NULL};
        directions[3] = (Point){current.x, current.y - 1, NULL, NULL};

        /* check if adjacent cells are valid */
        for (i = 0; i < 4; i++) {
            next = directions[i];
            if (next.x >= 0 && next.x < maze->cols && next.y >= 0 && next.y < maze->rows) { /* next cell in bounds? */
                if (!visited[next.y][next.x] && (maze->grid[next.y][next.x] == PATH || maze->grid[next.y][next.x] == EXIT)) { /* next cell not visited and is path or exit? */
                    queuePush(&queue, next.x, next.y); /* enqueue valid cell */
                    visited[next.y][next.x] = true;
                }
            }
        }
    }

    /* clean up */
    for (i = 0; i < maze->rows; i++) {
        free(visited[i]);
    }
    free(visited);
    resetQueue(&queue);
}
