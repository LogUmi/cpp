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
#include <deque>
#include <string>
#include <cstddef>
#include <ctime>

#define NUMBER_SIZE 4
#define TIME_SIZE 	10
#define TIME_PREC	5

class PmergeMe
{
	private:
		std::vector<int>					vdata;
		std::vector< std::pair<int, int> >	vPairs;
		std::vector<int>					vM;
		std::vector<size_t>					vjacobsthal;
		std::vector<size_t>					vpos;
		int									vodd;
		std::deque<int>						ddata;
		std::deque< std::pair<int, int> > 	dPairs;
		std::deque<int>						dM;
		std::deque<size_t>					djacobsthal;
		std::deque<size_t>					dpos;
		int									dodd;

		bool								is_valid( const char * str ) const;
		bool								sort_conform() const;
		void								vector_sort( void );
		void								dequer_sort( void );

	public:
					PmergeMe( void );
					PmergeMe( const PmergeMe & other );
					~PmergeMe( void );
		PmergeMe &	operator=( PmergeMe other );

		int		exec( int size, char** argv);
};
#endif
