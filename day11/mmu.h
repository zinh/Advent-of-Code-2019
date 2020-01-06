#ifndef MMU_H__
#define MMU_H__

#include <unordered_map>
#include <functional>

using namespace std;

template<typename K, typename V, typename Hasher = hash<K>>
class mmu {
  public:
    V& operator[](K idx) {
      if (pages.find(idx) == pages.end()) {
        pages[idx] = 0;
      } 
      return pages[idx];
    };
    int stat(void) {
      return pages.size();
    }
  private:
    unordered_map<K, V, Hasher> pages;
};

#endif
