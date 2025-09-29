/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/29 15:39:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <cstddef>
#include <stdexcept>

class Span
{
	private:
		std::vector<int>	data;
		unsigned int		N;

	public:
				Span ( void );
				Span ( unsigned int N );
				Span ( const Span & other );
				~Span ( void );
		Span &	operator=( Span other );

		void			addNumber( const int i );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

		template <typename InputIterator>
		void	addNumber( InputIterator first, InputIterator last )
		{
			size_t distance = std::distance(first, last);
			if (distance > (this->N - this->data.size()))
				throw std::logic_error("Span: too much data");
			data.insert(this->data.end(), first, last);
		}
	};
#endif
