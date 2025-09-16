/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/16 21:15:37 by lgerard          ###   ########.fr       */
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
	public:
		static void convert( const std::string  & literal );
};
#endif