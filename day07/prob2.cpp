#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <array>
#include "machine.h"

using namespace std;
const int MEMORY_SIZE = 10000;
const int PASS = 5;
vector<vector<int>> permutations(int from ,int to);

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

  //Cpu machine(MEMORY_SIZE);
  //machine.load_program(s);
  //cout << "Halted: " << machine.is_halted() << endl;
  //string output = machine.resume(vector<int>{9, 0});
  //cout << "Output: " << output << endl;
  //cout << "Halted: " << machine.is_halted() << endl;

  int max_output = INT32_MIN;
  vector<vector<int>> perms = permutations(5, 10);
  //vector<vector<int>> perms = { vector<int>{9, 8, 7, 6, 5} };

  for (const auto& initial_inputs : perms) {
    int previous_output = 0;
    string output;
    array<Cpu, PASS> machines = { Cpu(MEMORY_SIZE), Cpu(MEMORY_SIZE), Cpu(MEMORY_SIZE), Cpu(MEMORY_SIZE), Cpu(MEMORY_SIZE) };

    for (int i = 0; i < PASS; i++)
      machines[i].load_program(s);
    // First pass
    for (int i = 0; i < PASS; i++) {
      //cout << "1st pass(input): " << initial_inputs[i] << endl;
      output = machines[i].resume(vector<int>{initial_inputs[i], previous_output});
      //cout << "1st pass(output): " << output << endl;
      try {
        previous_output = stoi(output);
      } catch (const std::invalid_argument& e) {
        cerr << "Invalid output: " << output << endl;
        break;
      } catch (const out_of_range& e) {
        cerr << "Out of range output: " << output << endl;
        break;
      }
    }

    bool halted = false;
    while(!halted) {
      for (auto& machine : machines) {
        output = machine.resume(vector<int>{previous_output});
        try {
          previous_output = stoi(output);
        } catch (const std::invalid_argument& e) {
          cerr << "Invalid output: " << output << endl;
        } catch (const out_of_range& e) {
          cerr << "Out of range output: " << output << endl;
        }
      }

      for (auto& machine : machines) {
        if (!machine.is_halted())
          goto CONT;
      }
      halted = true;
      if (max_output < previous_output)
        max_output = previous_output;
CONT:
      continue;
    }
  }
  cout << "Max output: " << max_output;
}

vector<vector<int>>
permutations(int from ,int to) {
  vector<int> s;
  vector<vector<int>> result;
  for (int i = from; i < to; i++)
    s.push_back(i);
  do {
    vector<int> item;
    for (auto i : s)
      item.push_back(i);
    result.push_back(item);
  } while (next_permutation(s.begin(), s.end()));
  return result;
}
