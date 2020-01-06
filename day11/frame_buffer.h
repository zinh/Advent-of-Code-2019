#include <utility>
#include "mmu.h"

using namespace std;

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

    FrameBuffer(int initialX, int initialY, Direction d) {
      pointer = Pointer{.x = initialX, .y = initialX, .d = d};
    }

    void writeTo(int x, int y, int val);
    void rotate(int angle);
    void forward(int step);
    void writeAndRotate(int val, int angle);
    int currentColor() {
      return buffer[pair<int, int>(pointer.x, pointer.y)];
    }
    struct Pointer currentPosition() {
      return pointer;
    }

    int stat(void) {
      return buffer.stat();
    }
  private:
    mmu<pair<int, int>, int> buffer;
    struct Pointer pointer;
};
