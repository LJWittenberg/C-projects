#ifndef _LIST_FUNC_H_
#define _LIST_FUNC_H_
struct Node {
	int anzahl;
	int rank;
	char* frist_name;
	char gender;
        struct Node *next;
};



void addName(struct Node* head_ref, char* name, char gender, int new_rank, int this_anzahl);
//
void TopX(struct Node* head_ref, int count, int sort_count);
//
void printLinkedlist(struct Node *p);
//
void sort_by_gender(struct Node* head_ref);
//
struct Node* swap(struct Node* ptr1, struct Node* ptr2);
//
void sort_by_alpha(struct Node** head_ref, int count);
//
void sort_by_amount(struct Node** head_ref, int count);
//
int size(struct Node** head_ref);
//
void alpha(struct Node* head_ref, int sort_count);
#endif
