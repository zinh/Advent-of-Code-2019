#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <boost/algorithm/string/split.hpp>
#include "mmu.h"

using namespace std;
class Cpu {
  public:
    Cpu() : ip{0}, 
      halted{false},
      ds{0} {}

    ~Cpu() {
    }

    bool is_halted(void) { return halted; }

    string execute(vector<int>);
    void run(void);
    void load_program(string);
    void reset(void);
    string start(vector<int>);
    string resume(vector<int>);

  private:
    mmu<int> memory;
    int memory_size;
    string buffer;
    int ip;
    bool halted;
    int ds; // data segment register

    void add(int, int, int);
    void multiply(int, int, int);
    void input(int);
    void output(int);
    int& get_operand(int, int);
    void jnz(int, int);
    void jz(int, int);
};

