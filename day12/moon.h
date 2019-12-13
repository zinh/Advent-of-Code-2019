#define MOON_COUNT 4
#define DIMENSION 3

struct Point {
  int x, y, z;
};

struct Moon {
  struct Point position;
  struct Point velocity;
};

void step(struct Moon moons[MOON_COUNT]);
void read_file(char *file_name, struct Moon moons[MOON_COUNT]);
