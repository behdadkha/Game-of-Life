#include "GameBoard.h"
#include "Display.h"
#include "catch.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

TEST_CASE( "tests for BoardT" , "[BoardT]"){

BoardT glider("Glider.txt");//glider
vector<vector<bool>> glide = glider.getGrid();
BoardT TenCell("TenCell.txt");//ten cell row
vector<vector<bool>> tencell = TenCell.getGrid();


	SECTION( "constructor normal case to see if grid is initialized correctly" ){
		REQUIRE
		((	
			glide[7][6] == true
		      &	tencell[6][3] == true
 		      & glide[0][0] == false
		      & tencell[0][0] == false

		));
	}
	SECTION("constructor throws invalid argument when the file does not exist"){
		REQUIRE_THROWS_AS(BoardT("nothing.txt"), ::invalid_argument);
	}
	SECTION("constructor throws out of range for grids other than 20x20"){
		ofstream Wfile("Glider1.txt");
		for(int row = 0; row < 10; row++){
			for(int col = 0; col < 10; col++){
				Wfile << 0;
			}
			Wfile << endl;
		}
		Wfile.close();
		REQUIRE_THROWS_AS(BoardT("Glider1.txt"), ::out_of_range);
	}
	SECTION("is_cell_alive normal case"){
		REQUIRE
		((
			  glider.is_cell_alive(7,6) == true
			& glider.is_cell_alive(8,7) == true
			& glider.is_cell_alive(9,7) == true
			& glider.is_cell_alive(9,9) == false
		));
		for(int i = 1; i < 11; i++){
			REQUIRE(TenCell.is_cell_alive(6,i) == true);
		}
	}
	SECTION("is_cell_alive throws exception in case of wrong row"){
		REQUIRE_THROWS_AS(glider.is_cell_alive(-1,5), ::out_of_range);
		REQUIRE_THROWS_AS(glider.is_cell_alive(21,19), ::out_of_range);
		REQUIRE_THROWS_AS(glider.is_cell_alive(-15,12), ::out_of_range);
		REQUIRE_THROWS_AS(TenCell.is_cell_alive(-16,2), ::out_of_range);
	}
	SECTION("is_cell_alive throws exception in case of wrong column"){
		REQUIRE_THROWS_AS(glider.is_cell_alive(19,540), ::out_of_range);
                REQUIRE_THROWS_AS(glider.is_cell_alive(5,-1), ::out_of_range);
	}
	SECTION("set_cell_alive, general cases"){
		glider.set_cell_alive(0,0);
		REQUIRE(glider.is_cell_alive(0,0));

		REQUIRE(TenCell.is_cell_alive(0,1) == false);
		TenCell.set_cell_alive(0,1);
		REQUIRE(TenCell.is_cell_alive(0,1) == true);
	}
	SECTION("set_cell_alive throws out of range for wrong row,column"){
		REQUIRE_THROWS_AS(glider.set_cell_alive(-1,1), ::out_of_range);
		REQUIRE_THROWS_AS(TenCell.set_cell_alive(-20,20), ::out_of_range);
	}

	SECTION("set_cell_dead normal cases"){
		REQUIRE(TenCell.is_cell_alive(6,1) == true);//[6][1] is alive
		TenCell.set_cell_dead(6,1);//make it dead
		REQUIRE(TenCell.is_cell_alive(6,1) == false);
	}
	SECTION("set_cell_dead throws out of range for invalid row/column"){
		REQUIRE_THROWS_AS(glider.set_cell_dead(5,-1), ::out_of_range);
		REQUIRE_THROWS_AS(glider.set_cell_dead(-5,0), ::out_of_range);
		REQUIRE_THROWS_AS(glider.set_cell_dead(-1,20), ::out_of_range);
	}
	SECTION("next_state normal case, next iteration of the game"){
		REQUIRE(TenCell.is_cell_alive(5,2) == false);
		TenCell.next_state();
		REQUIRE(TenCell.is_cell_alive(5,2) == true);

		REQUIRE(glider.is_cell_alive(10,6) == false);
		glider.next_state();
		REQUIRE(glider.is_cell_alive(10,6) == true);
	}
	SECTION("getGrid normal case"){
		REQUIRE(glide[10][5] == glider.is_cell_alive(10,5));
		//using the .getGrid at the top to get glide and tencell 
		REQUIRE(tencell[5][0] == TenCell.is_cell_alive(5,0));
	}
	
}
