#include <stdlib.h>

#include "unity.h"
#include "lib.h"

void setUp(void) {}
void tearDown(void) {}

void test_RepeatPattern_1(void) {
  int pattern[3] = {1,3,5};
  int *output = repeat_pattern(pattern, 3, 6);
  int expected[6] = {1,3,5,1,3,5};
  for(int i = 0; i < 6; i++) 
    TEST_ASSERT_EQUAL(output[i], expected[i]);

  free(output);
}

void test_RepeatPattern_2(void) {
  int pattern[4] = {1, 3, 5, 7};
  int *output = repeat_pattern(pattern, 4, 6);
  int expected[6] = {1, 3, 5, 7, 1, 3};
  for(int i = 0; i < 6; i++) 
    TEST_ASSERT_EQUAL(output[i], expected[i]);

  free(output);
}

void test_RepeatPattern_3(void) {
  int pattern[] = {1, 3, 5, 7, 9, 11, 13};
  int *output = repeat_pattern(pattern, 7, 6);
  int expected[6] = {1, 3, 5, 7, 9, 11};
  for(int i = 0; i < 6; i++) 
    TEST_ASSERT_EQUAL(output[i], expected[i]);

  free(output);
}

void test_duplicate_pattern(void) {
  int pattern[4] = {0, 1, 0, -1};
  int *output = duplicate_pattern(pattern, 4, 2);
  int expected[8] = {0, 0, 1, 1, 0, 0, -1, -1};
  for(int i = 0; i < 8; i++)
    TEST_ASSERT_EQUAL(output[i], expected[i]);
  free(output);
}

void test_duplicate_pattern_2(void) {
  int pattern[] = {0, 1, 2};
  int *output = duplicate_pattern(pattern, 3, 3);
  int expected[] = {0,0,0,1,1,1,2,2,2};
  for(int i = 0; i < 9; i++)
    TEST_ASSERT_EQUAL(output[i], expected[i]);
  free(output);
}

void test_duplicate_pattern_3(void) {
  int pattern[] = {0, 1, 2};
  int *output = duplicate_pattern(pattern, 3, 1);
  int expected[] = {0, 1, 2};
  for(int i = 0; i < 3; i++)
    TEST_ASSERT_EQUAL(output[i], expected[i]);
  free(output);
}

void test_calculate_element(void) {
  int input[] = { 1,2,3,4,5,6,7,8 };
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 4, 8, 2, 2, 6, 1, 5, 8 };
  for(int i = 0; i < 8; i++)
    TEST_ASSERT_EQUAL(expected[i], calculate_element(input, 8, pattern, 4, i + 1));
}

void test_calculate_element_1(void) {
  int input[] = { 4,8,2,2,6,1,5,8 };
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 3, 4, 0, 4, 0, 4, 3, 8 };
  for(int i = 0; i < 8; i++)
    TEST_ASSERT_EQUAL(expected[i], calculate_element(input, 8, pattern, 4, i + 1));
}

void test_calculate_element_2(void) {
  int input[] = { 8, 0, 8, 7, 1, 2, 2, 4, 5, 8, 5, 9, 1, 4, 5, 4, 6, 6, 1, 9, 0, 8, 3, 2, 1, 8, 6, 4, 5, 5, 9, 5 };
  int pattern[] = { 0, 1, 0, -1 };
  TEST_ASSERT_EQUAL(2, calculate_element(input, 32, pattern, 4, 1));
  TEST_ASSERT_EQUAL(4, calculate_element(input, 32, pattern, 4, 2));
  TEST_ASSERT_EQUAL(7, calculate_element(input, 32, pattern, 4, 3));
  TEST_ASSERT_EQUAL(0, calculate_element(input, 32, pattern, 4, 4));
}

void test_extend_pattern_1(void) {
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 0, 1, 0, -1 };
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, extend_pattern(pattern, 4, 1, 4), 4);
}

void test_extend_pattern_2(void) {
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 0, 0, 1, 1, 0, 0, -1, -1};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, extend_pattern(pattern, 4, 2, 8), 8);
}

