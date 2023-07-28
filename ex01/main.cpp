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

int main() {
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");

	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(5);

	scav.attack("enemy");
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.guardGate();
	return 0;
}