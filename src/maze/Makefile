CC=gcc
TARGET=maze
SRC=maze.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) maze.txt path.txt

.PHONY: all clean
