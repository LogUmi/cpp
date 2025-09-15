/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/15 17:53:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main( void )
{
	srand(time(NULL)); // initialisation unique pour randomisation de robotomy
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "ex02 Forms basic tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	Bureaucrat b1("Big Boss", 1);
	std::cout << b1 << " created" << std::endl;
	Intern someRandomIntern;
	std::cout << "someRandomIntern created" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "ShrubberyCreationForm tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	try
	{
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		b1.signForm( *scf );
		b1.executeForm( *scf );
		delete scf;
	}
	catch ( const Intern::WrongFormException & e )
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Intern could'nt create the form : " << e.what() << std::endl;
	}
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "RobotomyRequestForm tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	try
	{
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b1.signForm( *rrf );
		b1.executeForm( *rrf );
		delete rrf;
	}
	catch ( const Intern::WrongFormException & e )
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Intern could'nt create the form : " << e.what() << std::endl;
	}
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	try
	{
		AForm* pdf = someRandomIntern.makeForm("presidential pardon", "Bender");
		b1.signForm( *pdf );
		b1.executeForm( *pdf );
		delete pdf;
	}
	catch ( const Intern::WrongFormException & e )
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Intern could'nt create the form : " << e.what() << std::endl;
	}
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "EternalLifeRequest" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	try
	{
		AForm* elr = someRandomIntern.makeForm("eternal life", "Bender");
		b1.signForm( *elr );
		b1.executeForm( *elr );
		delete elr;
	}
	catch ( const Intern::WrongFormException & e )
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Intern could'nt create the form : " << e.what() << std::endl;
	}
    return (0);
}