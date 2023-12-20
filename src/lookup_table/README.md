# Generate lookup table

Generate a lookup table to map from (x, y) to the index of an LED in the LED array.

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
./lookup_table <height> <width>
```

(height and width counted in number of LEDs)
