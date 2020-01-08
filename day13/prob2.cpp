#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#include <boost/algorithm/string/split.hpp>

#include "machine.cpp"
#include "frame_buffer.cpp"

using namespace std;

void update_buffer(string output, FrameBuffer& buffer) {
  vector<string> titles;
  boost::algorithm::split(titles, output, [](char x) -> bool { return x == '\n';} );
  for (int i = 0; i < ((titles.size() - 1) / 3); i++) {
    int x = stoi(titles[3 * i]);
    int y = stoi(titles[3 * i + 1]);
    if (x == -1 && y == 0) {
      // TODO: print score
      //continue;
    }
    int type = stoi(titles[3 * i + 2]);
    buffer.writeTo(x, y, type);
  }
}

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
  update_buffer(output, buffer);
  buffer.print();

  for (int i = 0; i < 10; i++) {
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    output = machine.resume(vector<int>{0});
    update_buffer(output, buffer);
    buffer.print();
  }
  return 0;
}
