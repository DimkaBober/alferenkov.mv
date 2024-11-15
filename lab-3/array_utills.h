#ifndef ARRAY_UTILS_H 
#define ARRAY_UTILS_H 

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int* inicialize_mas(int size);
int add_elem(int **mas, int *size, int index, int new_elem);
int del_elem(int **mas, int *size, int index);
void print_mas(int *mas, int size);
int remove_non_unique(int **arr, int *size, int **new_arr, int *new_size);
int input(int *input_char);
int completion_mas(int *mas, int size);

#endif

