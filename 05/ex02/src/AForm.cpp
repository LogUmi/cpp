/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:52:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/12 13:53:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************
AForm::AForm ( void )
:	name( "sheet" ),
	signing( false ),
	signing_grade( 1 ),
	executing_grade( 150 )
{
	//std::cout << "AForm default constructor executed" <<std::endl;
}

AForm::AForm (const AForm & other)
:	name( other.name ),
	signing( other.signing ),
	signing_grade( other.signing_grade ),
	executing_grade( other.executing_grade )
{
	//std::cout << "AForm copy constructor executed" <<std::endl;
	if (this->signing_grade > 150 || this->executing_grade > 150)
		throw GradeTooLowException();
	if (this->signing_grade < 1 || this->executing_grade < 1)
		throw GradeTooHighException();
	return ;
}

AForm::AForm( std::string name, int signing_grade, int executing_grade )
:	name( name ),
	signing( false ),
	signing_grade( signing_grade ),
	executing_grade( executing_grade )
{
	//std::cout << "AForm general constructor executed" <<std::endl;
	if (this->signing_grade > 150 || this->executing_grade > 150)
		throw GradeTooLowException();
	if (this->signing_grade < 1 || this->executing_grade < 1)
		throw GradeTooHighException();
	return ;
	
}

AForm::~AForm ( void )
{
		//std::cout << "AForm destructor executed" <<std::endl;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

AForm & AForm::operator=(const AForm & other)
{
	if (this != &other)
		this->signing = other.signing;
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

const std::string AForm::get_name ( void ) const
{
	return ( this->name );
}

bool	AForm::get_signing( void ) const
{
	return ( this->signing );
}

int	AForm::get_signing_grade( void ) const
{
	return ( this->signing_grade );
}

int	AForm::get_executing_grade ( void ) const
{
	return ( this->executing_grade );
}

void	AForm::beSigned( const Bureaucrat & burct )
{
	if (burct.get_grade() > this->signing_grade)
		throw GradeTooLowException();
	else
		this->signing = true;
	return ;
}

void	AForm::is_Executable( Bureaucrat const & executor ) const
{
	if (this->signing == false)
		throw FormNotSignedException();
	if (executor.get_grade() > this->executing_grade )
		throw GradeTooLowException();
}

// ****************************************************************************
// overload of ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream & o, const AForm & paper)
{
	std::string	s_status = "false";

	if (paper.get_signing() == true)
		s_status = "true";
	o 	<< "AForm " << paper.get_name() << " (target: " << paper.get_target()
		<< " / signing: " << s_status 
		<< " / signing grade: " << paper.get_signing_grade() 
		<< " / executing grade: " << paper.get_executing_grade() << ")";
	return (o);
}

// ****************************************************************************
// ****************************************************************************
// Exceptions
// ****************************************************************************
// ****************************************************************************

const char* AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low");
}

const char* AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high");
}

const char* AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Form is not signed");
}
