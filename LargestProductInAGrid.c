#include <stdio.h>

int main(){
	int grid [20][20];
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			scanf("%d", &grid[i][j]);
		}
	}

	long longestProduct = 0;
	long product = 0;

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(j < 17){
				product = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
				if(product > longestProduct){
					longestProduct = product;
				}
				if(i > 2){
					product = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
					if(product > longestProduct){
						longestProduct = product;
					}
				}
				if(i < 17){
					product = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
					if(product > longestProduct){
						longestProduct = product;
					}
					continue;
				}
			}
			if(i < 17){
				product = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
				if(product > longestProduct){
					longestProduct = product;
				}
			}
		}
	}

	printf("%ld\n", longestProduct);
	return 0;
}
