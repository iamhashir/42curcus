// #include "stdio.h"
// #include "stdlib.h"

// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	if (begin_list == NULL || *begin_list == NULL)
// 		return;

// 	t_list *cur = *begin_list;

// 	if (cmp(cur->data, data_ref) == 0)
// 	{
// 		*begin_list = cur->next;
// 		free(cur);
// 		ft_list_remove_if(begin_list, data_ref, cmp);
// 	}
// 	else  	{
// 		cur = *begin_list;
// 		ft_list_remove_if(&cur->next, data_ref, cmp);
// 	}
// }
// int main(){
// 	t_list *node = (t_list *)malloc(sizeof(node));
// 	node->next = NULL;
// 	int a =2;
// 	node->data  = &a;

// 	// printf("%i",*(int *)(node->data));
// 	ft_list_remove_if(&node, void *data_ref, int (*cmp)())
// }
#include "stdio.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct s_list
{
	struct s_list *next;
	void *data;
} t_list;

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	if (begin_list == NULL || *begin_list == NULL)
// 		return;

// 	t_list *cur = *begin_list;

// 	if (cmp(cur->data, data_ref) == 0)
// 	{
// 		*begin_list = cur->next;
// 		free(cur);
// 		ft_list_remove_if(begin_list, data_ref, cmp);
// 	}
// 	else // if there is a no else, you cant pass the Moulinette, tryed 2023.09.08
// 	{
// 		cur = *begin_list;
// 		ft_list_remove_if(&cur->next, data_ref, cmp);
// 	}
// }
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()){
	if(*begin_list == NULL || begin_list==NULL){
		return;
	}

	t_list *current=*begin_list;

	if(cmp(current->data,data_ref)==0){
		*begin_list=current->next;
		free(current);
		ft_list_remove_if(begin_list,data_ref,cmp);
	}
	else {
		current=*begin_list;
		ft_list_remove_if(&current->next,data_ref,cmp);
	}
}

	void ft_list_remove_if(t_list **begin , void *data, int (*cmo)()){

		if(begin!= NULL || * begin != NULL)
			return;
		t_list *cur = *begin;

		if(cmp(cur->data, data)==0)
		{
			begin = cur->next;
			free(cur);
			ft_list_remove_if(begin,data,cmp);
		}else{
			ft_list_remove_if(&cur,data,cmp);
		}
	}

int cmp(void *data, void *data_ref)
{
	int a = *(int *)data;
	int b = *(int *)data_ref;
	if (a == b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
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

    printf("Before deletion:\n");
    t_list *cur = node4;
    while (cur != NULL)
    {
        printf("%i\n", *(int *)(cur->data));
        cur = cur->next;
    }

    int ref = 5;
    ft_list_remove_if(&node4, &ref, cmp);

    printf("After deletion:\n");
    cur = node4;
    while (cur != NULL)
    {
        printf("%i\n", *(int *)(cur->data));
        cur = cur->next;
    }

    return 0;
}
