#include <stdio.h>
#include <stdlib.h>
#include "moon.h"

int
main(int argc, char **argv) {
  if (argc != 2) {
    printf("Invalid parameter\n");
    exit(EXIT_FAILURE);
  }

  struct Moon moons[MOON_COUNT];
  read_file(argv[1], moons);
  for (int i = 1; i <= 1000; i++)
    step(moons);
  return EXIT_SUCCESS;
}
