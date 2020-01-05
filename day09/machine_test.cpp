#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestMachine

#include <boost/test/parameterized_test.hpp>
#include <boost/test/unit_test.hpp>
#include "machine.cpp"
#include <string>

struct Fixture {
  Fixture() {
    BOOST_TEST_MESSAGE("setup");
  }
  ~Fixture() {
    BOOST_TEST_MESSAGE("teardown");
  }

  Cpu<long> m;
};

BOOST_FIXTURE_TEST_CASE(test_add_intermediate, Fixture) {
  string program = "1101,1,2,7,4,7,99,0";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 3);
}

BOOST_FIXTURE_TEST_CASE(test_add_positional, Fixture) {
  string program = "1001,8,1,7,4,7,99,0,3";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 4);
}

BOOST_FIXTURE_TEST_CASE(test_add_relative_1, Fixture) {
  string program = "21201,8,1,7,4,7,99,0,3";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 4);
}

BOOST_FIXTURE_TEST_CASE(test_add_relative_2, Fixture) {
  string program = "109,2,2201,7,8,9,4,9,99,3,4,0";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 7);
}

BOOST_FIXTURE_TEST_CASE(test_multiply_intermediate, Fixture) {
  string program = "1102,1,2,7,4,7,99,2";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 2);
}

BOOST_FIXTURE_TEST_CASE(test_multiply_positional, Fixture) {
  string program = "1002,8,2,7,4,7,99,0,9";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 18);
}

BOOST_FIXTURE_TEST_CASE(test_multiply_relative, Fixture) {
  string program = "21002,8,2,7,4,7,99,0,9";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 18);
}

BOOST_FIXTURE_TEST_CASE(test_jump_if_true, Fixture) {
  string program = "1105,1,6,4,9,99,4,10,99,0,1";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 1);
}

BOOST_FIXTURE_TEST_CASE(test_jump_if_true_positional, Fixture) {
  string program = "1005,11,6,4,9,99,4,10,99,0,1,1";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 1);
}

BOOST_FIXTURE_TEST_CASE(test_jump_if_true_relative, Fixture) {
  string program = "109,3,2205,10,11,204,8,99,204,9,99,10,20,1,5";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 10);
}

BOOST_FIXTURE_TEST_CASE(test_jump_if_true_2, Fixture) {
  string program = "1105,0,3,4,9,99,4,10,99,0,1";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 0);
}

BOOST_FIXTURE_TEST_CASE(test_jump_if_true_2_positional, Fixture) {
  string program = "1005,11,3,4,9,99,4,10,99,0,1,0";
  m.load_program(program);
  string output = m.resume(vector<int>{});
  BOOST_TEST(stoi(output) == 0);
}

//void shared_test_case(string program, vector<int> input, int expected) {
//  m.load_program(program);
//  string output = m.resume(input);
//  BOOST_TEST(stoi(output) == expected);
//}

BOOST_AUTO_TEST_CASE(test_long_number) {
  long n = 1125899906842624;
  BOOST_TEST(n == 1125899906842624);
}

//boost::unit_test::test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] ) {
//}
