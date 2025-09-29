/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/26 19:15:24 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:

	public:
						MutantStack ( void ){};
						MutantStack ( const MutantStack & other ): std::stack<T>(other.c){};
						~MutantStack ( void ){};
		MutantStack &	operator=( MutantStack other )
		{
			std::swap(this->c, other.c);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator					iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin( void ) { return (this->c.begin()); };
		iterator				end( void ) { return(this->c.end()); };
		const_iterator			begin( void ) const { return (this->c.cbegin()); };
		const_iterator			end( void ) const { return(this->c.cend()); };
		reverse_iterator		rbegin( void ) { return (this->c.rbegin()); };
		reverse_iterator		rend( void ) { return(this->c.rend()); };
		const_reverse_iterator	rbegin( void ) const { return (this->c.crbegin()); };
		const_reverse_iterator	rend( void ) const { return(this->c.crend()); };
};
#endif
