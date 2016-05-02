#include <stdio.h>

int main(){
	int multiple = 0;
	for(int i = 2520; ;i+= 20){
		//11,12,13,14, 15, 16, 17,18, 19
		if(i % 11 == 0 && i % 12 == 0 && i % 13 == 0 && i % 14 == 0 && i % 15 == 0 && i % 16 == 0 &&
		i % 17 == 0 && i % 18 == 0 && i % 19 == 0){	//1,2,4,5,10,20
			multiple = i;
			break;
		}
	}
	printf("Smallest positive number that is divisible by all of the numbers from 1 to 20:\n%d\n", multiple);
	return 0;
}
