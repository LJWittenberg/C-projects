/**
 * @file
 *
 * Test for functions in gcd_functions.c
 */
#include <assert.h>

/* Include the interface of the module under testing */
#include "gol_board.h"
#include "cmdargs.h"
/******************************************************/

static void test_Game_of_life_functions(void){
	struct board test_game;
	test_game = initialize_board(test_game,6,6);
	// testing if the requested dimensions have been created.
	test_game.current_cells[0][0] = 1;
	test_game.current_cells[2][2] = 1;
	test_game.current_cells[5][5] = 1;
	assert(test_game.current_cells[0][0] == 1);
	assert(test_game.current_cells[2][2] == 1);
	assert(test_game.current_cells[5][5] == 1);
	// testing cell in grid function.
	int pos1 = cell_in_grid(test_game,0,0);
	int pos2 = cell_in_grid(test_game,5,5);
	int pos3 = cell_in_grid(test_game,2,2);
	int pos4 = cell_in_grid(test_game,-1,3);
	int pos5 = cell_in_grid(test_game,8,99);
	assert(pos1 == 1);
	assert(pos2 == 1);
	assert(pos3 == 1);
	assert(pos4 == 0);
	assert(pos5 == 0);
	delete_board(test_game);
	// testing the live neightbours check:
	/* all cells are checked
	 * 1 1 1	0 0 0
	 * 1 1 1	1 1 1
	 * 1 1 1	0 0 0
	 * expected result 1 == 9. 	expected result 2 == 2 		expected result 3 == 2
	*/
	struct board test_game_neigh = initialize_board(test_game_neigh,3,3);
	// initializing all cells as alive.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
                        test_game_neigh.current_cells[i][j] = 1;
                }
        }
	int live_neigh_count1 = count_live_neighbours(test_game_neigh,1,1);
        int live_neigh_count2 = count_live_neighbours(test_game_neigh,0,0);
        int live_neigh_count3 = count_live_neighbours(test_game_neigh,0,1);
        int live_neigh_count4 = count_live_neighbours(test_game_neigh,0,2);
        int live_neigh_count5 = count_live_neighbours(test_game_neigh,1,0);
        int live_neigh_count6 = count_live_neighbours(test_game_neigh,1,2);
        int live_neigh_count7 = count_live_neighbours(test_game_neigh,2,0);
        int live_neigh_count8 = count_live_neighbours(test_game_neigh,2,1);
        int live_neigh_count9 = count_live_neighbours(test_game_neigh,2,2);
	assert(live_neigh_count1 == 8);
	assert(live_neigh_count2 == 3);
        assert(live_neigh_count3 == 5);
        assert(live_neigh_count4 == 3);
        assert(live_neigh_count5 == 5);
        assert(live_neigh_count6 == 5);
        assert(live_neigh_count7 == 3);
        assert(live_neigh_count8 == 5);
        assert(live_neigh_count9 == 3);
	// initializing all cells as dead.
        for (int i = 0; i < 3; i++) {  
                for (int j = 0; j < 3; j++) {
                        test_game_neigh.current_cells[i][j] = 0;
                }
        }
        test_game_neigh.current_cells[1][0] = 1;
        test_game_neigh.current_cells[1][1] = 1;
        test_game_neigh.current_cells[1][2] = 1;
        int live_neigh_count = count_live_neighbours(test_game_neigh,1,1);
	int test_0_3_0_2 = count_live_neighbours(test_game_neigh,1,0);
	int test_0_3_0_3 = count_live_neighbours(test_game_neigh,1,2);
        assert(live_neigh_count == 2);
	assert(test_0_3_0_2 == 1);
	assert(test_0_3_0_3 == 1);
	// testing enforce_rules()
	enforce_rules(test_game_neigh);
	swap_cell_states(test_game_neigh);
	assert(test_game_neigh.current_cells[0][1] == 1);
	assert(test_game_neigh.current_cells[1][1] == 1);
	assert(test_game_neigh.current_cells[2][1] == 1);
	print_game(test_game_neigh);
	assert(check_dead_life(test_game_neigh) == 1);
	delete_board(test_game_neigh);
	// testing cmdargs
	struct cmdargs cmdargs;
	int parse_check = cmdargs_parse(&cmdargs, 3,(char *[2]){ "5", "7"},10,10);
	assert(parse_check == 0);
	delete_buffer(cmdargs);
	int int_parse1;
	int int_parse2;
	int int_parse3;
	int_parse1 = argparse_int("10");
	assert(int_parse1 == 10);
	int_parse2 = argparse_int("0b1010");
        assert(int_parse2 == 10);
	int_parse3 = argparse_int("0x10");
	assert(int_parse3 == 16);
	assert(argparse_int("a") == 0);
}
/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
        test_Game_of_life_functions();
        return 0;
}
