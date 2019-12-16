#include <stdio.h>
#include <string.h>

#include "rule.h"

void print_map(struct Map m) {
  printf("%d %s\n", m.count, m.name);
}

struct Map parse_token(char *token) {
  char c;
  char label[10];
  int label_size = 0;
  int i = 0, cnt = 0;
  while((c = token[i++]) != '\0') {
    if (c >= '0' && c <= '9')
      cnt = cnt * 10 + (c - '0');
    if (c >= 'A' && c <= 'Z')
      label[label_size++] = c;
  }
  label[label_size] = '\0';
  struct Map result = {cnt, label};
  return result;
}

struct Rule read_file(char *file_name) {
  FILE *fd = fopen(file_name, "r");

  char *line;
  size_t linecapp;
  while (getline(&line, &linecapp, fd) != EOF) {
    char *token;
    int cnt = 0;
    while((token = strsep(&line, ",=")) != NULL) {
      struct Map m = parse_token(token);
      print_map(m);
    }
  }

  fclose(fd);
}
