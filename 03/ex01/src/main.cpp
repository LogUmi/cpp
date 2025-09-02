/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 18:56:18 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	write_clap(ClapTrap & a)
{
	std::cout	<< a.get_name() << " is ClapTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

void	write_scav(ScavTrap & a)
{
	std::cout	<< a.get_name() << " is ScavTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

int	main(void)
{
	std::cout << "\033[34m*** Constructing ***\033[0m" << std::endl << std::endl;
	ClapTrap	a("One");
	write_clap	(a);
	ScavTrap	b("Two");
	write_scav	(b);
	ScavTrap	c("Three");
	write_scav 	(c);
	std::cout 	<< std::endl << "*** Testing member functions ***" 
				<< std::endl;
	std::cout << std::endl << "** ClapTrap **" << std::endl;
	a.attack("some other ClapTrap");
	a.takeDamage(5);
	a.beRepaired(3);
	a.beRepaired(5);
	a.takeDamage(100);
	a.attack("some other other ClapTrap");
	a.beRepaired(50);
	{
		std::cout 	<< std::endl << "* Intermediary ClapTrap constructor testing *"
					<< std::endl;
		ClapTrap f;
		f = a;
		std::cout << "assignation de a : ";
		write_clap(f);
		ClapTrap g(a);
		std::cout << "copie de a : ";
		write_clap(g);
	}
	std::cout << std::endl << "** ScavTrap **" << std::endl;
	b.beRepaired(30);
	b.guardGate();
	for (int i = 0; i < 52; i++)
		b.attack("everyone");
	b.guardGate();
	b.beRepaired(100);
	b.takeDamage(100);
	b.guardGate();
	c.takeDamage(100);
	c.guardGate();
	{
		std::cout 	<< std::endl << "* Intermediary ScavTrap constructor testing *"
					<< std::endl;
		ScavTrap	f;
		f = b;
		std::cout << "assignation de b : ";
		write_scav(f);
		ScavTrap g(c);
		std::cout << "copie de c : ";
		write_scav(g);
	}
	std::cout 	<< std::endl << "\033[31m*** Deconstructing ***\033[0m"
				<< std::endl;
	return (0);
}
