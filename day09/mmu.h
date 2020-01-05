#include <map>

using namespace std;

template<typename T>
class mmu {
  public:
    T& operator[](int idx) {
      if (pages.find(idx) == pages.end()) {
        pages[idx] = 0;
      } 
      return pages[idx];
    };
  private:
    map<int, T> pages;
};
