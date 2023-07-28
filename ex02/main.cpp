/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:01:22 by mdoll             #+#    #+#             */
/*   Updated: 2023/07/19 12:01:22 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include "FragTrap.hpp"

int main() {
	std::cout << "---------- Constructing ---------\n" << std::endl;
	FragTrap fragTrap("frag");
	ScavTrap scavTrap("scav");
	ClapTrap clapTrap("clap");

	std::cout << "\n---------- Testing functions ---------\n" << std::endl;
	fragTrap.attack("target");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();
	std::cout << fragTrap.getHp() << " hp" << std::endl;
	std::cout << fragTrap.getEnergy() << " energy" << std::endl;
	std::cout << fragTrap.getDmg() << " dmg" << std::endl;
	std::cout << fragTrap.getName() << " name" << std::endl;
	fragTrap.takeDamage(100);
	std::cout << fragTrap.getHp() << " hp" << std::endl;
	fragTrap.beRepaired(100);
	std::cout << fragTrap.getHp() << " hp" << std::endl;
	std::cout << fragTrap.getEnergy() << " energy" << std::endl;
	fragTrap.highFivesGuys();
	std::cout << "\n---------- Deconstructing ---------\n" << std::endl;
}