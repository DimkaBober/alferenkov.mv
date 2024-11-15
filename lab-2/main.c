#include <stdio.h>
#include "schet.h"
#include "check.h"
#include <math.h>

int prog1(){
    long double x;
    long double e;
    int rez;
    while(1){
    	rez = check_par(&x);
		if(rez == 0){
			break;
		}
    	if(rez == 1){
    		printf("Некорректный ввод x\n");
    	}
    	else if(rez == 2){
    	    printf("Х не лежит в допустимом диапазоне\n");		
    	}
		else if(rez == 3){
		    printf("Ввод завершен (Ctrl + D)\n");
		    return 0;
		}    	    	
    }
    while(1){
        rez = check_e(&e);
    	if(rez == 0){
    		break;
    	}
        if(rez == 1){
        	printf("Некорректный ввод e\n");
        }
        else if(rez == 2){
        	printf("e не может быть меньше нуля\n");		
        }
    	else if(rez == 3){
    		printf("Ввод завершен (Ctrl + D)\n");
    		return 0;
    	}    	    	
    }
    float n = 0;
    long double a = funk1(x, e, &n);
    printf("Количество членов ряда %.0f\n", n);
    int m = (-1) * log10(e);
    long double test = logl(1 + x);
    printf("Ожидаемый ответ %.20Lf\n", test);
    printf("Ответ:          %.*Lf\n",m, a);
    printf("Погрешность     %.20Lf\n", fabsl(a - test));
    return 0;
}

int prog2(){
    long double x;
    int n;
    int rez;
	while(1){
    	rez = check_par(&x);
		if(rez == 0){
			break;
		}
    	if(rez == 1){
    		printf("Некорректный ввод x\n");
    	}
    	else if(rez == 2){
    	    printf("Х не лежит в допустимом диапазоне\n");		
    	}
		else if(rez == 3){
		    printf("Ввод завершен (Ctrl + D)\n");
		    return 0;
		}    	    	
    }
    while(1){
        rez = check_n(&n);
    	if(rez == 0){
    		break;
    	}
        else if(rez == 2){
        	printf("n не может быть меньше нуля\n");		
        }
    	else if(rez == 3){
    		printf("Ввод завершен (Ctrl + D)\n");
    		return 0;
    	}    	    	
    }	
    long double a = funk2(x, n);
	long double test = logl(1 + x);
	printf("Ожидаемый ответ %.20Lf\n", test);
    printf("Ответ:          %.20Lf\n", a);
    printf("Погрешность:    %.20Lf\n", fabsl(test - a));
    return 0;
}


int main(){
    int num_prog;
    printf("Вариант №75 Вычислить значение функции в точке при помощи разложения в ряд\n");
    printf("Введите номер программы: 1 с параметром и точностью, 2 с параметром и количеством членов ряда\n");
    while(scanf("%d", &num_prog) != EOF){
    	if(num_prog == 1){
        	prog1();
    	}
    	else if(num_prog == 2){
        	prog2();
    	}
    	else{
        	printf("Некоректный ввод номера программы\n");
    	}
    	printf("Введите номер программы: 1 с параметром и точностью, 2 с параметром и количеством членов ряда\n");
    	while (getchar() != '\n');    	
    }
    return 0;
}
