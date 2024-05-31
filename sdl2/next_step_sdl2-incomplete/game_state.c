/**
 * @file
 *
 * Implements the program's logic.
 */

#include "game_state.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
/*
 * note for the code in comments.
 * The code in comments is part of a subtask that I am unable to complete.
 * I am leaving it in just in case I may find the time and interest to finish it later.
*/

void game_state_init(struct game_state *state){

	static const struct game_state default_state = {.obj.speedx = 1, .obj.y = 50, .obj.dead = 0, .obj.next = NULL};
	*state = default_state;
}
//
struct game_objects object_update(struct game_objects obj_sq){
        if(obj_sq.dead == 0){
		obj_sq.x += obj_sq.speedx;
        	obj_sq.y += obj_sq.speedy;
	}

        if(obj_sq.y >= 400){
                obj_sq.speedy *= -1;
		obj_sq.dead = 0;
        }
        if(obj_sq.x > 590){
                obj_sq.speedx*=-1;
		obj_sq.dead = 0;
        }
        if(obj_sq.x <= 0){
                obj_sq.speedy*=-1;
		obj_sq.dead = 0;
        }
	if(obj_sq.y <= 0){
		obj_sq.speedy*=-1;
		obj_sq.dead = 0;
	}
        // This part of the code will later be responisble to remove non jumping objects.
	// A glitch will appear if the objects y-value gets higher than 402.
	// If the objects reaches this point it will stopping --> result in a complete hold of the object.
        if(obj_sq.y >= 402){
                obj_sq.speedy = 0;
		//question: how can an object which speed is determinted by an integer and that speed is by default set to 1 by slowed over time?
		obj_sq.speedx = 0;
		obj_sq.dead = 1;
        }
        else{
                obj_sq.speedy += 1;
        }
	return obj_sq;
}
//
int getY(const struct game_objects* obj_sq){
	return obj_sq->y;
}
//
int getX(const struct game_objects* obj_sq){
	return obj_sq->x;
}
//
void game_state_update(struct game_state *state){
	// has to executed at least ones with the initial object.
	state->obj = object_update(state->obj);
	// addtion --> timer of one second condition.
	if(state->obj.dead == 1){
		int check = 0;
		struct timespec start, finish;
        	while(check < 1){
                	clock_gettime(CLOCK_MONOTONIC,&start);
			sleep(1);
                	clock_gettime(CLOCK_MONOTONIC,&finish);
                	check = abs(finish.tv_sec - start.tv_sec);
		}
        	if(check >= 1){
			free(state);
		}
	}
}
//
int size(struct game_objects* head_ref){
        struct game_objects* temp = head_ref;
        int count = 0;
        while(temp != NULL){
                count++;
                temp = temp->next;
        }
        return count;
}
void boost(struct game_objects* obj){
	obj->speedy -= 25;
}
//
//I am unable to achieve the second task therefore this will not be finished.
// I will move on and sadly won´t complete this exersice.
/*void addHead(struct game_objects* head_ref, int this_x, int this_y){
        struct game_objects* new_node = malloc(sizeof(struct game_state*));
	if(new_node == NULL){
		exit(1);
	}
	else{
        new_node->x = this_x;
	new_node->y = this_y;
	new_node->speedx = 1;
	new_node->speedy = 1;
	new_node->dead = 0;
        new_node->next = head_ref;
        head_ref = new_node;
	}
}*/

