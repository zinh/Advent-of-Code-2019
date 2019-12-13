#include "moon.h"

extern "C" void read_file(char *file_name, struct Moon moons[MOON_COUNT]);
extern "C" void step(struct Moon moons[]);

int
main(int argc, char **argv){
  struct Moon moons[MOON_COUNT];
  read_file(argv[1], moons);
  for (int i = 1; i <= 1000; i++){
    step(moons);
  }
  return 0;
}
