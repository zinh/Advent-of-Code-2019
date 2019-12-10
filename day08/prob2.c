#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WIDTH 25
#define HEIGHT 6
#define DEPTH 100
#define BLACK '0'
#define WHITE '1'

int read_file(char *, char image[DEPTH][HEIGHT][WIDTH]);
void print_layer(char image[HEIGHT][WIDTH]);
int write_image(char*, char image[DEPTH][HEIGHT][WIDTH]);

int
main(int argc, char **argv){
  if (argc != 2)
    exit(EXIT_FAILURE);
  char *file_name = argv[1];
  char image[DEPTH][HEIGHT][WIDTH];
  int result = read_file(file_name, image);
  write_image("output.ppm", image);
  return 0;
}

int
read_file(char *file_name, char image[DEPTH][HEIGHT][WIDTH]) {
  FILE* fd = fopen(file_name, "r");
  if (fd == NULL)
    return -1;
  char c;
  int layer = 0, width = 0, height = 0;
  while ((c = getc(fd)) != EOF) {
    //if (layer == 0)
    //  printf("%c", c);
    image[layer][height][width] = c;
    if ((width == WIDTH) && (height == HEIGHT)) {
      width = 0;
      height = 0;
      layer++;
      continue;
    } 
    if (width + 1 >= WIDTH) {
      width = 0;
      height++;
    } else {
      width++; 
    }
  }
  fclose(fd);

  return 1;
}

int
write_image(char *file_name, char image[DEPTH][HEIGHT][WIDTH]) {
  FILE* fd = fopen(file_name, "w");
  fprintf(fd, "P1\n");
  fprintf(fd, "%d %d\n", WIDTH, HEIGHT);
  for (int h = 0; h < HEIGHT; h++) {
    for (int w = 0; w < WIDTH; w++) {
      for (int layer = 0; layer < DEPTH; layer++) {
        //if (layer == 0)
        //  putchar(image[layer][h][w]);
        char color = image[layer][h][w];
        if (color == BLACK) {
          fprintf(fd, "1 ");
          break;
        } else if (color == WHITE) {
          fprintf(fd, "0 ");
          break;
        }
      }
    }
    fprintf(fd, "\n");
  }
  fclose(fd);
  return 0;
}

void
print_layer(char image[HEIGHT][WIDTH]) {
  for (int h = 0; h < HEIGHT; h++) {
    for (int w = 0; w < WIDTH; w++)
      putchar(image[h][w]);
    printf("\n");
  }
}
