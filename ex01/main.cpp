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

int main() {

	std::cout << "---------- Constructing ---------\n" << std::endl;
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");

	ScavTrap basic;
	ScavTrap bob("Bob");
	ScavTrap copyBob(bob);
	ScavTrap assignFred = ScavTrap("Fred");

	std::cout << "\n---------- Testing functions ---------\n" << std::endl;

	std::cout << "\n----- attacking -----\n" << std::endl;
	bob.attack("a tree");
	assignFred.attack("a rock");
	scav.attack("enemy");
	clap.attack("enemy");
	std::cout << "\n----- taking damage -----\n" << std::endl;
	bob.takeDamage(5);
	std::cout << "Bob has " << bob.getHp() << " HP left" << std::endl;
	bob.takeDamage(10);
	std::cout << "Bob has " << bob.getHp() << " HP left" << std::endl;
	scav.takeDamage(5);
	std::cout << "Scav has " << scav.getHp() << " HP left" << std::endl;
	clap.takeDamage(5);
	std::cout << "\n----- repairing -----\n" << std::endl;
	scav.beRepaired(40);
	std::cout << "ScavTrap " << scav.getName() << " has " << scav.getEnergy() << " energy points" << std::endl;
	clap.beRepaired(2);
	std::cout << "\n----- Gurad Gate -----\n" << std::endl;
	scav.guardGate();
	scav.guardGate();

	std::cout << "\n---------- Deconstructing ---------\n" << std::endl;
	return 0;
}