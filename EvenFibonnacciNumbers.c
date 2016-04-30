#include <stdio.h>

int main(){
	int pred1 = 0;
	int pred2 = 1;
	int n = 0;
	int sum = 0;
	while(n < 4000000){
		n = pred1 + pred2;
		if(n % 2 == 0){
			sum += n;
		}
		pred1 = pred2;
		pred2 = n;
	}
	printf("Result: %d \n", sum);
	return 0;
}
