#include <stdio.h>
#include <stdlib.h>
#include "rule.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Invalid arguments");
    exit(EXIT_FAILURE);
  }

  read_file(argv[1]);
}
