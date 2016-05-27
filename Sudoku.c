//A C program that takes an unsolved Sudoku grid as an input and display the solution.

#include <stdio.h>
#include <stdbool.h>

int rows [9][9];
int columns [9][9];
int grids [9][9];
bool newNumber = true;
bool tempBool = true;

void gridSearch(int grid, int number){
	bool cases [9];
	for(int i = 0; i < 9; i++){
		if(grids[grid][i] != 0){
			cases[i] = true;
		}
		else{
			cases[i] = false;
		}
	}

	//First, verification by rows
	int start = 0;
	if(grid > 5){
		start = 6;
	}
	else if (grid > 2){
		start = 3;
	}

	for(int i = start; i < start+3; i++){
		for(int j = 0; j < 9; j++){
			if(rows[i][j] == number){
				cases[(i % 3) * 3] = true;
				cases[(i % 3) * 3 +1] = true;
				cases[(i % 3) * 3 +2] = true;
				break;
			}
		}
	}

	//Second, verification by columns
	start = 0;
	if(grid % 3 == 2){
		start = 6;
	}
	else if(grid % 3 == 1){
		start = 3;
	}

	for(int i = start; i < start+3; i++){
		for(int j = 0; j < 9; j++){
			if(columns[i][j] == number){
				cases[i % 3] = true;
				cases[i % 3 +3] = true;
				cases[i % 3 +6] = true;
				break;
			}
		}
	}

	int zeros = 0;
	int index;
	for(int i = 0; i < 9; i++){
		if(cases[i] == false){
			zeros++;
			index = i;
		}
		//Little optimization!
		if(zeros >=2){
			return;
		}
		
	}

	grids[grid][index] = number;
	rows[grid / 3 * 3 + index/3][grid % 3 * 3 + index%3] = number;
	columns[grid % 3 * 3 + index%3][grid/3 * 3 + index/3] = number;

	newNumber = true;
	tempBool = true;
}

void rowSearch(int row, int number){
	bool cases [9];
	for(int i = 0; i < 9; i++){
		if(rows[row][i] != 0){
			cases[i] = true;
		}
		else{
			cases[i] = false;
		}
	}

	//Verification by grid
	int start = 0;
	if(row > 5){
		start = 6;
	}
	else if (row > 2){
		start = 3;
	}

	for(int i = start; i < start+3; i++){
		for(int j = 0; j < 9; j++){
			if(grids[i][j] == number){
				cases[(i % 3) * 3] = true;
				cases[(i % 3) * 3 +1] = true;
				cases[(i % 3) * 3 +2] = true;
				break;
			}
		}
	}

	//Verification by columns
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(columns[i][j] == number){
				cases[i] = true;
				break;
			}
		}
	}

	int zeros = 0;
	int index;
	for(int i = 0; i < 9; i++){
		if(cases[i] == false){
			zeros++;
			index = i;
		}
		
		if(zeros >=2){
			return;
		}
		
	}

	rows[row][index] = number;
	columns[index][row] = number;
	grids[row/3*3 + index/3][row%3*3 + index%3] = number;

	newNumber = true;
	tempBool = true;
}

void columnSearch(int column, int number){
	bool cases [9];
	for(int i = 0; i < 9; i++){
		if(columns[column][i] != 0){
			cases[i] = true;
		}
		else{
			cases[i] = false;
		}
	}

	//Verification by grid
	int start = 0;
	if(column > 5){
		start = 2;
	}
	else if (column > 2){
		start = 1;
	}

	for(int i = start; i <= start+6; i+=3){
		for(int j = 0; j < 9; j++){
			if(grids[i][j] == number){
				cases[(i / 3) * 3] = true;
				cases[(i / 3) * 3 +1] = true;
				cases[(i / 3) * 3 +2] = true;
				break;
			}
		}
	}

	//Verification by rows
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(rows[i][j] == number){
				cases[i] = true;
				break;
			}
		}
	}

	int zeros = 0;
	int index;
	for(int i = 0; i < 9; i++){
		if(cases[i] == false){
			zeros++;
			index = i;
		}
		
		if(zeros >=2){
			return;
		}
		
	}
	
	columns[column][index] = number;
	rows[index][column] = number;
	grids[index/3*3 + column/3][index%3*3 + column%3] = number;

	newNumber = true;
	tempBool = true;
}

int main(){
	bool solved = false;

	//Store the input in rows.
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%1d", &rows[i][j]);
		}
	}

	//Store the input in columns
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			columns[j][i] = rows [i][j];
		}
	}

	//Store the input in 9*9 grids.
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 3; j++){
			grids[i][3*j] = rows[(i/3)* 3 + j][(i%3) * 3];
			grids[i][3*j +1] = rows[(i/3) * 3 + j][(i%3) * 3 +1];
			grids[i][3*j +2] = rows[(i/3) * 3 + j][(i%3) * 3 +2];
		}
	}

	/*while(!solved){
		printf("Lol");
	}*/

	//TODO: Put the following code inside the while loop (see above)
	while(tempBool){
		tempBool = false;
		while(newNumber){
			newNumber = false;
			for(int grid = 0; grid < 9; grid++){
				for(int i = 1; i <= 9; i++){
					bool found = false;
					for(int j = 0; j < 9; j++){
						if(grids[grid][j] == i){
							found = true;
							break;
						}
					}
					if(!found){
						gridSearch(grid,i);
					}
				}
			}
		}
		newNumber = true;

		while(newNumber){
			newNumber = false;
			for(int row = 0; row < 9; row++){
				for(int i = 1; i <= 9; i++){
					bool found = false;
					for(int j = 0; j < 9; j++){
						if(rows[row][j] == i){
							found = true;
							break;
						}
					}
					if(!found){
						rowSearch(row,i);
					}
				}
			}
		}

		newNumber = true;

		int lol = 0;
		while(newNumber && lol < 10){
			newNumber = false;
			for(int column = 0; column < 9; column++){
				for(int i = 1; i <= 9; i++){
					bool found = false;
					for(int j = 0; j < 9; j++){
						if(columns[column][j] == i){
							found = true;
							break;
						}
					}
					if(!found){
						columnSearch(column,i);
					}
				}
			}
			lol++;
		}
	}

	printf("Final: \n");		
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%d", rows[i][j]);
		}
		printf("\n");
	}
	return 0;
}
