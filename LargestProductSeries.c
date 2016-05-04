#include <stdio.h>

int main(){
	int theNumber [1000];
	long biggestProduct = 0;

	for(int i = 0; i < 1000; i++){
		scanf("%1d", &theNumber[i]);
	}

	for(int i = 0; i < 1000; i++){
		long product = theNumber[i];
		for(int j = 1; j < 13 && i+j < 1000; j++){
			product = product * theNumber[i+j];
		}
		if(product > biggestProduct){
			biggestProduct = product;
		}
	}

	printf("Greatest product: %ld\n", biggestProduct);
	return 0;
}
