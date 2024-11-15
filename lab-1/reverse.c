int reverse(int num){
	int result = 0;
	while(num > 0){
		result = result * 10 + (num % 10);
		num /= 10;
	}
	return result;
}
