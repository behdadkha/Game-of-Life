// author: Behdad Khamneli, khamneb
// collaborator: Behzad Khamneli
#include "Display.h"
#include <iostream>
#include <fstream>
#include <string>
#define SIZE 20
using namespace std;

void view::display(vector<vector<bool>> grid){

	for(int row = 0; row < SIZE; row++){
                for(int col = 0; col < SIZE; col++){
                        if(grid[row][col])
                                cout << 1;
                        else
                                cout << 0;
                }
                cout << endl;
        }

}
void view::output(vector<vector<bool>> grid, string file){
	fstream outFile;
	outFile.open(file, ios::out);
	for(int row = 0; row < SIZE; row++){
		for(int col = 0; col < SIZE; col++){
			if(grid[row][col])
				outFile << 1;
			else
				outFile << 0;
		}
		outFile << endl;
	}
}

