/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 19:28:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <cstddef>
#include <ctime>
#include <ratio>
#include <chrono>

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

PmergeMe::PmergeMe( void )
:	datav(),
	datad()
{}

PmergeMe::PmergeMe( const PmergeMe & other )
:	datav(other.datav),
	datad(other.datad)
{}

PmergeMe::~PmergeMe( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

PmergeMe &	PmergeMe::operator=( PmergeMe other )
{
	std::swap(this->datav, other.datav);
	std::swap(this->datad, other.datad);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

int	PmergeMe::exec( int size, char** argv)
{
	//size_t	i = 0;
	//using namespace std::chrono;
	static_cast<void>(size);
	static_cast<void>(argv);

  	std::chrono::steady_clock::time_point t1 = 	std::chrono::steady_clock::now();

	std::cout << "printing out 1000 stars...\n";
	for (int i=0; i<1000; ++i) std::cout << "*";
	std::cout << std::endl;
	std::chrono::steady_clock::time_point t2 = 	std::chrono::steady_clock::now();

  	std::chrono::duration<double> time_span = 	std::chrono::duration_cast<	std::chrono::duration<double>>(t2 - t1);

  	std::cout << "It took me " << time_span.count() << " seconds.";
	std::cout << std::endl;

  return (0);

}

