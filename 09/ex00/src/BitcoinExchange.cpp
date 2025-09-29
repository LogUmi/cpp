/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/29 02:21:47 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

BitcoinExchange::BitcoinExchange( void )
:	data(),
	value(0)
{
	std::memset(&time_s, 0, sizeof(time_s));
	std::memset(&tmps, 0, sizeof(tmps));
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & other )
:	data(other.data),
	time_s(other.time_s),
	value(other.value)
{
	std::memcpy(tmps, other.tmps, sizeof tmps);
}

BitcoinExchange::~BitcoinExchange( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange other )
{
	std::swap(this->data, other.data);
	std::swap(this->value, other.value);
	std::swap(this->time_s, other.time_s);
	std::swap(this->tmps, other.tmps);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void	BitcoinExchange::tmp_str_cpy(std::string & str, int n, int pos)
{
	if (n >= TMP_STR_LEN)
		throw std::out_of_range("Error: BitcoinExchange::tmps overflow - rise TMP_STR_LEN");
	str.copy(this->tmps, n, pos);
	tmps[n] = '\0';
}

size_t	BitcoinExchange::is_digit(std::string & str, int offs) const
{
	int	i = offs;

	while(static_cast<size_t>(i) < str.size() && str[i] > 47 && str[i] < 58)
		i++;
	if (static_cast<size_t>(i) == str.size())
		return (0);
	if (i == offs)
		return (-1);
	return (i);
}

size_t	BitcoinExchange:: is_date(std::string & str)
{
	int			offst = 0;
	int			poffst = 0;

	std::memset(&this->time_s, 0, sizeof(time_s));
	std::memset(&tmps, 0, sizeof(tmps));
	if ((offst = is_digit( str, offst )) < 1)
		throw std::runtime_error("Error: bad input => " + str);
	tmp_str_cpy(str, offst - poffst, poffst);
	time_s.tm_year = atoi(tmps);
	if (time_s.tm_year < 1900 || str[offst] != '-')
		throw std::runtime_error("Error: bad input => " + str);
	poffst = ++offst;
	if ((offst = is_digit( str, offst )) < 1)
		throw std::runtime_error("Error: bad input => " + str);
	tmp_str_cpy(str, offst - poffst, poffst);
	time_s.tm_mon = atoi(tmps) - 1;
	if (time_s.tm_mon < 0 || time_s.tm_mon > 11 || str[offst] != '-')
		throw std::runtime_error("Error: bad input => " + str);
	poffst = ++offst;
	if ((offst = is_digit( str, offst )) < 1)
		throw std::runtime_error("Error: bad input => " + str);
	tmp_str_cpy(str, offst - poffst, poffst);
	time_s.tm_mday = atoi(tmps);
	if (time_s.tm_mon < 1 || time_s.tm_mon > 31 || !(str[offst] == ',' || str[offst] == '|'))
		throw std::runtime_error("Error: bad input => " + str);
	return (++offst);
}

void	BitcoinExchange::is_value(std::string & str, int offst)
{
	int	poffst = offst;

	std::memset(&this->time_s, 0, sizeof(time_s));
	std::memset(&tmps, 0, sizeof(tmps));
	if (str[offst] == '-' || str[offst] == '+')
	{
		if (str[offst] == '-')
			throw std::runtime_error("Error: not a positive number.");
		poffst = ++offst;
	}
	if ((offst = is_digit( str, offst )) < 0)
		throw std::runtime_error("Error: bad input => " + str);
	if (offst == 0)
	{
		tmp_str_cpy(str, static_cast<int>(str.size()) - poffst, poffst);
		this->value = strtof(tmps, NULL);
		return ;
	}
	if (str[offst] == '.')
	{
		if (str[offst] == '-')
			throw std::runtime_error("Error: not a positive number.");
		offst++;
	}
	else if (str[offst] == 'e' ||)
}

void	BitcoinExchange::line_integration( std::string str)
{
	try
	{
		int	offst = is_date(str);
		is_value(str, offst);
	}
	catch(const std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	BitcoinExchange::seek_line( std::string str )
{
	try
	{
		int	offst = is_date(str);
		is_value(str, offst);
	}
	catch(const std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
}
