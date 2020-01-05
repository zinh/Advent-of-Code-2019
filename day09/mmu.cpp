#include "mmu.h"

//template<typename T>
//T& mmu<T>::operator[](int idx) {
//  int k = idx / 100;
//  if (pages.find(k) != pages.end()) {
//    array<T, PAGE_SIZE> page = pages[k];
//    return page[idx % 100];
//  } else { // allocate new page
//    array<T, PAGE_SIZE> a;
//    pages.push_back(a);
//    page_map[k] = pages.size() - 1;
//    return a[idx % 100];
//  }
//}
