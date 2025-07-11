/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:33:25 by mhashir           #+#    #+#             */
/*   Updated: 2024/04/05 15:58:41 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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