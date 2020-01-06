#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestFrameBuffer
#include <boost/test/unit_test.hpp>
#include "frame_buffer.h"

BOOST_TEST_DONT_PRINT_LOG_VALUE( Direction )

BOOST_AUTO_TEST_CASE(test_constructor) {
  FrameBuffer frm = FrameBuffer(1, 1);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.x == 1);
  BOOST_TEST(p.y == 1);
  BOOST_TEST(frm.currentColor() == 0);
  BOOST_TEST(p.d == Direction::up);
}

BOOST_AUTO_TEST_CASE(test_writeTo) {
  FrameBuffer frm = FrameBuffer(0, 0);
  frm.writeTo(0, 0, 1);
  BOOST_TEST(frm.currentColor() == 1);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_1) {
  FrameBuffer frm = FrameBuffer(0, 0);
  frm.writeAndRotate(1, 90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::right);
  BOOST_TEST(p.x == 1);
  BOOST_TEST(p.y == 0);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_2) {
  FrameBuffer frm = FrameBuffer(0, 0);
  frm.writeAndRotate(1, -90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::left);
  BOOST_TEST(p.x == -1);
  BOOST_TEST(p.y == 0);
}


BOOST_AUTO_TEST_CASE(test_writeAndRotate_3) {
  FrameBuffer frm = FrameBuffer(0, 0, Direction::down);
  frm.writeAndRotate(1, 90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::left);
  BOOST_TEST(p.x == -1);
  BOOST_TEST(p.y == 0);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_4) {
  FrameBuffer frm = FrameBuffer(0, 0, Direction::down);
  frm.writeAndRotate(1, -90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::right);
  BOOST_TEST(p.x == 1);
  BOOST_TEST(p.y == 0);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_5) {
  FrameBuffer frm = FrameBuffer(0, 0, Direction::left);
  frm.writeAndRotate(1, 90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::up);
  BOOST_TEST(p.x == 0);
  BOOST_TEST(p.y == 1);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_6) {
  FrameBuffer frm = FrameBuffer(0, 0, Direction::left);
  frm.writeAndRotate(1, -90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::down);
  BOOST_TEST(p.x == 0);
  BOOST_TEST(p.y == -1);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_7) {
  FrameBuffer frm = FrameBuffer(0, 0, Direction::right);
  frm.writeAndRotate(1, 90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::down);
  BOOST_TEST(p.x == 0);
  BOOST_TEST(p.y == -1);
}

BOOST_AUTO_TEST_CASE(test_writeAndRotate_8) {
  FrameBuffer frm = FrameBuffer(0, 0, Direction::right);
  frm.writeAndRotate(1, -90);
  Pointer p = frm.currentPosition();
  BOOST_TEST(p.d == Direction::up);
  BOOST_TEST(p.x == 0);
  BOOST_TEST(p.y == 1);
}
