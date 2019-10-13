/**
 * \file Display.h
 * \author Behdad Khamneli, khamneb
 * \brief Displays the game grid
 */
//collaborator : Behzad Khamneli
#ifndef A4_DISPLAY_H_
#define A4_DISPLAY_H_
#include <vector>
#include <string>
using namespace std;

/**
 * \brief Display the game of life's grid
 * \details It has two functions, one writes the output into a file
 * and the other one displays the grid on the screen
 */
class view{
	public:
		/**
 		* \brief Write the grid into a file using 0s and 1s
 		* \param grid The grid from the game of life
 		* \param file The output file that needs to be generated
 		*/
		void output(vector<vector<bool>> grid, string file);
		/**
 		* \brief Display the grid on the screen using 0s and 1s
 		* \param grid The grid from the game of life
 		*/
		void display(vector<vector<bool>> grid);
		
};
#endif
