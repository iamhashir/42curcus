/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:33:46 by mhashir           #+#    #+#             */
/*   Updated: 2024/04/05 15:40:56 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	int		shift;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i])
		{
			shift = 8;
			while (shift-- > 0)
			{
				if ((argv[2][i] >> shift) & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(30);
			}
		}
	}
	else
		write(1, "~~Usage pid and message~~\n", 20);
}
