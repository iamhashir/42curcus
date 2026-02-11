
#include "stdio.h"
#include "stdlib.h"
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while(begin_list){
		f(begin_list->data);
		begin_list=begin_list->next;
	}
}
void f(void *c){
	c=NULL;
}

int main(){
	
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
    node1->next = NULL;
    int d = 5;
    node1->data = &d;

    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    node2->next = node1;
    int c = 7;
    node2->data = &c;

    t_list *node3 = (t_list *)malloc(sizeof(t_list));
    node3->next = node2;
    int b = 5;
    node3->data = &b;

    t_list *node4 = (t_list *)malloc(sizeof(t_list));
    node4->next = node3;
    int a = 3;
    node4->data = &a;

	ft_list_foreach(node4,f);
	t_list *temp = node4;
	while(temp!=NULL){
		printf("%d\n",*(int*)temp->data);
		temp=temp->next;
	}

}