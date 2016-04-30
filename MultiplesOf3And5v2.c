#include <stdio.h>

int sum(int number){
	int result = 0;
	int i = 3;
	int j = 5;
	for(;;){
		if(i < j){
			result += i;
			i += 3;
		}
		else if(j < i){
			result += j;
			j += 5;
		}
		else{
			result += i;
			i += 3;
			j += 5;
		}
		
		if(j >= number && i >= number){
			break;
		}
	}
	return result;
}

int main(){
	puts("Enter a number to find the sum of all the multiples of 3 and 5 below it.");
	int number;
	int result;
	int valid = scanf("%d", &number);
	result = sum(number);
	printf("The sum is %d \n", result);
	return 0;
}
