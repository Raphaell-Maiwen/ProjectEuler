#include <stdio.h>
#include <math.h>

int main(){
	int a = 0; 
	int b;
	int c = 6;

	while(1 == 1){
		for(int i = c-1; i > 1; i--){
			double sqA = pow(c, 2) - pow(i, 2);
			if(sqrt(sqA) == (int)sqrt(sqA)){
				a = sqrt(sqA);
				b = i;
				if(a + b + c == 1000){
					break;
				}
				else{
					a = 0;
				}
			}
		}
		if(a != 0){
			if(a + b + c == 1000){
				break;
			}
		}
		c++;
	}
	printf("%d * %d * %d =\n", a, b, c);
	long product = a * b * c;
	printf("%ld", product);
	return 0;
}
