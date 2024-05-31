#include"gol_board.h"

struct board initialize_board(struct board game, int r, int c){
	// creating two two dimensional array pointers for the board
	int **matrix1 = (int **)malloc(r*sizeof(int *));
	for(int i = 0; i < r;i++){
		matrix1[i] = (int *) malloc(c*sizeof(int));
	}
        int **matrix2 = (int **)malloc(r*sizeof(int *));
        for(int i = 0; i < r;i++){
                matrix2[i] = (int *) malloc(c*sizeof(int));
        }
	game.current_cells = matrix1;
	game.updated_cells = matrix2;
	game.max_rows = r; // maximum x coordinate
	game.max_cols = c; // maximum y coordinate
	// initializing both pointer with values.
        for (int i = 0; i < game.max_rows; i++) {
                for (int j = 0; j < game.max_cols; j++) {
                        game.current_cells[i][j] = 0;
                        game.updated_cells[i][j] = 0;
                }
        }
	return game;
}
//
int cell_in_grid(struct board game, int cur_row, int cur_col){
	if( cur_row >= 0 && cur_col >= 0 && cur_row < game.max_rows && cur_col < game.max_cols){
		return 1;
	}
	return 0;
}
//
int count_live_neighbours(struct board game, int cur_row, int cur_col){
	int count = 0;
		for(int i=cur_row-1; i <= cur_row+1; i++){
			for(int j=cur_col-1; j <= cur_col+1; j++){
				int proceed_check = cell_in_grid(game,i,j);
				if(proceed_check == 1){
					if(game.current_cells[i][j] == 1){
						count++;
					}
				}
        		}
		}
		// the checked cell should not be considered.
		if(game.current_cells[cur_row][cur_col] == 1){
                	count--;
        	}
	return count;
}
//
void enforce_rules(struct board game){
	for(int i = 0; i < game.max_rows; i++){
		for(int j = 0; j < game.max_cols; j++){
			int neighbour_live_cell = count_live_neighbours(game,i,j);
			// check if a live cell should stay alive
			if(game.current_cells[i][j] == 1 && (neighbour_live_cell == 2 || neighbour_live_cell == 3)){
				game.updated_cells[i][j] = 1;
			}
			// check if a dead cell should become alive
			else if(game.current_cells[i][j] == 0 && neighbour_live_cell == 3){
				game.updated_cells[i][j] = 1;
			}
			// if non of the previous conditions apply the cell should be dead
			else{
				game.updated_cells[i][j] = 0;
			}
		}
	}
}
// freeing multline array pointers.
void delete_board(struct board game){
	for(int i = 0; i < game.max_rows; i++){
		free(game.current_cells[i]);
		free(game.updated_cells[i]);
	}
	free(game.current_cells);
        free(game.updated_cells);
}
//
void print_game(struct board game){
        for (int i = 0; i < game.max_rows; i++) {
                for (int j = 0; j < game.max_cols; j++) {
			if(game.current_cells[i][j] == 1){
				// alternative for the * print
                        	//printf("%d ", game.current_cells[i][j]);
				printf("*");
			}
			else{
				printf(" ");
			}
                }
                printf("\n");
        }
	printf("\n");
}
//
void swap_cell_states(struct board game){
	for (int i = 0; i < game.max_rows; i++) {
                for (int j = 0; j < game.max_cols; j++) {
                        game.current_cells[i][j] = game.updated_cells[i][j];
                        game.updated_cells[i][j] = 0;
                }
        }
}
//
int check_dead_life(struct board game){
	int dead = 0;
	for (int i = 0; i < game.max_rows; i++) {
                for (int j = 0; j < game.max_cols; j++) {
			if(game.current_cells[i][j] == 1){
				dead = 1;
			}
                }
        }
	return dead;
}
