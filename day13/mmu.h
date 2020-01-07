#ifndef MMU_H__
#define MMU_H__

#include <unordered_map>
#include <functional>

using namespace std;

template<typename K, typename V, typename Hasher = hash<K>>
class mmu {
  private:
    typedef unordered_map<K, V, Hasher> PageList;
    PageList pages;
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
    typedef typename PageList::iterator iterator;
    typedef typename PageList::const_iterator const_iterator;

    iterator begin() { return pages.begin(); }
    iterator end() { return pages.end(); }
};

#endif
