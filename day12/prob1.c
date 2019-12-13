#include <stdio.h>
#include <stdlib.h>

#define MOON_COUNT 4
#define DIMENSION 3

struct Point {
  int x, y, z;
};

void print_point(struct Point p) {
  printf("(%d, %d, %d)", p.x, p.y, p.z);
}

struct Point 
parse_line(char *line) {
  int pos = 0, n = 0, sign = 1, idx = 0;
  int a[3];
  char c;
  while ((c = line[pos++]) != '\0') {
    if (c == '<' || c == '>' || c == ' ')
      continue;
    if (c >= '0' && c <= '9'){
      n = n * 10 + (c - '0');
    }
    if (c == '-')
      sign = -1;
    if (c == ',') {
      a[idx] = sign * n;
      n = 0;
      sign = 1;
      idx++;
    }
  }
  a[idx] = sign * n;
  struct Point p = {a[0], a[1], a[2]};
  return p;
}

int
main(int argc, char **argv) {
  if (argc != 2) {
    printf("Invalid parameter\n");
    exit(EXIT_FAILURE);
  }

  FILE *fd;
  fd = fopen(argv[1], "r");
  if (fd == NULL) {
    printf("File not found\n");
    exit(EXIT_FAILURE);
  }
  char *line = NULL;
  size_t linecapp = 0;
  while (getline(&line, &linecapp, fd) != EOF) {
    struct Point p = parse_line(line);
    print_point(p);
  }

  fclose(fd);
  return EXIT_SUCCESS;
}
