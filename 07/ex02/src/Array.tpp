/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/20 18:23:18 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

template < typename T >
Array<T>::Array( void )
:	data(0),
	n(0)
{}

template < typename T >
Array<T>::Array( unsigned int n)
:	data(0),
	n(n)
{
	data = new T[n]();
}

template < typename T >
Array<T>::Array( const Array & other )
:	data(0),
	n(other.n)
{
	this->data = new T[this->n];
	for (unsigned int i = 0; i < other.n; i++)
		this->data[i] = other.data[i];
}

template < typename T >
Array<T>::~Array( void )
{
	delete[] this->data;
}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

template < typename T >
Array<T> &	Array<T>::operator=(const Array & other)
{
	if (this != &other)
	{
		this->n = other.n;
		if (this->n == 0)
		{
			delete[] this->data;
			data = 0;
		}
		else
		{
			T* tmp = new T[this->n];
			for (unsigned int i = 0; i < this->n; i++)
				tmp[i] = other.data[i];
			delete[] this->data;
			this->data = tmp;
		}
	}
	return (*this);
}

template < typename T >
T & Array<T>::operator[](const unsigned int idx)
{
	if (idx >= this->n)
		throw std::out_of_range("index out of range");
	return (this->data[idx]);
}

template < typename T >
const T & Array<T>::operator[](const unsigned int idx) const
{
	if (idx >= this->n)
		throw std::out_of_range("index out of range");
	return (this->data[idx]);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

template < typename T >
unsigned int Array<T>::size( void ) const
{
	return ( this->n );
}
