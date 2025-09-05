/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/05 17:40:22 by lgerard          ###   ########.fr       */
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
	std::cout << "Bureaucrat default contructor executed";
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
:	name(name),
	grade(grade)
{
		std::cout << "Bureaucrat default contructor executed";
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor executed";	
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& burct )
{
	this->name = burct.name;
	this->grade = burct.grade;
	
}
