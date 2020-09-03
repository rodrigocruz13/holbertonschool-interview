#ifndef _MULTI_H_
#define _MULTI_H_

#define _TRUE_ 1
#define _FALSE_ 0
#define MAX1 1000
#define MAX2 2000

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void multiply(char *num_1, char *num_2);
void *create_array(int rows, int cols);
int is_a_number(char *a_str);
void sum_and_print(char answer[MAX1][MAX2], int len_1, int len_2);

#endif /*_MULTI_H_*/