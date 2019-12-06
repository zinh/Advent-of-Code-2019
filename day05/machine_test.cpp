#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(no_matches){
}

int
add(int a, int b) {
  return a + b;
}

BOOST_AUTO_TEST_CASE(my_test) {
  BOOST_TEST(add(1,1) == 3);
}
