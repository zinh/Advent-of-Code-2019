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

    void execute(int, vector<int>);
    void load_program(string);

  private:
    void add(int, int, int);
    void multiply(int, int, int);
    void input(int);
    void output(int);
};

void Cpu::execute(int opcode, vector<int> args) {
  int op = opcode % 100;
  switch (op) {
    case 1: // add
      break;
    case 2: // multiply
      break;
    case 3: // input
      break;
    case 4: // output
      break;
    case 99: // exit
      break;
    default:
      throw runtime_error("Invalid operator");
  }
}

void Cpu::add(int op1, int op2, int result) {
  memory[result] = op1 + op2;
}

void Cpu::multiply(int op1, int op2, int result) {
  memory[result] = op1 * op2;
}

void Cpu::output(int val) {
  buffer.append(to_string(val));
}

void Cpu::load_program(string program) {
  vector<string> instructions;
  int i = 0;
  boost::algorithm::split(instructions, program, [](char x) -> bool { return x == ',';} );
  for (auto ins : instructions){
    memory[i++] = stoi(ins);
  }
}
