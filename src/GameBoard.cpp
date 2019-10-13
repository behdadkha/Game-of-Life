//author: Behdad Khamneli, khamneb
//collaborator: Behzad khamneli
#include "GameBoard.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

BoardT::BoardT(string FileName){
	grid = new bool*[SIZE];//instance variable
	for(int i = 0; i < SIZE; i++){
		grid[i] = new bool[SIZE];
	}
	for(int row = 0; row < SIZE; row++){//to make all the cells dead initially
		for(int col = 0; col < SIZE; col++){
			grid[row][col] = 0;
		}
	}
	fstream read;
	read.open(FileName);
	if(read.fail())
		throw invalid_argument("File could not be opened");
	string line;
	int x = 0;
	int y = 0;
	while(getline(read,line)){
		for(char c : line){
			int val = (int)c;
			if( val == 49 ){
				grid[y][x] = true;
			}
			x++;
		}
		if(x != 20)
                                throw out_of_range("wrong number of columns");
		x = 0;
		y++;
			
	}
	if(y != 20)
                   throw out_of_range("wrong number of rows");
	read.close();
}
void BoardT::next_state(){
	bool gridCopy[SIZE][SIZE] = {};
	
	copyGrid(gridCopy);
	
	for(int row = 0; row < SIZE; row++ ){
		for(int col = 0; col < SIZE; col++){
			int point = 0;

			for(int difRow = -1; difRow <= 1; difRow++){
				for(int difCol = -1; difCol <= 1; difCol++){
					if(col+difCol != -1 && col+difCol != SIZE && row+difRow != -1 && row+difRow != SIZE){
						if(gridCopy[row+difRow][col+difCol] && !(difCol == 0 && difRow == 0))
							point++;
					}
				}
			}
			
			if(point == 3)
				grid[row][col] = true;
			else if(point < 2)
				grid[row][col] = false;
			else if(point > 3)
				grid[row][col] = false;
		}
	}
}
bool BoardT::is_cell_alive(int row, int col){
	if(row < 0 || row >= 20 || col < 0 || col >= 20)
		throw out_of_range("invalid row or column");
	return grid[row][col];
}
void BoardT::set_cell_alive(int row, int col){
	if(row < 0 || row >= 20 || col < 0 || col >= 20)
                throw out_of_range("invalid row or column");

	grid[row][col] = true;	
}
void BoardT::set_cell_dead(int row, int col){
	if(row < 0 || row >= 20 || col < 0 || col >= 20)
                throw out_of_range("invalid row or column");

	grid[row][col] = false;
}
void BoardT::copyGrid(bool gridCopy[SIZE][SIZE]){
	for(int row = 0; row < SIZE; row++){
		for(int col = 0; col < SIZE; col++){
			gridCopy[row][col] = grid[row][col];
		}
	}
}

vector<vector<bool>> BoardT::getGrid(){
	vector<vector<bool>> GridVector(SIZE, vector<bool>(SIZE));
	for(int row = 0; row < SIZE; row++){
		for(int col = 0; col < SIZE; col++){
			GridVector[row][col] = grid[row][col];
		}
	}
	return GridVector;
}
