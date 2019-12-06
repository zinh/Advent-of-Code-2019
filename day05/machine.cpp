#include "machine.h"

void Cpu::execute() {
  while(true) {
    int opcode = memory[ip];
    int op = opcode % 100;

    switch (op) {
      case 1: // add
      case 2: // multiply
        {
        int op1 = (opcode / 100 % 10) == 0 ?  memory[memory[ip + 1]] : memory[ip + 1];
        int op2 = (opcode / 1000 % 10) == 0 ?  memory[memory[ip + 2]] : memory[ip + 2];
        int op3 = memory[ip + 3];
        if (op == 1)
          add(op1, op2, op3);
        else
          multiply(op1, op2, op3);
        ip += 4;
        break;
        }
      case 3: // input
        {
        int op1 = memory[ip + 1];
        memory[op1] = 1; // TODO: temporary const value
        ip += 2;
        break;
        }
      case 4: // output
        {
        int op1 = memory[ip + 1];
        output(memory[op1]);
        ip += 2;
        break;
        }
      case 99: // exit
        cout << buffer << '\n';
        return;
      default:
        throw runtime_error("Invalid operator");
    }
  }
}

void Cpu::add(int op1, int op2, int result) {
  memory[result] = op1 + op2;
}

void Cpu::multiply(int op1, int op2, int result) {
  memory[result] = op1 * op2;
}

void Cpu::output(int val) {
  buffer.append("\n");
  buffer.append(to_string(val));
}

void Cpu::load_program(string program) {
  vector<string> instructions;
  int i = 0;
  boost::algorithm::split(instructions, program, [](char x) -> bool { return x == ',';} );
  for (auto ins : instructions){
    memory[i++] = stoi(ins);
  }
  cout << "Loaded: " << i << " instructions" << '\n';
}
