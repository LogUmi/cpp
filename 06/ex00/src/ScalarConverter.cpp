/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:59 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/18 15:00:20 by lgerard          ###   ########.fr       */
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

char	ScalarConverter::get_char( int val )
{
	if (val >=0 && val < 256)
		return (static_cast<char>(val));
	return (static_cast<char>(255));
}
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
	ptr = is_digit( arg, 0 );
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
	std::string	is = "";
	float		f = 0.0;
	std::string	fs = "";
	double		d = 0.0;
	std::string ds = "";
	int 		status = 0;
	
	status	= is_what( arg );
	switch (status)
	{
		case 0: // single char
			c = arg[0];
			i = static_cast<int>(c);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case 1: // int
			try
			{
				i = std::stoi( arg, NULL, 10);
				c = get_char(i);
			}
			catch(const std::out_of_range& e)
			{
				is = "overflow";
				static_cast<char>(255);
			}
			f = std::stof( arg, NULL );
			d = std::stod( arg, NULL );
			break ;
		case 2: // float
			f = std::stof( arg, NULL );
			if (f > static_cast<float>(INT_MAX) 
				|| f < static_cast<float>(INT_MIN))
			{
				i = static_cast<int>(f);
				c = get_char(i);
			}
			else
			{
				is = "impossible";
				c = static_cast<char>(255);
			}
			d = static_cast<double>(f);
			break ;
		case 3: // double
			d = std::stod( arg, NULL );
			if (d > static_cast<double>(INT_MAX) 
				|| f < static_cast<double>(INT_MIN))
			{
				i = static_cast<int>(d);
				c = get_char(i);
			}
			else
			{
				is = "impossible";
				c = static_cast<char>(255);
			}
			i = static_cast<int>(d);
			c = get_char(i);
			f = static_cast<float>(d);
			break ;
		case 4: // pseudo literal
			c = static_cast<char>(255);
			is = "impossible";
			try
			{
				f = std::stof( arg, NULL );
			}
			catch(const std::invalid_argument& e)
			{
				fs = "impossible";
			}
			try
			{
				d = std::stod( arg, NULL );
			}
			catch(const std::exception& e)
			{
				ds = "impossible";
			}
			break ;
		case 5: // other case
			c = static_cast<char>(255);
			is = "impossible";
			fs = "impossible";
			ds = "impossible";
	}
	if (c > 31 && c < 127)
		std::cout << "char: '" << c << "' " << status << std::endl;
	else if ((c >= 0 && c < 32 )|| c == 127)
		std::cout << "char: Non displayable" << status << std::endl;
	else
		std::cout << "char: impossible" << status << std::endl;
	if (is.empty())
		std::cout << "int: " << i << " " << status << std::endl;
	else
		std::cout << "int: " << is << status << std::endl;
	if (fs.empty())
		std::cout << "float: " << f << "f " << status << std::endl;
	else
		std::cout << "float: " << fs << status << std::endl;
	if (ds.empty())
		std::cout << "double: " << d << " " << status << std::endl;
	else
		std::cout << "double: " << ds << status << std::endl;
	return ;
}
