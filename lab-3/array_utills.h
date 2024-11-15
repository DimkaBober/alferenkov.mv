#ifndef ARRAY_UTILS_H 
#define ARRAY_UTILS_H 

#include <stdlib.h>
#include <stdio.h>

int* inicialize_mas(size_t size);
int add_elem(int **mas, size_t *size, int index, int new_elem);
int del_elem(int **mas, size_t *size, int index);
void print_mas(int *mas, size_t size);
int remove_non_unique(int *arr, size_t *size, int **new_arr, size_t *new_size);

#endif
