#pragma once
#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdio.h>
#include <stdlib.h>
 
typedef struct s_list
{
    int data;
    struct s_list *next;
}   t_list;

 

 

#endif