/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/10/07 16:21:23 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "BitcoinExchange.hpp"

void	treat_file( std::ifstream & ifs, bool type, BitcoinExchange & btc )
{
	std::string	str = "";
	std::string	result = "";
	int			i = 0;
	while (std::getline( ifs, result ))
	{
		str = str + result;
		/* if (ifs.eof() && !ifs.fail())
			break ; */
		if (ifs.eof() && ifs.fail())
			break ;
		else if (ifs.fail())
			throw std::runtime_error("ERROR: Logical error : failed to read (FAIL) file ");
		else if (ifs.bad())
			std::cerr 	<< "ERROR: Stream fatal error (BAD) on file " << std::endl;
		str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
		if ( i == 0 )
		{
			i++;
			if (str != "date,exchange_rate" && str != "date|value")
				throw std::runtime_error("Error: wrong format header in file ");
		}
		else if (type == true)
			btc.line_integration( str );
		else
			btc.seek_line( str );
		str.clear();
	}
	if (i == 0 && ifs.eof() && ifs.fail())
		throw std::runtime_error("Error: empty file ");	
}

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream	ifs(argv[1]);
	if (ifs.is_open() != true)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream	dataf(DATAFILE);
	if (dataf.is_open() != true)
	{
		std::cout << "Error: could not open database file." << std::endl;
		ifs.close();
		return (1);
	}
	/******* integration de la database *******/
	BitcoinExchange btc;
	try
	{
		treat_file(dataf, true, btc);
	}
	catch (const std::runtime_error & e)
	{
		std::cout << e.what() << DATAFILE << std::endl;
		dataf.close();
		ifs.close();
		return (1);
	}
	dataf.close();
	/******* prise en compte du fichier input et comparaison *******/
	try
	{
		treat_file(ifs, false, btc);
	}
	catch (const std::runtime_error & e)
	{
		std::cout << e.what() << argv[1] << std::endl;
		ifs.close();
		return (1);
	}
	ifs.close();
	return (0);
}
