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

const pair<int, int>& next_position(const Pointer& p, const FrameBuffer& buffer) {
  switch (currentPosition.d) {
    case Direction::up: 
      {
        buffer[pair<int, int>(p.x, p.y + 1)]
        buffer[pair<int, int>(p.x + 1, p.y)]
        break;
      }
    case Direction::down:
      {
        buffer[pair<int, int>(p.x, p.y - 1)]
        buffer[pair<int, int>(p.x - 1, p.y)]
        break;
      }
  }
}

void
sleep(int milisec){
  this_thread::sleep_for(std::chrono::milliseconds(milisec));
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

  cout << "\033[2J\033[1;1H"; // clear screen
  machine.load_program(s);
  string output = machine.resume(vector<int>{});
  update_buffer(output, buffer);
  buffer.print();

  for (int i = 0; i < 10; i++) {
    sleep(1000);
    output = machine.resume(vector<int>{0});
    update_buffer(output, buffer);
    buffer.print();
  }
  return 0;
}
