/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:31:44 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 02:20:27 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string:\t" << &string << std::endl;
	std::cout << "Address of stringPTR:\t" << &stringPTR << std::endl;
	std::cout << "Address of stringREF:\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string:\t\t" << string <<std::endl;
	std::cout << "Value pointed to by stringPTR:\t" << stringPTR <<std::endl;
	std::cout << "Value of stringREF:\t\t" << stringREF <<std::endl;

	return (EXIT_SUCCESS);
}