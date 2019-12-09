#include <iostream>
#include <algorithm>
#include <array>

int
main(){
  std::array<int, 3> s = { 1, 2, 3 };
  do {
    for (auto i : s) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  } while(std::next_permutation(s.begin(), s.end()));
}
