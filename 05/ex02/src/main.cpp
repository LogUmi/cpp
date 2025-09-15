/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/15 16:40:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

int main( void )
{
	srand(time(NULL)); // initialisation unique pour randomisation de robotomy
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "ex03 Forms basic tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	Bureaucrat b1("Big Boss", 1);
	std::cout << b1 << " created" << std::endl;
	Bureaucrat b25("Little Boss", 25);
	std::cout << b25 << " created" << std::endl;
	Bureaucrat b150("Little Hand", 150);
	std::cout << b150 << " created" << std::endl;
	ShrubberyCreationForm tree("home"); // sign 145 exec 137
	std::cout << tree << " created" << std::endl;
	RobotomyRequestForm robot("someone"); // sign 72 exec 45
	std::cout << robot << " created" << std::endl;
	PresidentialPardonForm pardon("everybody"); // sign 25 exec 5
	std::cout << pardon << " created" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "ShrubberyCreationForm tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	b1.executeForm(tree);
	b150.signForm(tree);
	b25.signForm(tree);
	b150.executeForm(tree);
	b25.executeForm(tree);
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "RobotomyRequestForm tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	b1.executeForm(robot);
	b150.signForm(robot);
	b25.signForm(robot);
	b150.executeForm(robot);
	std::cout << "****************************************************************************" << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		b25.executeForm(robot);
		std::cout << "****************************************************************************" << std::endl;
	}
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	b150.signForm(pardon);
	b25.signForm(pardon);
	b150.executeForm(pardon);
	b25.executeForm(pardon);
	b1.executeForm(pardon);
    return (0);
}