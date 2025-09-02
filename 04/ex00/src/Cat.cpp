/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/11 23:10:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Cat::Cat( void )
 :	Animal ( "Cat" ),
 	name("Kitty")
{
	std::cout 	<< "Cat default constructor called for " 
				<< this->name << std::endl;
	return ;
}

Cat::Cat( std::string id ) 
: 	Animal( "Cat" ),
	name( id )
{
	std::cout << "Cat named object constructor called for " << name << std::endl;
	return ;
}

Cat::Cat( const Cat & ct)
 :	Animal( "Cat" ),
	name( "copy" )
{
	std::cout << "Cat copy constructor called for " << name << std::endl;
	*this = ct;
	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called for " << name << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Cat&	Cat::operator=(const Cat& ct)
{
	std::cout 	<< "Cat copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		this->name = ct.name;
		Animal::type = ct.getType();
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	Cat::makeSound( void ) const
{
	std::cout << "This Cat makes a Cat sound: MEEEEOOOOOOW " << std::endl;
}

std::string	Cat::getName( void ) const
{
	return (this->name);
}