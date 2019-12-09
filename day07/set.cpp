#include <vector>
#include <initializer_list>

using namespace std;

template<typename T>
class Set {
  vector<T> members;
  public:
    Set(initializer_list<T> lst) {
      for (auto t : lst)
        members.push_back(t);
    }
};
