# Testing maze generation and solving

> Work in Progress

Create a maze on our LED matrix and find a way to fly our drone through it.

## Compile

> Tested on Linux only! This probably won't work on Windows.

Use the [Makefile](./Makefile) to compile:

```bash
make
```

## Execute

> Tested on Linux only! This probably won't work on Windows.

Run: 

```bash
./maze <rows> <cols> <startX> <startY> <exitX> <exitY>
```

## TODO

- mazes do not seem to have walls on the right and bottom
- adapt [solving alg](https://raw.githubusercontent.com/joewing/maze/master/maze.c)
- implement multiple starts/exits
- tbh, I am not really sure if all mazes are solvable
