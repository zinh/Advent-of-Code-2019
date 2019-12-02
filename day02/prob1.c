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

int run(int* opcodes, int size) {
  int pointer = 0;
  while (opcodes[pointer] != 99) {
    int op = opcodes[pointer];
    switch (op) {
    case 1:
    case 2:
      {
	int pos1 = opcodes[pointer + 1];
	int pos2 = opcodes[pointer + 2];
	int result_pos = opcodes[pointer + 3];
	printf("pos1 = %d, pos2 = %d, result = %d\n", pos1, pos2, result_pos);
	int r = op == 1 ? opcodes[pos1] + opcodes[pos2] : opcodes[pos1] * opcodes[pos2];
	opcodes[result_pos] = r;
	pointer += 4;
	break;
      }
    default:
      return 0;
    }
  }
  return opcodes[0];
}

int
main(){
  char* line;
  line = read_input("01.input");
  int* opcodes = NULL;
  int size =  parse_input(line, &opcodes);
  opcodes[1] = 12;
  opcodes[2] = 2;
  int result = run(opcodes, size);
  printf("Result = %d\n", result);
  free(line);
  free(opcodes);
  return 0;
}