void test_extend_pattern_3(void) {
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 0, 0, 1, 1, 0, 0, -1 };
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, extend_pattern(pattern, 4, 2, 7), 7);
}

void test_extend_pattern_4(void) {
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 0, 0, 1, 1, 0, 0, -1, -1, 0, 0 };
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, extend_pattern(pattern, 4, 2, 10), 10);
}

void test_extend_pattern_5(void) {
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, extend_pattern(pattern, 4, 8, 10), 10);
}

void test_extend_pattern_6(void) {
  int pattern[] = { 0, 1, 0, -1 };
  int expected[] = { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 };
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, extend_pattern(pattern, 4, 8, 20), 20);
}

void test_caculate_phase_1(void) {
  int input[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 4, 8, 2, 2, 6, 1, 5, 8 };
  int *output = calculate_phase(input, 8, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 8);
  free(output);
}

void test_caculate_phase_2(void) {
  int input[] = { 4, 8, 2, 2, 6, 1, 5, 8 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 3, 4, 0, 4, 0, 4, 3, 8 };
  int *output = calculate_phase(input, 8, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 8);
  free(output);
}

void test_caculate_phase_3(void) {
  int input[] = { 3, 4, 0, 4, 0, 4, 3, 8 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 0, 3, 4, 1, 5, 5, 1, 8 };
  int *output = calculate_phase(input, 8, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 8);
  free(output);
}

void test_caculate_phase_4(void) {
  int input[] = { 0, 3, 4, 1, 5, 5, 1, 8 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 0, 1, 0, 2, 9, 4, 9, 8 };
  int *output = calculate_phase(input, 8, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 8);
  free(output);
}

void test_caculate_phase_5(void) {
  int input[] = { 8,0,8,7,1,2,2,4,5,8,5,9,1,4,5,4,6,6,1,9,0,8,3,2,1,8,6,4,5,5,9,5 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 2,4,7,0,6,8,6,1,3,0,0,6,0,3,8,7,8,2,6,5,6,6,8,5,3,2,4,8,4,9,4,5 };
  int *output = calculate_phase(input, 32, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 32);
  free(output);
}

void test_caculate_phase_6(void) {
  int input[] = { 2,4,7,0,6,8,6,1,3,0,0,6,0,3,8,7,8,2,6,5,6,6,8,5,3,2,4,8,4,9,4,5 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 1,7,9,3,4,3,8,8,1,2,1,5,7,3,2,7,5,7,5,9,4,8,2,4,9,6,4,0,2,8,9,5 };
  int *output = calculate_phase(input, 32, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 32);
  free(output);
}

void test_caculate_phase_7(void) {
  int input[] = { 3,6,2,5,7,0,9,1,9,4,7,2,6,3,6,3,5,0,7,4,7,5,1,1,3,2,2,4,0,6,4,5,0 };
  int pattern[] = { 0, 1, 0, -1};
  int expected[] = { 2,4,1,7,6,1,7,6,4,8,0,9,1,9,0,4,6,1,1,4,0,3,8,7,6,3,1,9,5,5,9,5 };
  int *output = calculate_phase(input, 32, pattern, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, output, 32);
  free(output);
}

void test_duplicate_array(void) {
  int input[] = { 1, 2 };
  int output[] = { 1, 2, 1, 2 };
  TEST_ASSERT_EQUAL_INT_ARRAY(output, duplicate_array(input, 2, 2), 4);
}

void test_duplicate_array_1(void) {
  int input[] = { 1, 2 };
  int output[] = { 1, 2 };
  TEST_ASSERT_EQUAL_INT_ARRAY(output, duplicate_array(input, 2, 1), 2);
}

void test_duplicate_array_2(void) {
  int input[] = { 1, 2 };
  int output[] = { 1, 2, 1, 2, 1, 2 };
  TEST_ASSERT_EQUAL_INT_ARRAY(output, duplicate_array(input, 2, 3), 6);
}

