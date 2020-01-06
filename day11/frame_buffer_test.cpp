#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestFrameBuffer
#include <boost/test/unit_test.hpp>
#include "frame_buffer.h"

BOOST_AUTO_TEST_CASE(test_constructor) {
  FrameBuffer frm = FrameBuffer(0, 0);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.x == 0);
  BOOST_TEST(p.y == 0);
  //BOOST_TEST(p.d == Direction::up);
  //BOOST_TEST(true);
}
