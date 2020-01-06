#include <map>

using namespace std;

template<typename K, typename V>
class mmu {
  public:
    V& operator[](K idx) {
      if (pages.find(idx) == pages.end()) {
        pages[idx] = 0;
      } 
      return pages[idx];
    };
  private:
    map<K, V> pages;
};
