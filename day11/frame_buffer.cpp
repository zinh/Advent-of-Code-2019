#include "frame_buffer.h"
#include <iostream>

void FrameBuffer::writeAndRotate(int val, int angle) {
  writeTo(pointer.x, pointer.y, val);
  rotate(angle);
  forward(1);
}

void FrameBuffer::writeTo(int x, int y, int val) {
  buffer[pair<int, int>(x, y)] = val;
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
  //cout << "Forward " << step << endl;
  //cout << "Current direction" << pointer.d << endl;
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
