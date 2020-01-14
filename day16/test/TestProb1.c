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
