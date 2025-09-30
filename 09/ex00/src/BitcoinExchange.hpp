/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 16:43:38 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <string>
#include <cstdlib>

#define DATAFILE 		"data.csv"
#define TMP_STR_LEN		256

class BitcoinExchange
{
	private:
		std::map<time_t, float> data;
		struct tm				time_s;
		float					value;
		char					tmps[TMP_STR_LEN];

		void	tmp_str_cpy(std::string & str, int n, int pos);
		size_t	is_digit(std::string & str, int offst) const;
		size_t	set_date(std::string & str);
		void	set_value(std::string & str, int offst);

	public:
							BitcoinExchange( void );
							BitcoinExchange( const BitcoinExchange & other );
							~BitcoinExchange( void );
		BitcoinExchange &	operator=( BitcoinExchange other );

		void				line_integration( std::string str);
		void				seek_line( std::string str );

};
#endif
