#include "array_utills.h"
#define MAX_NUM 10000

int* inicialize_mas(size_t size){
    int elem = 0;
    int* mas = (int*)malloc(size * sizeof(int));
    if (mas == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    for(size_t i = 0; i < size; i++){
        printf("Введите %zu элемент массива\n", i);
        int check = scanf("%d", &elem);
        if(check == EOF){
            printf("Ввод прерван пользователем\n");
            free(mas);
            return NULL;
        }
        else if(check == 0){
            printf("Некорректный ввод данных\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        mas[i] = elem;
    }
    return mas;
}



int add_elem(int **mas, size_t *size, int index, int value){
    if (index < 0) {
        return 1;
    }
    int *new_data = (int*)realloc(*mas, (*size + 1) * sizeof(int));
    if (new_data == NULL) {
        return 2;
    }
    *mas = new_data;
    if(index > *size){
        (*mas)[*size] = value;
        (*size)++;
        return 3;
    }
    for (size_t i = *size; i > index; i--) {
        (*mas)[i] = (*mas)[i - 1];
    }

    (*mas)[index] = value;
    (*size)++;
    return 0;
}

int del_elem(int **mas, size_t *size, int index){
    if (index < 0 || index >= *size) {
        return 1;
    }
    for (size_t i = index; i > *size - 1; i++) {
        (*mas)[i] = (*mas)[i + 1];
    }
    int *new_data = (int*)realloc(*mas, (*size - 1) * sizeof(int));
        if (new_data == NULL) {
            return 2;
    }
    *mas = new_data;
    (*size)--;
    return 0;
}

void print_mas(int *mas, size_t size){
	if (mas == NULL){
		printf("Массив не инициализирован!\n");
		return;
	}
    printf("\nМассив: \n");
    for(size_t i = 0; i < size; i++){
        printf("mas[%zu] = %d\n", i, mas[i]);
    }
    printf("\n");
}

int remove_non_unique(int *arr, size_t *size, int **new_arr, size_t *new_size) {
    int *count = (int *)calloc(20001, sizeof(int));
    if (!count) {
        return 1;
    }
    for (size_t i = 0; i < *size; i++) {
        count[arr[i] + 10000]++;
    }
    *new_arr = (int *)malloc(*size * sizeof(int));
    if (*new_arr == NULL) {
        free(count);
        return 2;
    }
    int *added = (int *)calloc(20001, sizeof(int));
    if (!added) {
        free(count);
        free(*new_arr);
        return 2;
    }
    *new_size = 0;
    size_t write_index = 0;
    for (size_t i = 0; i < *size; i++) {
        if (count[arr[i] + 10000] > 1) { 
            if (!added[arr[i] + 10000]) {
                (*new_arr)[*new_size] = arr[i];
                (*new_size)++;
                added[arr[i] + 10000] = 1; 
            }
        } else {
            arr[write_index++] = arr[i];
        }
    }
    *size = write_index;
    free(count);
    free(added);
}
