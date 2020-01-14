#include <stdlib.h>
#include <stdio.h>

#include "lib.h"

int
read_file(char *file_name, int **result) {
  FILE *fd = fopen(file_name, "r");
  if (fd == NULL)
    return 0;
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
  return size;
}

// [1,2,3] -> [1,2,3,1,2,3]
int*
repeat_pattern(int pattern[], int pattern_size, int size) {
  int *result = malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++) {
    result[i] = pattern[i % pattern_size];
  }
  return result;
}

// pattern: [1,2,3], repeat_count: 2 -> [1,1,2,2,3,3]
// pattern: [1,2,3], repeat_count: 3 -> [1,1,1,2,2,2,3,3,3]
int*
duplicate_pattern(int *pattern, int pattern_size, int repeat_count) {
  int *result = malloc(sizeof(int) * pattern_size * repeat_count);
  for(int i = 0; i < pattern_size; i++) {
    for (int j = 0; j < repeat_count; j++)
      result[repeat_count * i + j] = pattern[i];
  }
  return result;
}

int *extend_pattern(int *pattern, int pattern_size, int repeat_count, int input_size) {
  int *duplicated_pattern = duplicate_pattern(pattern, pattern_size, repeat_count);
  int *repeated = repeat_pattern(duplicated_pattern, pattern_size * repeat_count, input_size + 1);
  return repeated;
}

int
calculate_element(int input[], int input_size, int pattern[], int pattern_size, int element_position) {
  int *repeated = extend_pattern(pattern, pattern_size, element_position, input_size + 1);
  int sum = 0;
  for(int i = 0; i < input_size; i++)
    sum += (repeated[i + 1] * input[i]);
  free(repeated);
  return abs(sum) % 10;
}

void print_phase(int *numbers, int size) {
  for(int pos = 0; pos < size; pos++)
    printf("%d", numbers[pos]);
  printf("\n");

}

int *calculate_phase(int *numbers, int size, int *pattern, int pattern_size) {
  int *new_numbers = malloc(sizeof(int) * size);
  for (int pos = 0; pos < size; pos++)
    new_numbers[pos] = calculate_element(numbers, size, pattern, pattern_size, pos + 1);
  return new_numbers;
}
