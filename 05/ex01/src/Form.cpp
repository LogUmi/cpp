#include <string>
#include <iostream>
#include <ostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************
Form::Form ( void )
:	name("sheet"),
	signing(false),
	signing_grade(1),
	executing_grade(150)
{
	//std::cout << "Form default constructor executed" <<std::endl;
}

Form::Form (const Form & other)
:	name(other.name),
	signing(other.signing),
	signing_grade(other.signing_grade),
	executing_grade(other.executing_grade)
{
	//std::cout << "Form copy constructor executed" <<std::endl;
	if (this->signing_grade > 150 || this->executing_grade > 150)
		throw GradeTooLowException();
	if (this->signing_grade < 1 || this->executing_grade < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form(std::string name, int signing_grade, int executing_grade)
:	name( name ),
	signing( false ),
	signing_grade( signing_grade ),
	executing_grade( executing_grade)
{
	//std::cout << "Form general constructor executed" <<std::endl;
	if (this->signing_grade > 150 || this->executing_grade > 150)
		throw GradeTooLowException();
	if (this->signing_grade < 1 || this->executing_grade < 1)
		throw GradeTooHighException();
	return ;
	
}

Form::~Form ( void )
{
		//std::cout << "Form destructor executed" <<std::endl;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Form & Form::operator=(const Form & other)
{
	if (this != &other)
		this->signing = other.signing;
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

const std::string Form::get_name ( void ) const
{
	return ( this->name );
}

bool	Form::get_signing( void ) const
{
	return ( this->signing );
}

int	Form::get_signing_grade( void ) const
{
	return ( this->signing_grade );
}

int	Form::get_executing_grade ( void ) const
{
	return ( this->executing_grade );
}

void	Form::beSigned(const Bureaucrat & burct)
{
	if (burct.get_grade() > this->signing_grade)
		throw GradeTooLowException();
	else
		this->signing = true;
	return ;
	}

// ****************************************************************************
// overload of ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream & o, const Form & paper)
{
	o 	<< "Form " << paper.get_name() << " (signing: " << paper.get_signing() 
		<< " / signing grade: " << paper.get_signing_grade() 
		<< " / executing grade: " << paper.get_executing_grade() << ")";
	return (o);
}

// ****************************************************************************
// ****************************************************************************
// Exceptions
// ****************************************************************************
// ****************************************************************************

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high");
}