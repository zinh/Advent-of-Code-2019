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
	if (pos1 > size || pos2 > size || result_pos > size) {
	  printf("Invalid memory access\n");
	  return 0;
	}
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

void print(int* in, int size){
  for (int i = 0; i < size; i++)
    printf("%d,", in[i]);
  printf("\n");
}
int
main(){
  char* line;
  line = read_input("01.input");
  int* opcodes = NULL;
  int size =  parse_input(line, &opcodes);
  for (int noun = 0; noun < 100; noun++) {
    for (int verb = 0; verb < 100; verb++) {
      int *new_opcodes = malloc(sizeof(int) * size);
      memcpy(new_opcodes, opcodes, sizeof(int) * size);
      print(new_opcodes, size);

      new_opcodes[1] = noun;
      new_opcodes[2] = verb;
      
      int result = run(new_opcodes, size);
      free(new_opcodes);
      if (result == 19690720) {
	goto BREAK;
      }
    }
  }
 BREAK:
  free(line);
  free(opcodes);
  return 0;
}
