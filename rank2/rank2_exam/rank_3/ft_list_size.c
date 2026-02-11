#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list){
	if(begin_list !=0){
		return (1+ ft_list_size(begin_list->next));
	}
}


int main() {
 

    return 0;
}