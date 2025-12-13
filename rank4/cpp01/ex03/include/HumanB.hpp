/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:32:54 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 02:48:54 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon*     _weapon; 

public:
    explicit HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};
