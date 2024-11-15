#include "array_utills.h"


int input(int *input_char){
	int check = 0;
	int n = 0;
	check = scanf("%d", &n);
	if (check == EOF) {
		clearerr(stdin);
		return 3;
	}
	else if (check == 0) {
		while (getchar() != '\n');
		return 1;
	}
	*input_char = n;
	return 0;
}

int completion_mas(int *mas, int size){
	int elem, check;
	for (int i = 0; i < size; i++){
		printf("Введите %d элемент массива\n", i);
		check = input(&elem);
	    if(check == 3){
	    	printf("Ввод прерван пользователем\n");
	   		return 3;
	   	}
	    if (check == 1){
	        printf("Некорректный ввод данных\n");
	        i--;
	    }
	    mas[i] = elem;
	}
	return 0;
}
int* inicialize_mas(int size){
    int* mas = (int*)calloc(size, sizeof(int));
    if (mas == NULL) {
        return NULL;
    }
    return mas;
}



int add_elem(int **mas, int *size, int index, int value){
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
    }
    else {
	    for (int i = *size; i > index; i--) {
	        (*mas)[i] = (*mas)[i - 1];
	    }
	    (*mas)[index] = value;
	}
    (*size)++;
    return 0;
}

int del_elem(int **mas, int *size, int index){
    if (index < 0 || index >= *size) {
        return 1;
    }
    for (int i = index; i < *size; i++) {
        (*mas)[i] = (*mas)[i + 1];
    }
    int *new_data = (int*)realloc(*mas, (*size - 1) * sizeof(int));
    if (new_data != NULL) {
    	*mas = new_data;
    }
    else if (*size > 1){
    	return 2;
    }
    (*size)--;
    return 0;
}


void print_mas(int *mas, int size){
	if (mas == NULL){
		printf("Массив не инициализирован!\n");
		return;
	}
    printf("\nМассив: \n");
    for(int i = 0; i < size; i++){
        printf("mas[%d] = %d\n", i, mas[i]);
    }
    printf("\n");
}

int remove_non_unique(int **arr, int *size, int **new_arr, int *new_size) {
	int count = 0;
	for(int i = 0; i < *size; ){
		count = 0;
		for(int j = 0; j < *size; j++){
			if((*arr)[i] == (*arr)[j]){
				count++;
			}
		}
		if (count > 1){
			add_elem(&*new_arr, &*new_size, *new_size, (*arr)[i]);
			for(int k = i + 1; k < *size; k++) {
				if ((*arr)[i] == (*arr)[k]){
					del_elem(&*arr, &*size, k);
					k--;
				}
			}
			del_elem(&*arr, &*size, i);
		}
		else{
			i++;			
		}
	}
	return 0;
}
