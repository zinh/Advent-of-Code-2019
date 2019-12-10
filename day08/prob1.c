#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WIDTH 25
#define HEIGHT 6

int read_file(char *);

int
main(int argc, char **argv){
  if (argc != 2)
    exit(EXIT_FAILURE);
  char *file_name = argv[1];
  int result = read_file(file_name);
  printf("Result: %d\n", result);
  return EXIT_SUCCESS;
}

int
read_file(char *file_name) {
  FILE* fd = fopen(file_name, "r");
  if (fd == NULL)
    return -1;
  char c;
  int size = WIDTH * HEIGHT;
  int i = 0, current_zero = 0, current_one = 0, current_two = 0;
  int min_zero = INT_MAX;
  int result = 0;
  while ((c = getc(fd)) != EOF) {
    //printf("%c", c);
    if (c == '0') current_zero++;
    if (c == '1') current_one++;
    if (c == '2') current_two++;
    if (++i >= size) {
      if (current_zero < min_zero) {
        result = current_one * current_two;
        min_zero = current_zero;
      }
      i = 0;
      current_zero = 0;
      current_one = 0;
      current_two = 0;
    }
  }

  return result;
}
