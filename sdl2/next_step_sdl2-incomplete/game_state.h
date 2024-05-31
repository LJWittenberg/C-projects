#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_
#include<stddef.h>
#include<stdlib.h>
struct game_objects{
        unsigned int x; /**< The current x position of the rectangle */
        unsigned int y; /**< The current y position of the rectangle */
        unsigned int speedx; /**< The rectangle's horizontal speed */
        unsigned int speedy; /**< The rectangle's vertical speed */
        unsigned int dead;//Variable to check if the square has stopped moving and is to be deleted.
	struct game_objects* next;
};
/** This is the context that contains all of the logical game state */
//
struct game_state
{
	// obj represents head could later be renamed
	struct game_objects obj;
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
//
struct game_objects object_update(struct game_objects obj_sq);
//
int getY(const struct game_objects* obj_sq);
//
int getX(const struct game_objects* obj_sq);
//
void addHead(struct game_objects* head_ref, int this_x, int this_y);
//
int size(struct game_objects* head_ref);
//
void boost(struct game_objects* obj);
#endif
