#include "GameBoard.h"
#include "Display.h"
#include <vector>
#include <iostream>
using namespace std;
int main(){

	BoardT board("Glider.txt");
	vector<vector<bool>> newBoard = board.getGrid();
	view out;
	cout << "input file" << endl;
	out.display(newBoard);
	cout << endl;
	for(int i = 0; i < 4; i++){
		cout << "state: " << i+1 << endl;
		board.next_state();
		newBoard = board.getGrid();
		out.display(newBoard);
		cout << endl;
	}
	out.output(newBoard, "output.txt");
}
