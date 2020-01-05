#include <iostream>
#include <fstream>
#include <string>
#include "machine.h"

using namespace std;

int
main(int argc, char** argv){
if (argc <= 1) {
    cout << "No file name" << '\n';
    return 1;
  }
  string file_name = argv[1];
  string s;

  fstream fs(file_name);
  fs >> s;
  Cpu machine;
  machine.load_program(s);
  string output = machine.resume(vector<int>{});
  cout << output;
  return 0;
}
