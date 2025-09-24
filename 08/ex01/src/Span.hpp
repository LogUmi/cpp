/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/25 00:07:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

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
};
#endif