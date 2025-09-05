/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/05 18:18:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>


// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Bureaucrat::Bureaucrat( void )
: 	name("John DOE"),
	grade(150)
{
	std::cout << "Bureaucrat default constructor executed" <<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
:	name(name),
	grade(grade)
{
	std::cout << "Bureaucrat default constructor executed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
:	name(other.name),
	grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor executed" << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor executed" << std::endl;	
}


// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& burct )
{	
	std::cout << "Bureaucrat assignation overload executed" << std::endl;	
	if (this != &burct)
	{
		this->grade = burct.grade;
	}
}


// ****************************************************************************
// member functions
// ****************************************************************************

std::string		Bureaucrat::get_name( void ) const
{
	return (this->name);
}

unsigned int	Bureaucrat::get_grade( void ) const
{
	return	(this->grade);
}


// ****************************************************************************
// overload of ostream operator
// ****************************************************************************

std::ostream & operator<<(std::ostream & o, Bureaucrat const & burct)
{
	o << burct.get_name() << ", bureaucrat grade " << burct.get_grade();
	return (o)
}