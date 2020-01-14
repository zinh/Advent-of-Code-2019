#ifndef LIB_H__
#define LIB_H__

int read_file(char *file_name, int **result);
int* repeat_pattern(int pattern[], int pattern_size, int size);
int* duplicate_pattern(int *pattern, int pattern_size, int repeat_count);
int calculate_element(int input[], int input_size, int pattern[], int pattern_size, int element_position);
void print_phase(int *, int);
int *calculate_phase(int *numbers, int size, int *pattern, int pattern_size);

#endif
