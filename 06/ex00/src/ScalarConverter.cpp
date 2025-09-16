/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:59 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/16 21:15:16 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************
ScalarConverter::ScalarConverter ( void )
{
	//std::cout << "ScalarConverter default constructor executed" <<std::endl;
	return ;
}

ScalarConverter::ScalarConverter (const ScalarConverter & other)
{
	static_cast<void>(other);
	//std::cout << "ScalarConverter copy constructor executed" <<std::endl;
	return ;
}

ScalarConverter::~ScalarConverter ( void )
{
		//std::cout << "ScalarConverter destructor executed" <<std::endl;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

ScalarConverter & ScalarConverter::operator=( const ScalarConverter & other )
{
	static_cast<void>(other);
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	ScalarConverter::convert( const std::string & literal )
{
	
	return ;
}
