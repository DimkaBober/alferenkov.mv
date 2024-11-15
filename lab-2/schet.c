#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double funk1(double x, double e, float *n){
    long double result = 0;
    long double elem = x;
    float i = 2;
	result += elem;
    while(e < fabsl(elem)){ 
    	elem = elem * (-1) * x * ((i - 1) / i);
        result += elem;
        ++i;
    }
    *n = i - 1;
    return result;
}

long double funk2(double x, int n){
    long double result = 0;
    float i = 2;
    long double elem = x;
    result += elem;
    while(i < n){
        elem = elem * (-1) * x * ((i - 1) / i);
        result += elem;
        ++i;
    }
    return result;
}
