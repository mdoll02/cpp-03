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
#include <iostream>

int main() {
	ClapTrap basic;
	ClapTrap bob("Bob");
	ClapTrap copyBob(bob);
	ClapTrap assignBob = bob;

	bob.attack("a tree");
	bob.takeDamage(5);
	std::cout << "Bob has " << bob.getHp() << " HP left" << std::endl;
	bob.takeDamage(10);
	std::cout << "Bob has " << bob.getHp() << " HP left" << std::endl;
	bob.beRepaired(6);
	std::cout << "Bob has " << bob.getHp() << " HP left" << std::endl;
	std::cout << "Bob has " << bob.getEnergy() << " Energy left" << std::endl;
	bob.attack("a bush");
	bob.attack("a lake");
	bob.attack("a fly");
	bob.attack("a river");
	basic.attack("piece of bread");
}