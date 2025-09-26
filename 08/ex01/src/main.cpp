/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/26 20:06:15 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <list>
#include "Span.hpp"

int main( void )
{
	unsigned int	n = 0;

	std::srand(std::time(NULL));
	// ******** Subject test *********

		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** Subject test ***" << std::endl;
	try
	{
		n = 5;
		Span sp = Span(n);
		std::cout << "Span created with N = " << n << std::endl;
		std::cout << "Attempt of " << n << " single addNumber: ";
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "done !" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ******** Subject test with too many addNumber *********

		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** Subject test with too many addNumber ***" << std::endl;
	try
	{
		n = 5;
		Span sp = Span(n);
		std::cout << "Span created with N = " << n << std::endl;
		std::cout << "Attempt of " << n + 1 << " single addNumber: ";
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(27);
		std::cout << "done !" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
// ******** vector addNumber full range regular test *********

		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** Vector full range addnumber regular test ***" << std::endl;
	try
	{
		n = 5;
		Span sp = Span(n);
		std::cout << "Span created with N = " << n << std::endl;
		std::vector<int> v;
		v.push_back(6);
		v.push_back(3);
		v.push_back(17);
		v.push_back(9);
		v.push_back(11);
		std::cout << "vector created with " << n << " int numbers" << std::endl;
		std::cout << "Attempt of range of " << n << " range addNumber: ";
		sp.addNumber(v.begin(), v.end());
		std::cout << "done !" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// ******** vector addNumber full range test with previous signle addNumber *********

		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** vector addNumber full range test with previous single addNumber ***" << std::endl;
	try
	{
		n = 5;
		Span sp = Span(n);
		std::cout << "Span created with N = " << n << std::endl;
		std::cout << "Attempt of " << n - 3 << " single addNumber: ";
		sp.addNumber(6);
		sp.addNumber(3);
		std::cout << "done !" << std::endl;
		std::vector<int> v;
		v.push_back(6);
		v.push_back(3);
		v.push_back(17);
		v.push_back(9);
		v.push_back(11);
		std::cout << "vector created with " << n << " int numbers" << std::endl;
		std::cout << "Attempt of range of " << n << " range addNumber: ";
		sp.addNumber(v.begin(), v.end());
		std::cout << "done !" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// ******** vector addNumber partial range test with previous single addNumber *********

		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** vector addNumber partial range test with previous single addNumber ***" << std::endl;
	try
	{
		n = 5;
		Span sp = Span(n);
		std::cout << "Span created with N = " << n << std::endl;
		std::cout << "Attempt of " << n - 3 << " single addNumber: ";
		sp.addNumber(6);
		sp.addNumber(3);
		std::cout << "done !" << std::endl;
		std::vector<int> v;
		v.push_back(6);
		v.push_back(3);
		v.push_back(17);
		v.push_back(9);
		v.push_back(11);
		std::cout << "vector created with " << n << " int numbers" << std::endl;
		std::cout << "Attempt of range of " << n - 2 << " range addNumber: ";
		sp.addNumber(v.begin() + 2, v.end());
		std::cout << "done !" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << sp.longestSpan() << std::endl;
		std::cout << "*** copy constructor test ***" << std::endl;
		Span ssp = Span(sp);
		std::cout << "shortestSpan: " << ssp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << ssp.longestSpan() << std::endl;
		std::cout << "*** assignation test ***" << std::endl;
		Span sssp = Span();
		sssp = sp;
		std::cout << "shortestSpan: " << sssp.shortestSpan() << std::endl;
		std::cout << "longestSpasn: " << sssp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// ******** list addNumber range test with previous signle addNumber *********

		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** list addNumber range test with previous single addNumber ***" << std::endl;
	try
	{
		n = 12000;
		Span sp = Span(n);
		std::cout << "Span created with N = " << n << std::endl;
		std::cout << "Attempt of 2 single addNumber(INT_MIN & INT_MAX): ";
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		std::cout << "done !" << std::endl;
		std::list<int> l;
		for (int i = 0; i < 11298; i++)
			l.push_back(rand());
		std::cout << "list created with " << n - 2 << " random int numbers" << std::endl;
		std::cout << "Attempt of range of " << n - 2 << " range addNumber: ";
		sp.addNumber(l.begin(), l.end());
		std::cout << "done !" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		long diffm = static_cast<long>(INT_MAX) - static_cast<long>(INT_MIN);
		std::cout	<< "longestSpasn: " << sp.longestSpan() 
					<< " (INT_MAX - INT_MIN = " << static_cast<unsigned int>(diffm)
					<< ")" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

