/**
 * @file
 *
 * Implements the program's logic.
 */

#include "game_state.h"

void game_state_init(struct game_state *state){

	static const struct game_state default_state = {.speedx = 1, .y = 50};
	*state = default_state;
}

void game_state_update(struct game_state *state){

	state->x += state->speedx;
	state->y += state->speedy;

	if (state->y > 435) {
        	state->speedy *= -1;
    	}

	if(state->x > 590){
		state->speedx*=-1;
		state->speedy +=1;
	}
	if(state->x <= 0){
                state->speedy*=-1;
                state->speedx +=1;
        }

	/*if(state->speedy >= 100){
		state->speedy = 1;
	}*/

	//state->speedy += 1;
}
