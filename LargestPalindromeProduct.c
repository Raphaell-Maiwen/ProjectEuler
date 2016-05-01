#include <stdio.h>

int largestPalindrome = 0;

void isPalindrome(int product){
	char digits[7];
	int length = sprintf(digits, "%d", product);
	char reverse[6];
	if(length == 6){
		reverse[0] = digits[5];
		reverse[1] = digits[4];
		reverse[2] = digits[3];
		reverse[3] = digits[2];
		reverse[4] = digits[1];
		reverse[5] = digits[0];
		if(reverse[0] == digits[0] && reverse[1] == digits[1] &&
			reverse[2] == digits[2] && reverse[3] == digits[3]
			&& reverse[4] == digits[4] && reverse[5] == digits[5] 
			&& product > largestPalindrome){
			largestPalindrome = product;
		}
	}
	else{
		reverse[0] = digits[4];
		reverse[1] = digits[3];
		reverse[2] = digits[2];
		reverse[3] = digits[1];
		reverse[4] = digits[0];
		if(reverse[0] == digits[0] && reverse[1] == digits[1] 
			&& reverse[2] == digits[2] && reverse[3] == digits[3]
			&& reverse[4] == digits[4] && product > largestPalindrome){
			largestPalindrome = product;
		}
	}
}

int main(){
	printf("Largest palindrome made from the product of 3-digit numbers: ");
	for(int i = 100; i < 1000; i++){
		for(int j = 100; j < 1000; j++){
			int product = i * j;
			isPalindrome(product);
		}
	}

	printf("%d\n", largestPalindrome);
	return 0;
}
