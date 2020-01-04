#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestMachine
#include <boost/test/unit_test.hpp>
#include "machine.h"
#include <string>

class MiniCpu {
  public:
    int run() {
      int& a = get_memory(1);
      a = 10;
      return get_memory(1);
    }
    
  private:
    mmu<int> memory;
    int& get_memory(int idx) {
      return memory[idx];
    }
};

BOOST_AUTO_TEST_CASE(test_add_intermediate) {
  Cpu m;
  string program = "1101,1,2,7,4,7,99,0";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 3);
}

BOOST_AUTO_TEST_CASE(test_add_positional) {
  Cpu m;
  string program = "1001,8,1,7,4,7,99,0,3";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 4);
}

BOOST_AUTO_TEST_CASE(test_add_relative_1) {
  Cpu m;
  string program = "21201,8,1,7,4,7,99,0,3";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 4);
}

BOOST_AUTO_TEST_CASE(test_add_relative_2) {
  Cpu m;
  string program = "109,2,2201,7,8,9,4,9,99,3,4,0";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 7);
}

BOOST_AUTO_TEST_CASE(test_multiply_intermediate) {
  Cpu m;
  string program = "1102,1,2,7,4,7,99,2";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 2);
}

BOOST_AUTO_TEST_CASE(test_multiply_positional) {
  Cpu m;
  string program = "1002,8,2,7,4,7,99,0,9";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 18);
}

BOOST_AUTO_TEST_CASE(test_multiply_relative) {
  Cpu m;
  string program = "21002,8,2,7,4,7,99,0,9";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 18);
}
