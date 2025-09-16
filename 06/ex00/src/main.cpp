/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/16 21:07:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "iostream"

int main( int argc, char ** argv )
{
	if (argc != 2)
	{
		std::cout 	<< "One parameter needed : ./ScalarConverter <char literal>" 
					<< std::endl;
		return (1);
	}
	ScalarConverter::convert( argv[1] );
	return (0);
}