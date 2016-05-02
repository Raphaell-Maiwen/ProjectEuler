#include <stdio.h>
#include <math.h>

long sumOfSquares(){
	long result = 0;
	for(int i = 1; i <= 100; i++){
		result += (long)pow(i, 2);
	}
	return result;
}

long squareOfSum(){
	long result = 0;
	for(int i = 1; i <= 100; i++){
		result += i;
	}
	result = (long)pow(result, 2);
	return result;
}

int main(){
	long subtrahend = sumOfSquares();
	long minuend = squareOfSum();
	long difference = minuend - subtrahend;
	printf("Difference: %ld\n", difference);
	return 0;
}
