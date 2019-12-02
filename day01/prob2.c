#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int fuel(int*, int*);

int
main(){
  FILE *fp;
  char *line = NULL;
  int lines[MAX_SIZE];
  size_t linecap = 0;
  ssize_t linelen;
  int total = 0;

  fp = fopen("01.input", "r");
  if (fp == NULL){
    exit(EXIT_FAILURE);
  }

  int size = 0;
  while ((linelen = getline(&line, &linecap, fp)) > 0) {
    int n = atoi(line);
    lines[size++] = n;
  }

  while (size > 0) {
    int result = fuel(lines, &size);
    total += result;
  }

  fclose(fp);
  free(line);

  printf("Result = %d\n", total);
  return EXIT_SUCCESS;
}

int fuel(int fuels[], int *size) {
  int total = 0;
  int j = 0;
  for (int i = 0; i < *size; i++){
    int next_value = fuels[i] / 3 - 2;
    if (next_value > 0) {
      total += next_value;
      fuels[j++] = next_value;
    }
  }
  *size = j;
  return total;
}
