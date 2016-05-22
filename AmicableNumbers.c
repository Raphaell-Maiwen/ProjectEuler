#include <stdio.h>

long d(int number){
	long sum = 0;
	for(int i = 1; i < number; i++){
		if(number % i == 0){
			sum += i;
		}
	}
	return sum;
}

int main(){
	long divisorsSum[10000];
	int sum = 0;

	for(int n = 0; n < 10000; n++){
		divisorsSum[n] = d(n);
	}

	for(int i = 0; i < 10000; i++){
		long index = divisorsSum[i];
		if(index < 10000){
			if(divisorsSum[index] == i && i < index){
				sum += index;
				sum += i;
			}	
		}
	}

	printf("%d\n", sum);
	return 0;
}
