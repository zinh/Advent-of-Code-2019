#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main(){
  vector<int> s {1, 2, 3}; 
  do {
    for (auto i : s) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  } while(std::next_permutation(s.begin(), s.end()));
}
