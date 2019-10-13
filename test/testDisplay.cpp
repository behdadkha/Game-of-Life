#include "Display.h"
#include "GameBoard.h"
#include "catch.h"
#include <fstream>
#include <vector>

using namespace std;
TEST_CASE( "tests for Display module", "[Show]"){

	view show;
	BoardT board("Glider.txt");
	vector<vector<bool>> glider = board.getGrid();
 
	SECTION( "displays a grid in a text file"){
		show.output(glider, "testGrid.txt");
		fstream read;
		read.open("testGrid.txt");
		bool grid[20][20];
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
                	x = 0;
                	y++;

        	}
        	read.close();
		for(int row = 0; row < 20; row++){
			for(int col = 0; col < 20; col++){
				REQUIRE(grid[row][col] == glider[row][col]);
			}
		}
		
	}
	
}

