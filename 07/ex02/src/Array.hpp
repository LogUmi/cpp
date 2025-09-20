/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/20 16:50:59 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template < typename T >
class Array
{
	private:
		T*				data;
		unsigned int	n;
	public:
		Array		( void );
		Array		( unsigned int n );
		Array		( const Array & other);
		~Array		( void );
		
		Array<T> &	operator=( const Array & other );
		T &			operator[]( const unsigned int idx );
		const T & 	operator[]( const unsigned int idx ) const;
		
		unsigned int 	size( void ) const;
};
# include "Array.tpp"
#endif