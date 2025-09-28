/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/28 22:46:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <string>

#define DATAFILE "data.csv"

class BitcoinExchange
{
	private:
		std::map<time_t, float> data;

	public:
							BitcoinExchange( void );
							BitcoinExchange( const BitcoinExchange & other );
							~BitcoinExchange( void );
		BitcoinExchange &	operator=( BitcoinExchange other );

		void				line_integration( std::string str);
		void				seek_line( std::string str );

};
#endif
