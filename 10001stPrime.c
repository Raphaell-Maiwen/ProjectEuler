#include <stdio.h>
#include <math.h>

int main(){
	int index = 6; //Since first 6 prime are already given (2,3,5,7,11,13)
	long lastPrime = 0;
	for(int i = 14; ; i++){
		double root = sqrt(i);
		int prime = 1;
		for(int j = 2; j <= root; j++){
			if(i % j == 0){
				prime = 0;
				break;
			}
		}
		if(prime == 1){
			index++;
			if(index == 10001){
				lastPrime = i;
				break;
			}
		}
	}
	printf("10001st Prime: %ld\n", lastPrime);
	return 0;
}
