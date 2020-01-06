#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <boost/algorithm/string/split.hpp>
#include "mmu.h"

using namespace std;
template<typename T>
class Cpu {
  public:
    Cpu() : ip{0}, 
      halted{false},
      ds{0} {}

    ~Cpu() {
    }

    bool is_halted(void) { return halted; }

    string execute(vector<int> input);
    void run(void);
    void load_program(string);
    void reset(void);
    string start(vector<int> input);
    string resume(vector<int> input);

  private:
    mmu<int, T> memory;
    int memory_size;
    string buffer;
    int ip;
    bool halted;
    int ds; // data segment register

    void add(T, T, T);
    void multiply(T, T, T);
    void input(int);
    void output(T);
    T& get_operand(int, int);
    void jnz(T, T);
    void jz(T, T);
};

