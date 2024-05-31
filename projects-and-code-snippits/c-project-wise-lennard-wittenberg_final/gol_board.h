#ifndef GOL_BOARD_H
#define GOL_BOARD_H

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

struct board{
// @param cells represents the cells in the Game of Life. the array should only hold 1 --> alive or 0 --> dead.
// other datatypes like bool or char could be used instead.
// The first dimension is supposed to represent the rows of the game_grid.
// The second dimension is supposed to represent the coloums of the game_grid.
// @param current_cells represent the current generation
// @param updated_cells represents the next generation.
	int **current_cells;
	int **updated_cells;
	int max_rows;
	int max_cols;
};
//
/*
 * Initializing the game grid in the form of a coordinate system.
 * The top left corner has the coordinates x = 0; y = 0
 * The top right corner has the coordinates x = max x; y = 0
 * The bottom left corner has the coordinates x = 0; y = max y
 * The bottom right corner has the coordinates x = max x; y = max y
 * At the start of the game all cells are dead.
 *@param r and c represent the maximum values for the rows and coloumns.
*/
struct board initialize_board(struct board game, int r, int c);
//
/*
 * Support function to test if a specific cell in inside of the grid.
 * used for the count_live_neighbours function and indirectly for the enforce_rules function.
*/
int cell_in_grid(struct board game, int cur_row, int cur_col);
//
/*
 * Support function that counts all surrounding live neighbours of a inspected cell.
 * @param cur_row and cur_col represent the x and y coordinates of the inspected cell.
*/
int count_live_neighbours(struct board game, int cur_row, int cur_col);
//
/*
 * Function to apply the rules of Conways game of Life.
*/
void enforce_rules(struct board game);
//
/*
 * Function to free the allocated memory of the structur
*/
void delete_board(struct board game);
//
/*
 * Function to print out the live cells of the grid to create the Game of Life simulation.
*/
void print_game(struct board game);
//
/*
 * transfering the data of updated_cells into current_cells and declaring all cells in updated cells as dead.
*/
void swap_cell_states(struct board game);
//
/*
 * Function to varify if any live cells are left withing the game.
*/
int check_dead_life(struct board game);
#endif
