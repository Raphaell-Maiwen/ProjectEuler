#include <stdio.h>
#include <math.h>

int divisors(long long number){
	//Would not work with 1.
	int divisors = 2;
	double root = sqrt(number);
	for(long i = 2; i < root; i++){
		if(number % i == 0){
			divisors+=2;
		}
	}
	if(root == (int)root){
		divisors++;
	}

	return divisors;
}

int main(){
	long long triangleNumber = 21;
	for(long i = 7;; i++){
		triangleNumber += i;
		printf("%lld\n", triangleNumber);
		int div = divisors(triangleNumber);
		printf("div: %d\n", div);

		if(div > 500){
			break;
		}
	}

	printf("%lld\n", triangleNumber);
	return 0;
}
