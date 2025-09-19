/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/19 23:12:38 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"


int main( void )
{
	int			i[5] = {1, 2, 3, 4, 5};
	float		f[5] = {6.5, 7.5, 8.5, 9.5, 10.5};
	double		d[5] = {11.5, 12.5, 13.5, 14.5, 15.5};
	void*		p[5] = {&i[0], &i[1], &i[2], &i[3], &i[4]};
	std::string	s[5] = {"un", "deux", "trois", "quatre", "cinq"};
	char		c[15] = "ceci est char*";
	int			j = 0;

	// ******** int *********
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	std::cout << "array int created : ";
	for (j = 0; j < 5; j++)
		std::cout << i[j] << " ";
	std::cout << std::endl;
	std::cout << "array with iter   : ";
	::iter( i, 5, &print_member );
	std::cout << std::endl;
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	// ******** floats *********
	std::cout << "array float created : ";
	for (j = 0; j < 5; j++)
		std::cout << f[j] << " ";
	std::cout << std::endl;
	std::cout << "array with iter     : ";
	::iter( f, 5, &print_member );
	std::cout << std::endl;
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	// ******** double *********
	std::cout << "array double created : ";
	for (j = 0; j < 5; j++)
		std::cout << d[j] << " ";
	std::cout << std::endl;
	std::cout << "array with iter      : ";
	::iter( d, 5, &print_member );
	std::cout << std::endl;
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	// ******** pointer *********
	std::cout << "pointer array created : ";
	for (j = 0; j < 5; j++)
		std::cout << p[j] << " ";
	std::cout << std::endl;
	std::cout << "array with iter       : ";
	::iter( p, 5, &print_member );
	std::cout << std::endl;
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	// ******** std::string *********
	std::cout << "array std::string created : ";
	for (j = 0; j < 5; j++)
		std::cout << s[j] << " ";
	std::cout << std::endl;
	std::cout << "array with iter           : ";
	::iter( s, 5, &print_member );
	std::cout << std::endl;
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	// ******** char* *********
	std::cout << "array char created : ";
	for (j = 0; j < 15; j++)
		std::cout << c[j] << " ";
	std::cout << std::endl;
	std::cout << "array with iter    : ";
	::iter( c, 15, &print_member );
	std::cout << std::endl;
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl;
	return (0);
}