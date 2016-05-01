#include <stdio.h>
#include <math.h>

short isPrime(long factor){
	double factorRoot = (sqrt(factor));

	for(long i = 2; i <= factorRoot; i++){
		if(factor % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	printf("Enter a number to obtain its largest prime factor: \n");

	long number;
	scanf("%ld", &number);
	long root = (long)(sqrt(number));
	long largestPrime = 0;
	printf("Test1\n");
	
	for(long i = 2; i < root; i++){
		if(number % i == 0){
			long otherFactor = number / i;
			if(otherFactor > i && otherFactor > largestPrime && isPrime(otherFactor) == 1){
				largestPrime = otherFactor;
				break;
			}
			else if(i > largestPrime && isPrime(i) == 1){
				largestPrime = i;
			}
			
		}
	}

	if(largestPrime == 0){
		largestPrime = number;
	}

	printf("Largest Prime Factor: %ld \n", largestPrime);
	return 0;
}
