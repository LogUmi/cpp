/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 16:38:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>

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
		throw std::out_of_range("BitcoinExchange::tmps overflow - rise TMP_STR_LEN");
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

size_t	BitcoinExchange::set_date(std::string & str)
{
	int			offst = 0;
	int			poffst = 0;

	std::memset(&this->time_s, 0, sizeof(time_s));
	std::memset(&tmps, 0, sizeof(tmps));
	if ((offst = is_digit( str, offst )) < 1)
		throw std::runtime_error("bad input => " + str);
	tmp_str_cpy(str, offst - poffst, poffst);
	time_s.tm_year = atoi(tmps) - 1900;
	if ((time_s.tm_year < -1900 || time_s.tm_year > 8099) || str[offst] != '-')
		throw std::runtime_error("bad input => " + str);
	poffst = ++offst;
	if ((offst = is_digit( str, offst )) < 1)
		throw std::runtime_error("bad input => " + str);
	tmp_str_cpy(str, offst - poffst, poffst);
	time_s.tm_mon = atoi(tmps) - 1;
	if (time_s.tm_mon < 0 || time_s.tm_mon > 11 || str[offst] != '-')
		throw std::runtime_error("bad input => " + str);
	poffst = ++offst;
	if ((offst = is_digit( str, offst )) < 1)
		throw std::runtime_error("bad input => " + str);
	tmp_str_cpy(str, offst - poffst, poffst);
	time_s.tm_mday = atoi(tmps);
	if (time_s.tm_mday < 1 || time_s.tm_mday > 31 || !(str[offst] == ',' || str[offst] == '|'))
		throw std::runtime_error("bad input => " + str);
	return (++offst);
}

void	BitcoinExchange::set_value(std::string & str, int offst)
{
	int	poffst = offst;

	std::memset(&tmps, 0, sizeof(tmps));
	if (str[offst] == '-' || str[offst] == '+')
	{
		if (str[offst] == '-')
			throw std::runtime_error("not a positive number.");
		poffst = ++offst;
	}
	if ((offst = is_digit( str, offst )) < 0)
	{
		std::cout << offst << " " << str[offst];
		throw std::runtime_error("bad input => " + str);
	}
		if (offst == 0)
	{}
	else if (str[offst] == '.')
	{
		offst++;
		if ((offst = is_digit( str, offst )) < 0)
			throw std::runtime_error("bad input => " + str);
		if (offst != 0 && (str[offst] == 'e' || str[offst] == 'E'))
		{
			offst++;
			if (str[offst] == '-' || str[offst] == '+')
				offst++;
			if ((offst = is_digit( str, offst )) != 0)
				throw std::runtime_error("bad input => " + str);
		}
		else if (offst != 0)
			throw std::runtime_error("bad input => " + str);
	}
	else if (str[offst] == 'e' || str[offst] == 'E')
	{
		offst++;
		if (str[offst] == '-' || str[offst] == '+')
			offst++;
		if ((offst = is_digit( str, offst )) != 0)
			throw std::runtime_error("bad input => " + str);
	}
	tmp_str_cpy(str, static_cast<int>(str.size()) - poffst, poffst);
	this->value = strtof(tmps, NULL);
	return ;
}

void	BitcoinExchange::line_integration( std::string str)
{
	try
	{
		int	offst = set_date(str);
		set_value(str, offst);
		std::pair<std::map<time_t, float>::iterator, bool> exist =
				this->data.insert(std::make_pair(mktime(&this->time_s), this->value));
		if (!exist.second)
			throw std::runtime_error("key already exist - nothing recorded " + str);
	}
	catch(const std::runtime_error & e)
	{
		std::cout << "Database integration error: " << e.what() << std::endl;
	}
}

void	BitcoinExchange::seek_line( std::string str )
{
	try
	{
		int	offst = set_date(str);
		set_value(str, offst);
		this->tmp_str_cpy(str, offst - 1, 0);
		if (this->value > 1000.0)
			throw std::runtime_error("a too large number.");
		std::map<std::time_t, float>::iterator it = this->data.upper_bound(mktime(&this->time_s));
		if (it == this->data.begin())
			throw std::runtime_error("no anterior date recorded.");
		else
			it--;
		std::cout << this->tmps << " => " << this->value << " = " << (this->value * it->second) << std::endl;
	}
	catch(const std::runtime_error & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
