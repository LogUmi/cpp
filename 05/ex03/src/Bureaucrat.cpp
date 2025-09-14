/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/14 12:44:16 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Bureaucrat::Bureaucrat( void )
: 	name("John DOE"),
	grade(150)
{
	//std::cout << "Bureaucrat default constructor executed" <<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
:	name(name),
	grade(grade)
{
	//std::cout << "Bureaucrat copy constructor executed" << std::endl;
	if (grade < 1)
	{
		//grade = 1;
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		//this->grade = 150;
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
:	name(other.name),
	grade(other.grade)
{
	//std::cout << "Bureaucrat copy constructor executed" << std::endl;
	if (other.grade < 1)
		throw GradeTooHighException();
	if (other.grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat( void )
{
	//std::cout << "Bureaucrat destructor executed" << std::endl;	
}


// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& burct )
{	
	//std::cout << "Bureaucrat assignation overload executed" << std::endl;	
	if (this != &burct)
	{
		this->grade = burct.grade;
	}
	return (*this);
}


// ****************************************************************************
// member functions
// ****************************************************************************

const std::string		Bureaucrat::get_name( void ) const
{
	return (this->name);
}

int	Bureaucrat::get_grade( void ) const
{
	return	(this->grade);
}

void	Bureaucrat::upGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw GradeTooHighException();
	else if (this->grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::downGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw GradeTooLowException();
	else if (this->grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::signForm( AForm & toSign )
{
	try
	{
		toSign.beSigned(*this);
		std::cout << *this << " signed " << toSign << std::endl;
	}
	catch( const AForm::GradeTooLowException & e )
	{
		std::cout << *this << " couldn't sign " << toSign << " because " << e.what() <<std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form ) const
{
	try 
	{
		form.execute( *this );
		std::cout << *this << " executed " << form << std::endl;
	}
	catch(const AForm::GradeTooLowException & e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() <<std::endl;
	}
	catch(const AForm::FormNotSignedException & e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() <<std::endl;
	}
	catch(const ShrubberyCreationForm::FileIssueException & e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() <<std::endl;
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is to high (< 1)");
}
	
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is to low (> 150)");
}