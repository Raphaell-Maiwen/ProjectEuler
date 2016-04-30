#include <stdio.h>

int sum(int number){
	int result = 0;
	for(int i = 3; i < number; i++){
		if(i % 3 == 0){
			result += i;
		}
		else if(i % 5 == 0){
			result += i;
		}
	}
	return result;
}

int main(){
	puts("Enter a number to find the sum of all the multiples of 3 and 5 below it.");
	int number;
	int result;
	//TODO: A verification loop to make sure we have a number, more precisely a positive one. 
	int valid = scanf("%d", &number);
	while(number < 0){
		puts("You must enter a positive number.");
		valid = scanf("%d", &number);
	}
	result = sum(number);
	printf("The sum is %d \n", result);
	return 0;
}
