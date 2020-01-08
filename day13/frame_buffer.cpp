#include "frame_buffer.h"
#include <iostream>
#include <fstream>
//#include <cstdio>

void FrameBuffer::writeAndRotate(int val, int angle) {
  writeTo(pointer.x, pointer.y, val);
  rotate(angle);
  forward(1);
}

void FrameBuffer::writeTo(int x, int y, int val) {
  int color = buffer[pair<int, int>(x, y)];
  if (color != val) {
    buffer[pair<int, int>(x, y)] = val;
    //painted_cells.insert(pair<int, int>(x, y));
  }
}

// TODO: temporary angle = {90, -90}
void FrameBuffer::rotate(int angle) {
  if (angle == 90) {
    switch (pointer.d) {
      case Direction::up:
        pointer.d = Direction::right;
        break;
      case Direction::down:
        pointer.d = Direction::left;
        break;
      case Direction::right:
        pointer.d = Direction::down;
        break;
      case Direction::left:
        pointer.d = Direction::up;
        break;
    }
  } else if (angle == -90) {
    switch (pointer.d) {
      case Direction::up:
        pointer.d = Direction::left;
        break;
      case Direction::down:
        pointer.d = Direction::right;
        break;
      case Direction::right:
        pointer.d = Direction::up;
        break;
      case Direction::left:
        pointer.d = Direction::down;
        break;
    }
  }
}

void FrameBuffer::forward(int step) {
  switch (pointer.d) {
    case Direction::up:
      pointer.y += step;
      break;
    case Direction::down:
      pointer.y -= step;
      break;
    case Direction::left:
      pointer.x -= step;
      break;
    case Direction::right:
      pointer.x += step;
      break;
  }
}

void FrameBuffer::print() {
  int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
  cout << "\033[0;0H"; // \033[x;yH -> move cursor to row y, col x
  for (const auto& item : buffer) {
    pair<int, int> position = item.first;
    int x = position.first;
    int y = position.second;
    int color = item.second;
    if (x < min_x)
      min_x = x;
    if (x > max_x)
      max_x = x;
    if (y < min_y)
      min_y = y;
    if (y > max_y)
      max_y = y;
  }

  for (int y = max_y; y >= min_y; y--) {
    for(int x = min_x + 1; x <= max_x; x++) {
      int color = buffer[pair<int, int>(x, y)];
      switch (color) {
        case 0: // empty
          cout << "·";
          break;
        case 1: // wall
          cout << "█";
          break;
        case 2: // block
          cout << "▒";
          break;
        case 3:
          cout << "─";
          break;
        case 4:
          cout << "O";
          break;
      }
    }
    cout << "\n";
  }
}

const pair<int, int>& FrameBuffer::get_point_by_type(int type) {
  for (auto& item : buffer) {
    if (item.second == type)
      return item.first;
  }
  return pair<int, int>{-1, -1};
}
