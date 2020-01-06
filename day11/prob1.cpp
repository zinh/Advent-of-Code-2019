#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string/split.hpp>

#include "machine.cpp"
#include "frame_buffer.cpp"

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
  Cpu<int> machine;
  FrameBuffer buffer = FrameBuffer(0, 0);

  machine.load_program(s);
  int color = 0;
  while(true) {
    string output = machine.resume(vector<int>{color});
    vector<string> instructions;
    boost::algorithm::split(instructions, output, [](char x) -> bool { return x == '\n';} );
    machine.clo();
    int angle = instructions[1] == "0" ? -90 : 90;
    buffer.writeAndRotate(stoi(instructions[0]), angle);
    color = buffer.currentColor();

    if (machine.is_halted())
      break;
  }
  cout << "Stat: " << buffer.stat() << endl;
  return 0;
}
