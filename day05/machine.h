#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>

using namespace std;
class Cpu {
  int* memory;
  int memory_size;
  string buffer;
  int ip;
  public:
    Cpu(int memory_size) :memory{new int[memory_size]}, memory_size{memory_size} {}

    ~Cpu() {
      delete[] memory;
    }

    void execute(void);
    void run(void);
    void load_program(string);

  private:
    void add(int, int, int);
    void multiply(int, int, int);
    void input(int);
    void output(int);
};
