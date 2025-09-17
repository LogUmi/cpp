/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:59 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/17 17:56:55 by lgerard          ###   ########.fr       */
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

void	ScalarConverter::convert( const std::string & arg )
{
	char	c = 0;
	int		i = 0;
	float	f = 0.0;
	double	d = 0.0;
	int 	status[4] = {0, 0, 0, 0};
	
	// ********** char section **********
	if( arg.size() > 1 )
		status[0] = 2;
	else
		c = arg[0];
	// ********** int section **********
	try
	{
		i = std::stoi( arg, NULL, 10);
	}
	catch(const std::invalid_argument& e)
	{
		status[1] = 2;
	}
	catch(const std::out_of_range& e)
	{
		status[1] = 2;
	}
	if (status[0] != 0 && status[1] == 0)
	{
		if (i < 32 || i == 127)
			status[0] = 1;
		else if ( i < 127)
		{
			c = static_cast<char>(i);
			status[0] = 0;
		}
		else
			status[0] = 2;	
	}
	// ********** float section **********
	try
	{
		f = std::stof( arg, NULL );
	}
	catch(const std::invalid_argument& e)
	{
		status[1] = 2;
	}
	catch(const std::out_of_range& e)
	{
		status[1] = 1;
	}
	
	// ********** double section **********
	try
	{
		d = std::stod( arg, NULL );
	}
	catch(const std::invalid_argument& e)
	{
		status[1] = 2;
	}
	catch(const std::out_of_range& e)
	{
		status[1] = 1;
	}


	
	return ;
}
