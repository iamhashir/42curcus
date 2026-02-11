#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int cmp(int a, int b) {
	return (a <= b);
}

 


// t_list *sort_list(t_list* lst, int (*cmp)(int, int)) {
//     int swap;
//     t_list *start;

//     start = lst;

//     while (lst != NULL && lst->next != NULL)
//     {
//         if ((*cmp)(lst->data, lst->next->data) == 0)
// 		{
//             swap = lst->data;
//             lst->data = lst->next->data;
//             lst->next->data = swap;
//             lst = start;
//         }
// 	else
// 		lst = lst->next;
//     }
//     return (start);
// }
t_list *sort_list(t_list *head,int (*cmp)(int, int) ){
	t_list *start = head;
	int swap;
	while(head->next!=NULL){
		if((*cmp)(head->data,head->next->data)==0){
			swap = head->data;
			head->data=head->next->data;
			head->next->data=swap;
			head=start;
		}
		head=head->next;
	}
	return start;
}
int main(){

	t_list *node = (t_list *)malloc(sizeof(t_list));
	
	node->data=42;
	node->next=NULL;
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	node1->data=52;
	node1->next=node;
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	node2->data=62;
	node2->next=node1;
	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	node3->data=2;
	node3->next=node2;

	t_list *c=node3;

	sort_list(node3,&cmp);
	while(c){
		printf("%d\n",c->data);
		c=c->next;
	}
}

