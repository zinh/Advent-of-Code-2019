#include <iostream>
#include <fstream>
#include <string>
#include "machine.h"

#define PASS 5
using namespace std;

const int MEMORY_SIZE = 10000;
vector<vector<int>> permutations(int from ,int to, int depth);

int
main(int argc, char** argv){
  if (argc <= 1) {
    cout << "No file name" << '\n';
    return 1;
  }
  string file_name = argv[1];
  string s;

  fstream fs(file_name);
  fs >> s;

  vector<vector<int>> perms = permutations(0, 5, PASS);
  // cout << perms.size() << '\n';
  //for (auto p : perms) {
  //  for (auto i : p) 
  //    cout << i;
  //  cout << '\n';
  //}
    
  //cout << perms.size();

  int max_output = INT32_MIN;

  for (auto inputs : perms) {
    int previous_output = 0;
    string output;

    cout << "Input: ";
    for (auto i : inputs)
      cout << i << ' ';
    for (int pass = 0; pass < PASS; pass++){
      Cpu machine(MEMORY_SIZE);
      machine.load_program(s);
      output = machine.execute(vector<int>{inputs[pass], previous_output});
      try {
        previous_output = stoi(output);
      } catch (const std::invalid_argument& e) {
        //cout << "Invalid output" << '\n';
        break;
      }
    }
    cout << "Output: " << output << '\n';
    if (output.size() > 0)
      if (max_output < previous_output)
        max_output = previous_output;
  }
  cout << "Result: " << max_output << '\n';

  return 0;
}

vector<int> copy_vector(vector<int> src) {
  vector<int> v;
  for (auto i : src)
    v.push_back(i);
  return v;
}

vector<vector<int>> combinations(int from ,int to, int depth) {
  vector<vector<int>> result;
  for (int i = from; i < to; i++){
    result.push_back(vector<int>{i});
  }

  for (int i = 1; i < depth; i++) {
    int total = result.size();
    for (int idx = 0; idx < total; idx++){
      vector<int> member = result[idx];
      for (int j = from + 1; j < to; j++) {
        vector<int> v = copy_vector(member);
        v.push_back(j);
        result.push_back(v);
      }
      member.push_back(from);
      result[idx] = member;
    }
  }
  return result;
}
