/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/09 17:51:56 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>


// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Bureaucrat::Bureaucrat( void )
: 	name("John DOE"),
	grade(150)
{
	std::cout << "Bureaucrat default constructor executed" <<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
:	name(name),
	grade(grade)
{
	std::cout << "Bureaucrat default constructor executed" << std::endl;
	if (grade < 1)
	{
		grade = 1;
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		this->grade = 150;
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
:	name(other.name),
	grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor executed" << std::endl;
	if (other.grade < 0)
		throw GradeTooHighException();
	if (other.grade > 150)
		throw GradeTooLowException();
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

void	Bureaucrat::upGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
	{ 
		this->grade--;
		if (this->grade > 150)
			throw GradeTooLowException();
	}
}

void	Bureaucrat::downGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
	{
		this->grade++;
		if (this->grade < 1)
			throw GradeTooHighException();
	}
}


// ****************************************************************************
// overload of ostream operator
// ****************************************************************************

std::ostream & operator<<(std::ostream & o, Bureaucrat const & burct)
{
	o << burct.get_name() << ", bureaucrat grade " << burct.get_grade();
	return (o);
}

// ****************************************************************************
// ****************************************************************************
// Exceptions
// ****************************************************************************
// ****************************************************************************

Bureaucrat::GradeTooHighException::GradeTooHighException( void )
{}

Bureaucrat::GradeTooHighException::GradeTooHighException( const GradeTooHighException & gthe )
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void )
{}
	
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is to high (< 1)");
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void )
{}

Bureaucrat::GradeTooLowException::GradeTooLowException( const GradeTooLowException & gthe )
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void )
{}
	
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is to low (> 150)");
}