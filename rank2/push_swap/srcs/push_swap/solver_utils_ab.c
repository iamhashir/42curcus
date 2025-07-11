/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 05:41:11 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/25 03:36:14 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index_b(b, c);
	if (i < ft_findpos(a, c))
		i = ft_findpos(a, c);
	return (i);
}

int	ft_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index_b(b, c))
		i = get_listsize(b) - ft_find_index_b(b, c);
	if ((i < (get_listsize(a) - ft_findpos(a, c))) && ft_findpos(a, c))
		i = get_listsize(a) - ft_findpos(a, c);
	return (i);
}

int	ft_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_findpos(a, c))
		i = get_listsize(a) - ft_findpos(a, c);
	i = ft_find_index_b(b, c) + i;
	return (i);
}

int	ft_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index_b(b, c))
		i = get_listsize(b) - ft_find_index_b(b, c);
	i = ft_findpos(a, c) + i;
	return (i);
}
