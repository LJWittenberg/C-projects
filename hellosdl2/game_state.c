/**
 * @file
 *
 * Implements the program's logic.
 */

#include "game_state.h"

void game_state_init(struct game_state *state)
{
  static const struct game_state default_state = {.speedx = 1, .y = 50};
  *state = default_state;
}

void game_state_update(struct game_state *state)
{
    state->x += state->speedx;
    state->y += state->speedy;

    if (state->y >= 400) {
        state->speedy *= -1;
    }

	if(state->x >= 642){
		state->x = 1;
		state->y = 50;
		state->speedy = 1;
	}

    state->speedy += 1;
}
