/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/18 22:25:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main( void )
{
	Data		chart;
	uintptr_t	serial;
	Data*		dcopy;

	chart.x = 71;
	chart.y = 27;
	chart.txt = "Location";
	std::cout 	<< "**********************************************************************" 
				<< std::endl;
	std::cout 	<< "Original Data pointer: " << &chart << " to x = " << chart.x
				<< " y = " << chart.y << " txt = " << chart.txt << std::endl;
	serial = Serializer::serialize ( &chart );
	dcopy = Serializer::deserialize(serial);
	std::cout 	<< "**********************************************************************" 
				<< std::endl;
	std::cout 	<< "uintptr_t " << serial << "(" << reinterpret_cast<void*>(serial) 
				<< ") stocked at &" << &serial << std::endl;
	std::cout 	<< "**********************************************************************" 
				<< std::endl;
	std::cout 	<< "deserialized Data pointer: " << dcopy << " to x = " << dcopy->x
				<< " y = " << dcopy->y << " txt = " << dcopy->txt << std::endl;
	std::cout 	<< "**********************************************************************" 
				<< std::endl << std::endl;
	if (dcopy == &chart)
		std::cout << "*** SUCCESS ***" << std::endl;
	else
		std::cout << "*** FAILURE ***" << std::endl;
	return (0);
}