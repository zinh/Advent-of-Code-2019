#include <iostream>
#include <string>
#include <unordered_map>
#include "moon.h"

extern "C" {
  void read_file(char *file_name, struct Moon moons[MOON_COUNT]);
  void step(struct Moon moons[]);
  void print_moon(struct Moon m);
};

using namespace std;

string point_to_string(struct Point p) {
  return to_string(p.x) + to_string(p.y) + to_string(p.z);
}

string moons_to_key(struct Moon moons[MOON_COUNT]) {
  string r = "";
  for (int i = 0; i < MOON_COUNT; i++)
    r += point_to_string(moons[i].position);
  return r;
}

int
main(int argc, char **argv){
  struct Moon moons[MOON_COUNT];
  unordered_map<string, bool> h;
  read_file(argv[1], moons);
  int step_count = 1;
  for (int i = 0; i < MOON_COUNT; i++)
    print_moon(moons[i]);
  while(true) {
    step(moons);
    string k = moons_to_key(moons);
    if (h.find(k) == h.end())
      h[k] = true;
    else
      break;
    step_count++;
    //if (step_count % 100000 == 0)
    //  cout << step_count << '\n';
  }
  cout << "Step = " << step_count;
  return 0;
}
