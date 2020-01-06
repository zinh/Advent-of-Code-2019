#include "mmu.h"

enum class Direction {
  up, down, left, right
};

struct Pointer {
  int x, y;
  Direction d;
};

class FrameBuffer {
  public:
    FrameBuffer(int initialX, int initialY) {
      pointer = Pointer{.x = initialX, .y = initialX, .d = Direction::up};
    }
    void writeTo(int x, int y, int val);
    void rotate(int angle);
    void writeAndRotate(int val, int angle);
    int currentColor() {return 0;}
    struct Pointer currentPosition() {
      return pointer;
    }
  private:
    mmu<pair<int, int>, int> buffer;
    struct Pointer pointer;
};
