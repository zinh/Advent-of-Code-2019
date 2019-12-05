#include <stdio.h>
#include <stdlib.h>

int
digit_to_array(int n, int** out) {
  int capp = 10;
  int* result = malloc(sizeof(int) * capp);
  int size = 0;
  while (n > 0) {
    result[size++] = n % 10;
    n = n / 10;
    if (size >= capp) {
      capp += 10;
      result = realloc(result, sizeof(int) * capp);
    }
  }
  *out = result;
  return size;
}

int
is_non_decreasing(int* n, int size) {
  for (int i = size- 1; i > 0; i-- ) {
    if (n[i] > n[i - 1])
      return 0;
  }
  return 1;
}

int
two_adjacent(int* n, int size) {
  int count = 0;
  for (int i = size - 1; i > 0; i--) {
    if (n[i] == n[i - 1])
      count++;
  }
  return count > 0;
}

int
main(int argc, char** argv) {
  if (argc != 3)
    return 1;
  int from = atoi(argv[1]);
  int to = atoi(argv[2]);
  int count = 0;
  for(int i = from; i <= to; i++) {
    int* digits = NULL;
    int size = digit_to_array(i, &digits);
    if (two_adjacent(digits, size) && is_non_decreasing(digits, size))
      count++;
    free(digits);
  }
  printf("Result: %d\n", count);
  return 0;
}
