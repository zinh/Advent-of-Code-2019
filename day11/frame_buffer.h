#include <utility>
#include <set>

#include <boost/functional/hash.hpp>
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
    int colorOf(int x, int y) {
      return buffer[pair<int, int>(x, y)];
    }

    int currentColor() {
      return buffer[pair<int, int>(pointer.x, pointer.y)];
    }

    struct Pointer currentPosition() {
      return pointer;
    }

    int stat(void) {
      return buffer.stat();
    }

    void print(string filename);
  private:
    typedef pair<int, int> p;
    mmu<p, int, boost::hash<p>> buffer;
    set<pair<int, int>> painted_cells;
    struct Pointer pointer;
};
