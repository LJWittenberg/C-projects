#include"gol_board.h"
#include"cmdargs.h"
// currently only used for i/o debugging - unit testing.
int main(int argc, char **argv){
	// 40 by 210 allows the user to use their entire screen.
        struct board game = initialize_board(game,40,210);
	struct cmdargs cell_input;
	cmdargs_parse(&cell_input,argc,argv,game.max_rows,game.max_cols);
	for (int i = 0; i < game.max_rows; i++) {
                for (int j = 0; j < game.max_cols; j++) {
                        game.current_cells[i][j] = cell_input.a[i][j];
                }
        }
	delete_buffer(cell_input);
//
	/*
	 * The following code will create different example figures in grid
	*/
/*	//Blinker
	game.current_cells[23][1] = 1;
        game.current_cells[23][2] = 1;
        game.current_cells[23][3] = 1;
	game.current_cells[23][5] = 1;
        game.current_cells[23][6] = 1;
        game.current_cells[23][7] = 1;
	// Still life
	game.current_cells[0][18] = 1;
	game.current_cells[0][19] = 1;
	game.current_cells[1][19] = 1;
//
	//Glider
	game.current_cells[1][1] = 1;
        game.current_cells[2][2] = 1;
        game.current_cells[3][0] = 1;
        game.current_cells[3][1] = 1;
        game.current_cells[3][2] = 1;
//
	//Pulsar
	game.current_cells[11][4] = 1;
        game.current_cells[12][4] = 1;
        game.current_cells[13][4] = 1;
        game.current_cells[17][4] = 1;
        game.current_cells[18][4] = 1;
        game.current_cells[19][4] = 1;
        game.current_cells[11][9] = 1;
        game.current_cells[12][9] = 1;
        game.current_cells[13][9] = 1;
        game.current_cells[17][9] = 1;
        game.current_cells[18][9] = 1;
        game.current_cells[19][9] = 1;
        game.current_cells[11][11] = 1;
        game.current_cells[12][11] = 1;
        game.current_cells[13][11] = 1;
        game.current_cells[17][11] = 1;
        game.current_cells[18][11] = 1;
        game.current_cells[19][11] = 1;
        game.current_cells[11][16] = 1;
        game.current_cells[12][16] = 1;
        game.current_cells[13][16] = 1;
        game.current_cells[17][16] = 1;
        game.current_cells[18][16] = 1;
        game.current_cells[19][16] = 1;
        game.current_cells[9][6] = 1;
        game.current_cells[9][7] = 1;
        game.current_cells[9][8] = 1;
        game.current_cells[9][12] = 1;
        game.current_cells[9][13] = 1;
        game.current_cells[9][14] = 1;
        game.current_cells[14][6] = 1;
        game.current_cells[14][7] = 1;
        game.current_cells[14][8] = 1;
        game.current_cells[14][12] = 1;
        game.current_cells[14][13] = 1;
        game.current_cells[14][14] = 1;
        game.current_cells[16][6] = 1;
        game.current_cells[16][7] = 1;
        game.current_cells[16][8] = 1;
        game.current_cells[16][12] = 1;
        game.current_cells[16][13] = 1;
        game.current_cells[16][14] = 1;
        game.current_cells[21][6] = 1;
        game.current_cells[21][7] = 1;
        game.current_cells[21][8] = 1;
        game.current_cells[21][12] = 1;
        game.current_cells[21][13] = 1;
        game.current_cells[21][14] = 1;

//
*/	int game_acctive = 1;
	while(game_acctive == 1){
		print_game(game);
		sleep(1);
		enforce_rules(game);
		swap_cell_states(game);
		game_acctive = check_dead_life(game);
	}
	delete_board(game);
return 0;
}
