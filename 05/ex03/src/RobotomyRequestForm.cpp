/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:04:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/14 14:10:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************
RobotomyRequestForm::RobotomyRequestForm ( void )
:	AForm( "RobotomyRequestForm default", 72, 45 ),
	target( "Someone" )
{
	//std::cout << "RobotomyRequestForm default constructor executed" <<std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm & other )
:	AForm( other ),
	target(other.target)
{
	//std::cout << "RobotomyRequestForm copy constructor executed" <<std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
:	AForm( "RobotomyRequestForm", 72, 45 ),
	target( target )
{
	//std::cout << "RobotomyRequestForm general constructor executed" <<std::endl;
	return ;
	
}

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
		//std::cout << "RobotomyRequestForm destructor executed" <<std::endl;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
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

void	RobotomyRequestForm::execute( const Bureaucrat & executor ) const
{
	try
	{
		this->is_Executable(executor);
		std::cout << "*** drilling noises ***" << std::endl;
		if (rand() % 2)
			std::cout << target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "robotomy failed on " << target << std::endl;
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
