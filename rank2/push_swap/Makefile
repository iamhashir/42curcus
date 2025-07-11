 
NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/algorithm.c \
		srcs/push_swap/ft_add_node.c \
		srcs/push_swap/ft_stack_new.c \
		srcs/push_swap/ft_check_utils.c \
		srcs/push_swap/ft_parse.c \
		srcs/push_swap/solver_utils_ab.c \
		srcs/push_swap/solver_utils_ba.c \
		srcs/push_swap/ft_rotate_and_push.c \
		srcs/push_swap/operations.c \
		srcs/push_swap/operations_2.c \
		srcs/push_swap/operations_3.c \
		srcs/push_swap/ft_check_dup.c \
		srcs/push_swap/ft_check_sorted.c \
		srcs/push_swap/ft_error_print.c \
		srcs/push_swap/ft_free.c \
		srcs/push_swap/list_utils.c \
		srcs/push_swap/list_utils_2.c \
		srcs/push_swap/ft_parse_string.c \
		srcs/push_swap/ft_args_to_node.c \
		srcs/push_swap/ft_handle_args.c \
		srcs/push_swap/ft_sort_big.c \
		srcs/push_swap/ft_sort_three.c \
		srcs/push_swap/ft_rotate_type.c \
		
BONUS_SRC = srcs/checker/checker.c \
			srcs/checker/checker_utils.c \
			srcs/checker/get_next_line.c \
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}



.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
 
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} 
 

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
 
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} 
 

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus