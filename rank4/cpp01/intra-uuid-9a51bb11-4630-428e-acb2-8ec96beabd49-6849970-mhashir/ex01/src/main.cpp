/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:31:55 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 00:31:56 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int		zombieAmount = 10;

	horde = zombieHorde(zombieAmount, "Horde Member");
	if (horde == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < zombieAmount; ++i)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(0, "Failed");
	return (EXIT_SUCCESS);
}