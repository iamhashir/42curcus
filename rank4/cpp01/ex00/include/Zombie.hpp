/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 03:50:51 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 00:15:22 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
 		Zombie(std::string s);
 		~Zombie();
 		void	announce();

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
