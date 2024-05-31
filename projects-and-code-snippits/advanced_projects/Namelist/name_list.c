#include"cmdargs.h"
#include<stdio.h>
#include<stdlib.h>
#include"List_func.h"
#include<errno.h>
#include<string.h>
//
void check_options(struct cmdargs options, struct Node* head_ref){
	int alp = size(&head_ref);
	if(options.sorts_by_gender == 1){
		sort_by_gender(head_ref);
		return;
	}
	else if(options.topX == 1){
        	TopX(head_ref,options.ptruntil,alp);
		return;
	}
	else if(options.sorts_by_alpha == 1){
        	alpha(head_ref,alp);
		return;
	}
	TopX(head_ref,10,alp);
//        printLinkedlist(head_ref);

}
//
void parse_name(struct Node* head, char* line, int rank){
	char* name;
	char* gender;
	char* count;
	int anzahl = 0;
	int rc = 0;
	rc = sscanf(line, "%m[^,],%m[^,],%m[^,]", &name, &count, &gender);
	anzahl = argparse_int(count);
  	if(rc != 3){
		return;
	}
	addName(head,name,gender[0],rank,anzahl);
}
//
int main(int argc, char **argv){
	const char *filename = argv[1];
	FILE *csv;
	char buffer[1024];
	int rank = 1;
	struct cmdargs options;
	struct Node *head = malloc(sizeof(struct Node));
	cmdargs_parse(&options, argc, argv);
	head->rank = 0;
        head->frist_name = "";
        head->gender = ' ';
        head->anzahl = 0;
        head->next = NULL;
	csv = fopen(filename, "r");
	if(csv == NULL){
		fprintf(stderr, "Couldn´t open '%s'; %s\n", filename, strerror(errno));
		return 1;
	}
	else{
		fgets(buffer,1024,csv);
		printf("%s", buffer);
		while(fgets(buffer,1024,csv)){
			parse_name(head,buffer,rank);
			rank++;
		}
		fclose(csv);
	}
	check_options(options,head);
return 0;
}
