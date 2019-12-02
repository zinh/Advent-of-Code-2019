#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

vector<int> get_numbers(string file_name);
vector<int> next_fuels(const vector<int>& v, int &result);

int
main(int argc, char** argv){
  if (argc <= 1) {
    cout << "Invalid parameters\n";
    exit(1);
  }
  
  int result = 0;
  vector<int> v = get_numbers(argv[1]);
  
  while (v.size() > 0) {
    v = next_fuels(v, result);
  }
  cout << result << '\n';
  return 0;
}

vector<int> get_numbers(string file_name) {
  ifstream fs(file_name);
  string line;
  vector<int> v;
  
  if (fs.is_open()){
    while (getline(fs, line))
      v.push_back(stoi(line));
    fs.close();
  } else {
    throw runtime_error("Error open file");
  }
  return v;
}

vector<int> next_fuels(const vector<int>& v, int& result) {
  vector<int> fuels;
  for (auto f : v){
      int next_value = f / 3 - 2;
      if (next_value > 0){
	fuels.push_back(next_value);
	result += next_value;
      }
  }
  return fuels;
}
