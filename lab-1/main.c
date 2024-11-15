#include <stdio.h>
#include <stdbool.h>
#include "reverse.h"

int main(){
	printf("Вариант №16: Дано целое число. Получить новое целое число только из различных цифр введенного числа\n");
	bool num[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};	
	int vvod, now;
	int znak = 1;
	int result = 0;
	scanf("%d", &vvod);
	if(vvod < 0){
		znak = -1;
		vvod *= -1;
	}
	vvod = reverse(vvod);
	while(vvod > 0){
		now = vvod % 10;
		if(num[now]){
			result = result * 10 + now;
			num[now] = 0; 
		}
		vvod /= 10;
	}
	result *= znak;
	printf("Otvet %d\n", result);
}
