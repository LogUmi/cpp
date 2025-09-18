/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:59 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/18 18:44:44 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************
Serializer::Serializer ( void )
{
	//std::cout << "Serializer default constructor executed" <<std::endl;
	return ;
}

Serializer::Serializer (const Serializer & other)
{
	static_cast<void>(other);
	//std::cout << "Serializer copy constructor executed" <<std::endl;
	return ;
}

Serializer::~Serializer ( void )
{
		//std::cout << "Serializer destructor executed" <<std::endl;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Serializer & Serializer::operator=( const Serializer & other )
{
	static_cast<void>(other);
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

uintptr_t Serializer::serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data*>(raw));
}