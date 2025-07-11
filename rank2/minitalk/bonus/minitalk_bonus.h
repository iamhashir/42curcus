/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:59:45 by mhashir           #+#    #+#             */
/*   Updated: 2024/04/05 16:01:12 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_atoi(const char *s);
void	ft_putnbr(long n, char *base, int i, int *std_output);

typedef struct init
{
	int		i;
	char	c;
}			t_init;

#endif 