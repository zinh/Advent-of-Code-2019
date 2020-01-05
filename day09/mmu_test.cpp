#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestMMU
#include <boost/test/unit_test.hpp>
#include "mmu.h"

BOOST_AUTO_TEST_CASE(first_test)
{
  mmu<int> a;
  a[0] = 10;
  a[10] = 20;
  BOOST_TEST(a[0] == 10);
  BOOST_TEST(a[10] == 20);
  BOOST_TEST(a[1000] == 0);
  BOOST_TEST(a[100000] == 0);
}
