#include "frame_buffer.h"
#include <iostream>
#include <fstream>

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

void FrameBuffer::print(string filename) {
  ofstream ofs(filename, ios::out);
  int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
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
  ofs << "P1" << endl;
  ofs << max_x - min_x  + 1 << " " << max_y - min_y + 1 << endl;

  for (int y = max_y; y >= min_y; y--) {
    for(int x = min_x; x <= max_x; x++) {
      int color = buffer[pair<int, int>(x, y)];
      if (color == 1)
        ofs << "0" << " ";
      else
        ofs << "1" << " ";
    }
    ofs << endl;
  }
}
