#include <stdio.h>

int main(){
	int multiple = 0;
	for(int i = 2520; ;i+= 20){
		if(i % 11 == 0 && i % 12 == 0 && i % 13 == 0 && i % 14 == 0 && i % 15 == 0 && i % 16 == 0 &&
		i % 17 == 0 && i % 18 == 0 && i % 19 == 0){
			multiple = i;
			break;
		}
	}
	printf("Smallest positive number that is divisible by all of the numbers from 1 to 20:\n%d\n", multiple);
	return 0;
}

/*
Answer saw on the forum:
This does not require programming at all. Compute the prime factorization of each number from 1 to 20, and multiply the greatest power of each prime together:

20 = 2^2 * 5
19 = 19
18 = 2 * 3^2
17 = 17
16 = 2^4
15 = 3 * 5
14 = 2 * 7
13 = 13
11 = 11

All others are included in the previous numbers.

ANSWER: 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19 = 232 792 560

*/
