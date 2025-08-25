/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:32:47 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 02:45:05 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string _name;
    Weapon&     _weapon; 

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const; 
};
