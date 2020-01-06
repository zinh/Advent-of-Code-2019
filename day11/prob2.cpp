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
  int color = 1;
  buffer.writeTo(0, 0, 1);
  while(true) {
    string output = machine.resume(vector<int>{color});
    vector<string> instructions;
    boost::algorithm::split(instructions, output, [](char x) -> bool { return x == '\n';} );
    machine.clo();

    int angle;
    switch (stoi(instructions[1])) {
      case 0:
        angle = -90;
        break;
      case 1:
        angle = 90;
        break;
      default:
        throw runtime_error("Undefined color");
    } 

    //cout << "Color: " << instructions[0] << " Angle: " << angle << endl;
    buffer.writeAndRotate(stoi(instructions[0]), angle);
    color = buffer.currentColor();

    if (machine.is_halted())
      break;
  }
  //cout << "Stat: " << buffer.stat() << endl;
  return 0;
}
