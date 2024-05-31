#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

/** This is the context that contains all of the logical game state */
struct game_state
{
    unsigned int x; /**< The current x position of the rectangle */
    unsigned int y; /**< The current y position of the rectangle */
    unsigned int speedx; /**< The rectangle's horizontal speed */
    unsigned int speedy; /**< The rectangle's vertical speed */
};

/**
 * Initialize the given game state with default values.
 * 
 * @param state the game state that shall be initialized
 */
void game_state_init(struct game_state *state);

/**
 * Execute one time step to update the games state.
 *
 * @param state defines the state of being updated.
 */
void game_state_update(struct game_state *state);

#endif