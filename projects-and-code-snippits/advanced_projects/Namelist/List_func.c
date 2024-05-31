#include<stdio.h>
#include<stdlib.h>
#include"List_func.h"
#include<string.h>
//
void addName(struct Node* head_ref, char* name, char gender, int new_rank, int this_anzahl){

	/* 1. allocate node */
	struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->frist_name = name;
	new_node->gender = gender;
	new_node->rank = new_rank;
	new_node->anzahl = this_anzahl;

	/* 3. This new node is going to be the last node, so
	make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
	* node as head */
	if (head_ref == NULL) {
		head_ref = new_node;
        return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL){
        	last = last->next;
	}

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}
//
void printLinkedlist(struct Node *p) {
	while (p != NULL) {
		printf("%d %s %c\n", p->rank, p->frist_name, p->gender);
    		p = p->next;
	}
}
//
void sort_by_gender(struct Node* head_ref){
	struct Node* laeufer = head_ref;
	struct Node* laeufer2 = head_ref;
	while(laeufer != NULL){
		if(laeufer->gender == 'w'){
			printf("%d %s %c\n", laeufer->rank, laeufer->frist_name, laeufer->gender);
		}
                laeufer = laeufer->next;
	}
	while(laeufer2 != NULL){
                if(laeufer2->gender == 'm'){
                        printf("%d %s %c\n", laeufer2->rank, laeufer2->frist_name, laeufer2->gender);
                }
                laeufer2 = laeufer2->next;
        }
	printf("\n");

}
//
int size(struct Node** head_ref){
        struct Node* temp = *head_ref;
        int count = 0;
        while(temp != NULL){
                count++;
                temp = temp->next;
        }
        return count;
}

/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2){
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
// 
/* Function to sort the list */
void sort_by_alpha(struct Node** head_ref, int count){
	struct Node** tmp = head_ref;
	for(int i = 0; i <= count;i++){
		tmp = head_ref;
		int swapped = 0;
		for(int j = 0; j< count -1 - i; j++){
			struct Node* n1 = *tmp;
			struct Node* n2 = n1->next;
			if(strcmp(n1->frist_name,n2->frist_name)>0){
				*tmp = swap(n1,n2);
				swapped = 1;
			}
			tmp = &(*tmp)->next;
		}
		if(swapped == 0){
			break;
		}
	}

}
void sort_by_amount(struct Node** head_ref, int count){
        struct Node** tmp = head_ref;
        for(int i = 0; i <= count;i++){
                tmp = head_ref;
                int swapped = 0;
                for(int j = 0; j< count -1 - i; j++){
                        struct Node* n1 = *tmp;
                        struct Node* n2 = n1->next;
                        if(n1->anzahl < n2->anzahl){
                                *tmp = swap(n1,n2);
                                swapped = 1;
                        }
                        tmp = &(*tmp)->next;
                }
                if(swapped == 0){
                        break;
                }
        }

}
//
void TopX(struct Node* head_ref, int count, int sort_count){
	sort_by_amount(&head_ref,sort_count);
	struct Node* tmp = head_ref;
	int count_prints = 0;
	while (tmp != NULL) {
                printf("%d %s %c %d\n", tmp->rank, tmp->frist_name, tmp->gender, tmp->anzahl);
                tmp = tmp->next;
		count_prints++;
		if(count_prints >= count){
			return;
		}
        }
	printf("\n");
}
//
void alpha(struct Node* head_ref, int count){
        sort_by_alpha(&head_ref,count);
        struct Node* tmp = head_ref;
        while (tmp != NULL) {
                printf("%d %s %c \n", tmp->rank, tmp->frist_name, tmp->gender);
                tmp = tmp->next;
        }
        printf("\n");
}
