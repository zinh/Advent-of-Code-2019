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
  string output = machine.resume(vector<int>{});
  vector<string> titles;
  boost::algorithm::split(titles, output, [](char x) -> bool { return x == '\n';} );
  for (int i = 0; i < ((titles.size() - 1) / 3); i++) {
    //cout << titles[3 * i + 2] << endl;
    int x = stoi(titles[3 * i]);
    int y = stoi(titles[3 * i + 1]);
    int type = stoi(titles[3 * i + 2]);
    buffer.writeTo(x, y, type);
  }
  cout << buffer.count_cell(4);

  return 0;
}
