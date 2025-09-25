/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/25 12:37:27 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <limits>

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

Span::Span( void )
:	data(0),
	N(0)
{}

Span::Span( unsigned int n)
:	data(0),
	N(n)
{}

Span::Span( const Span & other )
:	data(other.data),
	N(other.N)
{}

Span::~Span( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

Span &	Span::operator=( Span other )
{
	std::swap(this->N, other.N);
	std::swap(this->data, other.data);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void	Span::addNumber( const int i)
{
	if (data.size() >= this->N)
		throw std::length_error("Span: data is already full");
	data.push_back(i);
}

unsigned int	Span::shortestSpan( void ) const
{
	if (data.size() < 2)
		throw std::logic_error("Span: no enough numbers");
	std::vector<int> tmp(data);
	std::sort(tmp.begin(), tmp.end());

	unsigned int 	smin = std::numeric_limits<unsigned int>::max();
	unsigned int	sous = 0;

	for (std::vector<int>::iterator it = tmp.begin(); it != (tmp.end() - 1); it++)
	{
		sous = *(it + 1) - *it;
		if (sous < smin)
			smin = sous; 
	}
	return (smin);
}

unsigned int Span::longestSpan( void ) const
{
	if (data.size() < 2)
		throw std::logic_error("Span: no enough numbers");
	return (*std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end()));
}
