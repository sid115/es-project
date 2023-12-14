# C Library to address LEDs 

> Work in Progress

This is not a library yet, but a collection of functions that can be tested in `main()`. The goal is to refine these functions and implement them in a proper library.

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
./lib <whatever your main needs>
```

## TODO

- test coord2Index for correctness and speed
- implement a lookup table to store all indices for each coordinate
