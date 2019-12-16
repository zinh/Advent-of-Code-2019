#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "moon.h"

extern "C" {
  void read_file(char *file_name, struct Moon moons[MOON_COUNT]);
  void step(struct Moon moons[]);
  void print_moon(struct Moon m);
};

using namespace std;

string 
point_to_string(struct Point p) {
  return to_string(p.x) + "," + to_string(p.y) + "," + to_string(p.z);
}

string 
moons_to_key(struct Moon moons[MOON_COUNT]) {
  string r = "";
  for (int i = 0; i < MOON_COUNT; i++) {
    r += point_to_string(moons[i].position);
    r += ",";
  }
  return r;
}

string
point_to_string2(char k, struct Point m) {
  switch(k) {
    case 'x':
      return to_string(m.x);
    case 'y':
      return to_string(m.y);
    case 'z':
      return to_string(m.z);
    default:
      throw runtime_error("Unknow key");
  }
}

string 
moons_to_key2(char k, struct Moon moons[MOON_COUNT]) {
  string r = "";
  for (int i = 0; i < MOON_COUNT; i++) {
    r += point_to_string2(k, moons[i].position);
    r += ",";
    r += point_to_string2(k, moons[i].velocity);
    r += ",";
  }
  return r;
}

void
print_moons(struct Moon moons[MOON_COUNT]) {
  for (int i = 0; i < MOON_COUNT; i++)
    print_moon(moons[i]);
}

int
main(int argc, char **argv) {
  struct Moon moons[MOON_COUNT];
  read_file(argv[1], moons);
  int dimensions[DIMENSION];
  int dim = 0;
  for (auto dimension : "xyz") {
    if (dimension == '\0')
      break;
    int step_count = 0;
    unordered_map<string, bool> h;
    while (true) {
      step(moons);
      string k = moons_to_key2(dimension, moons);
      if (h.find(k) == h.end())
        h[k] = true;
      else 
        break;
      step_count++;
    }
    dimensions[dim] = step_count;
    dim++;
  }
  for (auto i : dimensions) {
    cout << i << endl;
  }
  return 0;
}
