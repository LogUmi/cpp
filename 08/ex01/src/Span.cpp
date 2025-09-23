/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/23 19:59:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

Span::Span( void )
:	data(0),
	N(0)
{}

Span::Span( unsigned int n)
:	data(0),
	N(N)
{
	data = new int[N]();
}

Span::Span( const Span & other )
:	data(0),
	N(other.N)
{
	this->data = new int[this->N];
	for (unsigned int i = 0; i < other.N; i++)
		this->data[i] = other.data[i];
}

Span::~Span( void )
{
	delete[] this->data;
}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

Span &	Span::operator=(const Span & other)
{
	if (this != &other)
	{
		this->N = other.N;
		if (this->N == 0)
		{
			delete[] this->data;
			data = 0;
		}
		else
		{
			int* tmp = new int[this->N];
			for (unsigned int i = 0; i < this->N; i++)
				tmp[i] = other.data[i];
			delete[] this->data;
			this->data = tmp;
		}
	}
	return (*this);
}

Span::operator[](const unsigned int idx)
{
	if (idx >= this->n)
		throw std::out_of_range("index out of range");
	return (this->data[idx]);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

unsigned int Span::size( void ) const
{
	return ( this->n );
}
