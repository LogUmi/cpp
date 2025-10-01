/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 19:01:35 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe
{
	private:
		std::vector<unsigned int>	datav;
		std::list<unsigned int>		datal;

	public:
				PmergeMe( void );
				PmergeMe( const PmergeMe & other );
				~PmergeMe( void );
		PmergeMe &	operator=( PmergeMe other );

		int		exec( std::string str );
};
#endif
