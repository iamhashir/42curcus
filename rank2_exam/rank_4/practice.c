#include "stdio.h"
#include "stdlib.h"

typedef struct hashir
{
	char *a;
	struct hashir *next;
	struct hashir *prev;
}
hashir;

hashir *create(char * data){
	hashir *c = (hashir *)malloc(sizeof(hashir));
	if(!c){
		return NULL;
	}
	c->a= data;
	c->next=NULL;
	c->prev=NULL;
	return c;
}

void add(hashir **head, char * data){
	hashir *node = create(data);
	int i= 0;
	if(*head==NULL){
		*head=node;
	}	else{
		hashir *temp = *head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=node;
		node->prev=temp; 
	}
}
void printer(hashir *head){
    hashir *temp = head;
    while (temp != NULL) {
        printf(" %s ", temp->a);
        temp = temp->next;
    }
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	printf("\n");
    while (temp != NULL) {
        printf(" %s ", temp->a);
        temp = temp->prev;
    }
}
void frees(hashir **head) {
    hashir *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main() {
    char* str="hashir malik";
	while(*str !=NULL && *str !='\0'){
		if(*str==' '){
			*str='\0';
		}
		str++;
	}
	printf("%s",str);

	hashir* head = NULL;

    add(&head, "malik");
    add(&head, "hashir");
    add(&head, "traversing");

    printer(head);
	frees(&head);

    return 0;
}
 