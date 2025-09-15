/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:21:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/15 17:39:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Intern::Intern ( void )
{
	//std::cout << "Intern default constructor executed" <<std::endl;
	return ;
}

Intern::Intern ( Intern const & other )
{
	(void) other;
	//std::cout << "Intern copy constructor executed" <<std::endl;
	return ;
}

Intern::~Intern ( void )
{
	//std::cout << "Intern destructor executed" <<std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Intern & Intern::operator=( const Intern & other )
{
	(void)other;
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

AForm* 	Intern::createShrubbery( std::string const & target )
{
	return ( new ShrubberyCreationForm( target ) );
}

AForm*		Intern::createRobotomy( std::string const & target )
{
	return ( new RobotomyRequestForm( target ) );
}

AForm*		Intern::createPresidential( std::string const & target )
{
	return (new PresidentialPardonForm( target ) );
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string requests[4] =  
	{"shrubbery creation", "robotomy request", "presidential pardon", ""};
	AForm* (Intern::*creators[3])(std::string const&) = 
	{&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	int i = 0;
    AForm* form = NULL;

	while (!requests[i].empty())
	{
		if (name == requests[i])
		{
			form = (this->*creators[i])( target );
			break ;
		}
		i++;
	}
	if (requests[i].empty())
		throw WrongFormException();
	std::cout << "Intern creates " << form->get_name() << std::endl;
	return (form);
}

// ****************************************************************************
// ****************************************************************************
// Exceptions
// ****************************************************************************
// ****************************************************************************

const char * Intern::WrongFormException::what( void ) const throw()
{
	return ("Intern can't create a form with an unknown name");
}
