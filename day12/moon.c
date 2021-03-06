#include <stdio.h>
#include <stdlib.h>
#include "moon.h"

void 
print_point(struct Point p) {
  printf("(%d, %d, %d)", p.x, p.y, p.z);
}

void 
print_moon(struct Moon m) {
  printf("pos=<x=%d, y=%d, z=%d>, vel=<x=%d, y=%d, z=%d>\n", 
      m.position.x, m.position.y, m.position.z, 
      m.velocity.x, m.velocity.y, m.velocity.z);
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

int accelerate(x1, x2) {
  if (x1 > x2)
    return -1;
  else if (x1 < x2)
    return 1;
  else
    return 0;
}

struct Point
calc_accelerate(struct Moon m1, struct Moon m2) {
  struct Point a1 = { accelerate(m1.position.x, m2.position.x),
    accelerate(m1.position.y, m2.position.y),
    accelerate(m1.position.z, m2.position.z) };
  struct Point a2 = { accelerate(m2.position.x, m1.position.x),
    accelerate(m2.position.y, m1.position.y),
    accelerate(m2.position.z, m1.position.z) };
  return a1;
}

void
update_position(struct Moon *m) {
  struct Point pos = {m->position.x + m->velocity.x, 
    m->position.y + m->velocity.y, 
    m->position.z + m->velocity.z};
  m->position = pos;
}


int 
calc_energy(struct Moon m) {
  int potential = abs(m.position.x) + abs(m.position.y) + abs(m.position.z);
  int kinetic = abs(m.velocity.x) + abs(m.velocity.y) + abs(m.velocity.z);
  return potential * kinetic;
}

void
step(struct Moon moons[MOON_COUNT]) {
  struct Point total_accl[MOON_COUNT];
  int total_energy = 0;
  for (int idx = 0; idx < MOON_COUNT; idx++) {
    total_accl[idx].x = total_accl[idx].y = total_accl[idx].z = 0;
  }
  for (int idx = 0; idx < MOON_COUNT; idx++) {
    for (int other_idx = 0; other_idx < MOON_COUNT; other_idx++) {
      if (other_idx == idx)
        continue;
      struct Point accl = calc_accelerate(moons[idx], moons[other_idx]);
      total_accl[idx].x += accl.x;
      total_accl[idx].y += accl.y;
      total_accl[idx].z += accl.z;
    }
  }
  for (int idx = 0; idx < MOON_COUNT; idx++) {
    moons[idx].velocity.x += total_accl[idx].x;
    moons[idx].velocity.y += total_accl[idx].y;
    moons[idx].velocity.z += total_accl[idx].z;
    update_position(&moons[idx]);
    total_energy += calc_energy(moons[idx]);
  }
}

void read_file(char *file_name, struct Moon moons[MOON_COUNT]){
  FILE *fd;
  fd = fopen(file_name, "r");
  if (fd == NULL) {
    printf("File not found\n");
    exit(EXIT_FAILURE);
  }
  char *line = NULL;
  size_t linecapp = 0;
  int idx = 0;
  while (getline(&line, &linecapp, fd) != EOF) {
    struct Point p = parse_line(line);
    struct Point v = {0, 0, 0};
    moons[idx].position = p;
    moons[idx].velocity = v;
    //print_moon(moons[idx]);
    idx++;
  }
  fclose(fd);
}
