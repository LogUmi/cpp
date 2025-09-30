/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 13:28:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> data;

	public:
				RPN( void );
				RPN( const RPN & other );
				~RPN( void );
		RPN &	operator=( RPN other );

		int		exec( std::string str);
};
#endif
