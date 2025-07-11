/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 02:59:43 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/25 03:32:34 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index_a(a, c);
	if (i < ft_findpos(b, c))
		i = ft_findpos(b, c);
	return (i);
}

int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index_a(a, c))
		i = get_listsize(a) - ft_find_index_a(a, c);
	if ((i < (get_listsize(b) - ft_findpos(b, c))) && ft_findpos(b, c))
		i = get_listsize(b) - ft_findpos(b, c);
	return (i);
}

int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_findpos(b, c))
		i = get_listsize(b) - ft_findpos(b, c);
	i = ft_find_index_a(a, c) + i;
	return (i);
}

int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index_a(a, c))
		i = get_listsize(a) - ft_find_index_a(a, c);
	i = ft_findpos(b, c) + i;
	return (i);
}
