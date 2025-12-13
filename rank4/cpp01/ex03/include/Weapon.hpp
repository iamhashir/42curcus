/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:32:50 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 02:47:18 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <string>

class Weapon {
private:
    std::string _type;

public:
    explicit Weapon(const std::string& type);
    const std::string& getType() const; 
    void setType(const std::string& type);
};

