/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:39:10 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/25 04:07:04 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void		args_to_node(char **argv, t_stack **stack_a);
void		ft_add_node(t_stack **stack, t_stack *stack_new);
int			count_words(const char *str, char c);
t_stack		*ft_stack_new(int content);
int			handle_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			sign(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
t_stack		*get_lastlist(t_stack *lst);
int			space(int c);
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_sa(t_stack **a, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rrr_sub(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);
int			get_listsize(t_stack *lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_findpos(t_stack *a, int nbr);
int			ft_find_index_b(t_stack *stack_b, int nbr_push);
int			ft_find_index_a(t_stack *a, int nbr);
void		ft_sort(t_stack **stack_a);
int			ft_checksorted(t_stack *stack_a);
void		ft_sort_three(t_stack **stack_a);
t_stack		*ft_parse(int argc, char **argv);
t_stack		*ft_parse_string(char **argv);
void		ft_freestr(char **lst);
int			ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb(t_stack *a, t_stack *b, int c);
int			ft_rotate_type_ab(t_stack *a, t_stack *b);
int			ft_rotate_type_ba(t_stack *a, t_stack *b);
int			ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void		ft_rrb(t_stack **b, int j);
void		ft_check_sub(t_stack **a, t_stack **b, char *line);
char		*ft_check(t_stack **a, t_stack **b, char *line);
void		ft_checker_sub(t_stack **a, t_stack **b, char *line);
t_stack		*ft_process(int argc, char **argv);
void		ft_sb(t_stack **b, int j);
void		ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack		*process_remaining_characters_process(char **argv);
void		ft_error_ch(void);
void		ft_error(void);
void		ft_free(t_stack **lst);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);

#endif