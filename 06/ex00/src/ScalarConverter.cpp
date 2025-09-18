/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:59 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/18 18:44:44 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
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

int	ScalarConverter::is_digit( const std::string & arg, int ptr )
{
	int	cptr = ptr;

	while (arg[cptr] > 47 && arg[cptr] < 58)
		cptr++;
	if (static_cast<size_t>(cptr) == arg.size())
		return (0);
	if (cptr == ptr)
		return (-1);
	else
		return (cptr);
}

int	ScalarConverter::is_what( const std::string & arg )
{
	int		ptr = 0;

	// ******* single char test *******
	if (arg.size() == 1)
	{
		if (arg[0] > 47 && arg[0] < 58)
			return (1);
		else
			return (0);
	}
	// ******* pseudo literal test ********
	if (arg == "nan" || arg == "nanf" || arg == "inff" || arg == "inf" || arg == "-inff"
			|| arg == "-inf" || arg == "+inff" || arg == "+inf")
		return (4);
	// ******* int test *******
	if(arg[ptr] == '-' || arg[ptr] == '+')
		ptr++;
	ptr = is_digit( arg, ptr );
	if (ptr == -1)
		return (5);
	if (ptr == 0)
		return (1);
	// ****** float or double test *******
	// *** numbers under 1 test ***
	if (arg[ptr] == '.')
	{
		ptr = is_digit(arg, ptr + 1);
		if (ptr == -1)
			return (5);
		if (ptr == 0)
			return (3);
		if (arg[ptr] == 'f' && arg.size() == static_cast<size_t>(ptr + 1))
			return (2);
		// *** scientific exponent test ***
		if (arg[ptr] == 'e' || arg[ptr] == 'E')
		{
			ptr++;
			if ((arg[ptr] == '+' || arg[ptr] == '-')
					&& static_cast<size_t>(ptr) < arg.size())
				ptr++;
			if (static_cast<size_t>(ptr) < arg.size())
			{
				ptr = is_digit(arg, ptr);
				if (ptr == -1)
					return (5);
				if (ptr == 0)
					return (3);
				if (arg[ptr] == 'f' && arg.size() == static_cast<size_t>(ptr + 1))
					return (2);
				return (5);
			}
			return (5);
		}
		return (5);
	}
	// *** non scientific exponent test ***
	if (arg[ptr] == 'e' || arg[ptr] == 'E')
	{
		ptr++;
		if ((arg[ptr] == '+' || arg[ptr] == '-')
			&& static_cast<size_t>(ptr) < arg.size())
			ptr++;
		if (static_cast<size_t>(ptr) < arg.size())
		{
			ptr = is_digit(arg, ptr + 1);
			if (ptr == -1)
				return (5);
			if (ptr == 0)
				return (3);
			if (arg[ptr] == 'f' && arg.size() == static_cast<size_t>(ptr + 1))
				return (2);
			return (5);
		}
		return (5);
	}
	return (5);
}

void	ScalarConverter::convert( const std::string & arg )
{
	char		c = 0;
	int			i = 0;
	long		il = 0;
	std::string	is = "";
	float		f = 0.0;
	std::string	fs = "";
	double		d = 0.0;
	std::string ds = "";
	
	switch (is_what(arg))
	{
		case 0:
		// ******* single char *******
			c = arg[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case 1: 
		// ******* int ********
			il = atol(arg.c_str());
			if (il > INT_MAX || il < INT_MIN)
			{
				is = "impossible";
				c = static_cast<char>(255);
			}
			else
			{
				i = static_cast<int>(il);
				//c = get_char(i);
				c = static_cast<char>(i);	
			}
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case 2:
		// ******* float ********
			f = strtof(arg.c_str(), NULL);
			if (f > static_cast<float>(INT_MAX) 
				|| f < static_cast<float>(INT_MIN))
			{
				is = "impossible";
				c = static_cast<char>(255);	
			}
			else
			{
				i = static_cast<int>(f);
				c = static_cast<char>(f);
			}
			d = static_cast<double>(f);
			break ;
		case 3:
		// ******* double *******
			d = strtod(arg.c_str(), NULL);
			if (d > static_cast<double>(INT_MAX) 
				|| f < static_cast<double>(INT_MIN))
			{
				is = "impossible";
				c = static_cast<char>(255);	
			}
			else
			{
				i = static_cast<int>(d);
				c = static_cast<char>(d);
			}
			f = static_cast<float>(d);
			break ;
		case 4:
		// ******* pseudo literal *******
			c = static_cast<char>(255);
			is = "impossible";
			if (arg == "nanf" || arg == "inff" || arg == "-inff" || arg == "+inff")
			{
				f = strtof( arg.c_str(), NULL );
				d = static_cast<double>(f);
			}
			else
			{
				d = strtod( arg.c_str(), NULL );
				f = static_cast<float>(d);
			}
			break ;
		case 5: 
		// ******* other case *******
			c = static_cast<char>(255);
			is = "impossible";
			fs = "impossible";
			ds = "impossible";
	}
	// ******* print results *******
	if (c > 31 && c < 127)
		std::cout << "char: '" << c << "' " << std::endl;
	else if ((c >= 0 && c < 32 )|| c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (is.empty())
		std::cout << "int: " << i << " " << std::endl;
	else
		std::cout << "int: " << is << std::endl;
	if(fabs(f - static_cast<int>(f)) < 1e-6)
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout.unsetf(std::ios::fixed);
	if (fs.empty())
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << fs << std::endl;
	if(fabs(d - static_cast<int>(d)) < 1e-6)
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout.unsetf(std::ios::fixed);
	if (ds.empty())
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << ds << std::endl;
	std::cout.unsetf(std::ios::fixed);
	return ;
}
