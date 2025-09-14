/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:04:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/14 13:00:00 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************
PresidentialPardonForm::PresidentialPardonForm ( void )
:	AForm( "PresidentialPardonForm default", 25, 5 ),
	target( "Someone" )
{
	//std::cout << "PresidentialPardonForm default constructor executed" <<std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm & other )
:	AForm( other ),
	target(other.target)
{
	//std::cout << "PresidentialPardonForm copy constructor executed" <<std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
:	AForm( "PresidentialPardonForm", 25, 5 ),
	target( target )
{
	//std::cout << "PresidentialPardonForm general constructor executed" <<std::endl;
	return ;
	
}

PresidentialPardonForm::~PresidentialPardonForm ( void )
{
		//std::cout << "PresidentialPardonForm destructor executed" <<std::endl;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	PresidentialPardonForm::execute( const Bureaucrat & executor ) const
{
	try
	{
		this->is_Executable(executor);
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const AForm::GradeTooLowException & e)
	{
		throw ;
	}
	catch(const AForm::FormNotSignedException & e)
	{
		throw ;
	}
	return ;
}
