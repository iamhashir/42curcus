/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:34:52 by mhashir           #+#    #+#             */
/*   Updated: 2024/04/05 16:24:15 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_init	g_t;

void	init_by_zero(void)
{
	g_t.c = (char)255;
	g_t.i = 0;
}

void	handler1(int signum, siginfo_t *info, void *sheet)
{
	int static	pid;

	(void) sheet;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		init_by_zero();
	}
	if (signum == SIGUSR1)
		g_t.c |= (0x80 >> g_t.i++);
	else if (signum == SIGUSR2)
		g_t.c ^= (0x80 >> g_t.i++);
	if (g_t.c == '\0')
		kill(info->si_pid, SIGUSR1);
	if (g_t.i == 8)
	{
		ft_putchar(g_t.c);
		init_by_zero();
	}
}

int	main(void)
{
	int					a;
	struct sigaction	new_act1;

	new_act1.sa_sigaction = &handler1;
	new_act1.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid(), "0123456789", 10, &a);
	sigaction(SIGUSR1, &new_act1, NULL);
	sigaction(SIGUSR2, &new_act1, NULL);
	while (1)
		pause();
}
