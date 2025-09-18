/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/18 18:15:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
							ScalarConverter( void );
							ScalarConverter( const ScalarConverter & other );
							~ScalarConverter( void );
		ScalarConverter & 	operator=( const ScalarConverter & other );

		static int			is_digit( const std::string & arg, int ptr );
		static int			is_what( const std::string & arg );

	public:
		static void convert( const std::string  & literal );
};
#endif