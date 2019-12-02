#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_input(char* file_name){
  FILE* fd = fopen(file_name, "r");
  char* line = NULL;
  size_t linecap = 0;
  getline(&line, &linecap, fd);
  fclose(fd);
  return line;
}

int parse_input(char* line, int** out) {
  char* token;
  int array_size = 10;
  int* result = malloc(sizeof(int) * 10);
  int i = 0;
  while ((token = strsep(&line, ",")) != NULL) {
    if (i > array_size) {
      array_size += 10;
      result = (int*)realloc(result, array_size);
    }
    result[i++] = atoi(token);
  }
  *out = result;
  return i;
}

int
main(){
  char* line;
  line = read_input("01.input");
  int* opcodes = NULL;
  int size =  parse_input(line, &opcodes);
  for (int i = 0; i < size; i++)
    printf("%d\n", opcodes[i]);
  
  free(line);
  free(opcodes);
  return 0;
}
