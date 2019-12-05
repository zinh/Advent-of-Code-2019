#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>

using namespace std;

int
main(){
  vector<string> v;
  string s =  "hello,world,how";
  boost::algorithm::split(v, s, [](char c) -> bool {return c == ','; });
  for (auto s : v)
    cout << s << '\n';
  return 0;
}
