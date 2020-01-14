#include <stdlib.h>
#include <stdio.h>

#include "lib.h"

int pattern_size = 4;

int
main(int argc, char* argv[]) {
  if (argc != 2 && argc != 3) {
    printf("Invalid arguments");
    exit(EXIT_FAILURE);
  }
  char *file_name = argv[1];
  int phase_count = 10;
  if (argv[2]) {
    phase_count = atoi(argv[2]);
  }

  int *numbers;
  int size = read_file(file_name, &numbers);
  int *new_numbers = duplicate_array(numbers, size, 10000);
  free(numbers);
  numbers = new_numbers;
  size *= 10000;

  int pattern[] = { 0, 1, 0, -1 };

  for (int i = 0; i < phase_count; i++) {
    int *new_numbers = calculate_phase(numbers, size, pattern, pattern_size);
    free(numbers);
    numbers = new_numbers;
  }

  print_phase(numbers, size);
  free(numbers);
  return EXIT_SUCCESS;
}
