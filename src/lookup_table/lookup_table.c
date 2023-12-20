#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PANEL_WIDTH 8
#define FILEPATH "lookup_table.txt"

uint16_t** create2DArray(uint16_t rows, uint16_t cols) 
{
  uint16_t** arr = (uint16_t**) malloc(rows * sizeof(uint16_t*));

  for (uint16_t r = 0; r < rows; r++) 
  {
    arr[r] = (uint16_t*) malloc(cols * sizeof(uint16_t));
  }

  return arr;
}

void free2DArray(uint16_t** arr, uint16_t rows) 
{
  for (uint16_t r = 0; r < rows; r++)
  {
    free(arr[r]);
  }
  free(arr);
}

void write2DArray(uint16_t** arr, uint16_t rows, uint16_t cols, const char* filepath) 
{
  FILE* file = fopen(filepath, "w");
  uint16_t r, c;

  for (r = 0; r < rows; r++) 
  {
    fprintf(file, "{ ");
    for (c = 0; c < cols; c++) 
    {
      if (c == cols - 1)
      {
        fprintf(file, "%d", arr[r][c]);
      }
      else 
      {
        fprintf(file, "%d, ", arr[r][c]);
      }
    }
    if (r == rows - 1)
    {
      fprintf(file, " }");
    }
    else 
    {
      fprintf(file, " },\n");
    }
  }

  fclose(file);
}

int main(int argc, char* argv[])
{
  if (argc != 3) 
  {
    fprintf(stderr, "Usage: %s <height> <width>\n", argv[0]);
    return 1;
  }

  const int height = atoi(argv[1]);
  const int width = atoi(argv[2]);

  if (height <= 0 || width <= 0) 
  {
    fprintf(stderr, "Error: height or width must be greater than 0\n");
    return 1;
  }

  uint16_t x, y;
  uint16_t** lookup_table = create2DArray(height, width);

  for (y = 0; y < height; y++) 
  {
    for (x = 0; x < width; x++) 
    {
      lookup_table[y][x] = x % PANEL_WIDTH + y * PANEL_WIDTH + (x / PANEL_WIDTH) * (PANEL_WIDTH * height);
    }
  }

  write2DArray(lookup_table, height, width, FILEPATH);

  return 0;
}
