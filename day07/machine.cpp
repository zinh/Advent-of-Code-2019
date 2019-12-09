#include "machine.h"

int Cpu::get_operand(int opcode, int op_pos) {
  return (opcode / (int)pow(10, op_pos + 1) % 10) == 0 
    ? memory[memory[ip + op_pos]] 
    : memory[ip + op_pos];
}

void Cpu::start(vector<int> inputs) {
  ip = 0;
  execute(input);
}

void Cpu::resume(vector<int> inputs) {
}

string Cpu::execute(vector<int> inputs) {
  int input_idx = 0;
  while(true) {

    //cout << "IP(" << ip << ')';
    //for (int i = 0; i <= 16; i++)
    //  cout << memory[i] << ' ';
    //cout << '\n';

    int opcode = memory[ip];
    int op = opcode % 100;

    switch (op) {
      case 1: // add
      case 2: // multiply
        {
          int op1 = get_operand(opcode, 1);
          int op2 = get_operand(opcode, 2);
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
          memory[op1] = inputs[input_idx++];
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
      case 5: // jump-if-true
        {
          int op1 = get_operand(opcode, 1);
          int jump_addr = get_operand(opcode, 2);
          jnz(op1, jump_addr);
          break;
        }
      case 6: // jump-if-false
        {
          int op1 = get_operand(opcode, 1);
          int jump_addr = get_operand(opcode, 2);
          jz(op1, jump_addr);
          break;
        }
      case 7: // less-than
        {
          int op1 = get_operand(opcode, 1);
          int op2 = get_operand(opcode, 2);
          if (op1 < op2) {
            memory[memory[ip + 3]] = 1;
          } else {
            memory[memory[ip + 3]] = 0;
          }
          ip += 4;
          break;
        }
      case 8: // equals
        {
          int op1 = get_operand(opcode, 1);
          int op2 = get_operand(opcode, 2);
          if (op1 == op2) {
            memory[memory[ip + 3]] = 1;
          } else {
            memory[memory[ip + 3]] = 0;
          }
          ip += 4;
          break;
        }
      case 99: // exit
        return buffer;
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
  buffer.append(to_string(val));
  //buffer.append("\n");
}

// jump if true
void Cpu::jnz(int op1, int op2) {
  if (op1 != 0) {
    ip = op2;
  } else {
    ip += 3;
  }
}

// jump if alse
void Cpu::jz(int op1, int op2) {
  if (op1 == 0) {
    ip = op2;
  } else {
    ip += 3;
  }
}

void Cpu::load_program(string program) {
  vector<string> instructions;
  int i = 0;
  boost::algorithm::split(instructions, program, [](char x) -> bool { return x == ',';} );
  for (auto ins : instructions){
    memory[i++] = stoi(ins);
  }
  //cout << "Loaded: " << i << " instructions" << '\n';
}

void Cpu::reset(void) {
  ip = 0;
  buffer = "";
}
