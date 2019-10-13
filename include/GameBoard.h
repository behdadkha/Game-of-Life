/**
 * \file GameBoard.h
 * \author Behdad Khamneli, khamneb
 * \brief Template module, ADT that stores the state of the game
 */
//collaborator : Behzad Khamneli
#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include <vector>
#include <string>
#define SIZE 20
using namespace std;
/**
 * \brif Class representing game of "Game of Life"
 * \details Creates a game board with 20 rows and 20 columns
 */
class BoardT{
	private:
		//Array storing the game
		bool** grid;
		/**
 		 * \brief Copy the grid into a new grid
 		 * \details Because we do not want the change in the main grid
 		 * before all the neighbors are checked
 		 * \param girdCopy The new array that sotres the copy of the main grid
 		 */ 
		void copyGrid(bool gridCopy[SIZE][SIZE]);
		
	public:
		/**
 		 * \brief Constructor for the BoardT
 		 * \param FileName A string representing the input file
 		 */
		BoardT(string FileName);

		/**
 		 * \brief Go to the next state of the game
 		 * \details Compute the number of cells alive around each cell
 		 * and follow the roles.
 		 */ 
		void next_state();

		/**
 		 * \brief Check if a cell is alive
 		 * \param row An integer representing the cell's row
 		 * \param col An integer representing the cell's column
 		 * \return True if the given cell is alive, False otherwise
 		 */
		bool is_cell_alive(int row, int col);

		/**
 		 * \brief Set a cell with given coordinations to alive
 		 * \param row An integer representing the cell's row
 		 * \param col An integer representing the cell's column 
 		 */
		void set_cell_alive(int row, int col);
	
		/**
 		 * \brief Set a cell with given coordinations to dead 
 		 * \param row An integer representing the cell's row
 		 * \param col An integer representing the cell's column
 		 */
		void set_cell_dead(int row, int col);

		/**
 		 * \brief Returns the grid representing the game's grid
 		 * \details converted to vector so that the main grid is not immutable 
 		 * \return A multidimensional vector representing the grid
 		 */
		vector<vector<bool>> getGrid();


		
};

#endif
