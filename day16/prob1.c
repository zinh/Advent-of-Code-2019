#include <stdlib.h>
#include <stdio.h>

void read_file(char *, int **, int *);

int
main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Invalid arguments");
    exit(EXIT_FAILURE);
  }
  char *file_name = argv[1];
  int *numbers;
  int size;
  read_file(file_name, &numbers, &size);
  for (int i = 0; i < size; i++)
    printf("%d = %d\n", i, numbers[i]);
  free(numbers);
  return EXIT_SUCCESS;
}

void
read_file(char *file_name, int **result, int *return_size) {
  FILE *fd = fopen(file_name, "r");
  if (fd == NULL)
    return;
  char c;
  int size = 0, max_size = 10;
  int *numbers = malloc(sizeof(int) * max_size);
  while ((c = getc(fd)) != '\n') {
    if (size >= max_size) {
      max_size += 10;
      numbers = realloc(numbers, max_size);
    }
    numbers[size++] = c - '0';
  }
  *result = numbers;
  *return_size = size;
}
