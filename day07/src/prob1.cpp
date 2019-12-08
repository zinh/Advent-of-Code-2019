#include <iostream>
#include <fstream>
#include <string>
#include "machine.h"

using namespace std;

const int MEMORY_SIZE = 10000;

int
main(int argc, char** argv){
  if (argc <= 1) {
    cout << "No file name" << '\n';
    return 1;
  }
  string file_name = argv[1];
  string s;
  Cpu machine(MEMORY_SIZE);

  fstream fs(file_name);
  fs >> s;
  machine.load_program(s);
  return 0;
}
