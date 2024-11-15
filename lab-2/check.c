
#include <stdio.h>
#include <math.h>

int check_par(long double *x){
	printf("Введите x: ");
	int rez = scanf("%Lf", &*x);
	if(rez == EOF){
		return 3;
	}
	else if(rez == 0){
	    while (getchar() != '\n');
		return 1;
	}
	else if(fabsl(*x) < 1){
		return 0;
	}
	return 2;
}

int check_e(long double *e){
	printf("Введите e: ");
	int rez = scanf("%Lf", &*e);
	if(rez == EOF){
		return 3;
	}
	else if(rez == 0){
	    while (getchar() != '\n');
		return 1;
	}
	else if(*e > 0){
		return 0;
	}
	return 2;
}

int check_n(int *n){
	printf("Введите n: ");
	int rez = scanf("%d", &*n);
	if(rez == EOF){
		return 3;
	}
	else if(rez == 0){
	    while (getchar() != '\n');
		return 1;
	}
	else if(*n > 0){
		return 0;
	}
	return 2;
}
