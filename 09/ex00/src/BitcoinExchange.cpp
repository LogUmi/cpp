/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/28 22:44:06 by lgerard          ###   ########.fr       */
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
{}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & other )
:	data(other.data)
{}

BitcoinExchange::~BitcoinExchange( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange other )
{
	std::swap(this->data, other.data);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

BitcoinExchange::line_integration( std::string str)
{
	std::cout << str << std::endl;
}

BitcoinExchange::seek_line( std::string str )
{
	std::cout << str << std::endl;
}
