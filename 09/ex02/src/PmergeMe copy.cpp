/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 19:28:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <climits>
#include <iomanip>
#include <utility>
#include <algorithm>

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

PmergeMe::PmergeMe( void )
:	vdata(),
	vPairs(),
	vM(),
	vjacobsthal(),
	vpos(),
	vodd(-1),
	ddata(),
	dPairs(),
	dM(),
	djacobsthal(),
	dpos(),
	dodd(-1)
{}

PmergeMe::PmergeMe( const PmergeMe & other )
:	vdata(other.vdata),
	vPairs(other.vPairs),
	vM(other.vM),
	vjacobsthal(other.vjacobsthal),
	vpos(other.vpos),
	vodd(other.vodd),
	ddata(other.ddata),
	dPairs(other.dPairs),
	dM(other.dM),
	djacobsthal(other.djacobsthal),
	dpos(other.dpos),
	dodd(other.dodd)
{}

PmergeMe::~PmergeMe( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

PmergeMe &	PmergeMe::operator=( PmergeMe other )
{
	std::swap(this->vdata, other.vdata);
	std::swap(this->vPairs, other.vPairs);
	std::swap(this->vM, other.vM);
	std::swap(this->vjacobsthal, other.vjacobsthal);
	std::swap(this->vpos, other.vpos);
	std::swap(this->vodd, other.vodd);
	std::swap(this->ddata, other.ddata);
	std::swap(this->dPairs, other.dPairs);
	std::swap(this->dM, other.dM);
	std::swap(this->djacobsthal, other.djacobsthal);
	std::swap(this->dpos, other.dpos);
	std::swap(this->dodd, other.dodd);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

bool	PmergeMe::is_valid( const char * str ) const
{
	size_t	i = 0;

	if (str[i] == 0)
		return ( false );
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (size_t j = i; str[j] != 0; j++)
	{
		if (!(str[j] > 47 && str[j] < 58))
			return ( false );
	}
	return ( true );
}

void	PmergeMe::vector_sort( void )
{
	/*********** only one number **********/
	if (vdata.size() == 1)
	{
		vM.push_back(vdata[0]);
		return ;
	}
/*********** Pairs creation with consecutives data numbers max first & min second **********/
	size_t 	j = 0;
	size_t	i = 0;
	size_t	npair = vdata.size() / 2;
	for (i = 0; i < npair; i++)
	{
		vPairs.push_back(std::make_pair(std::max(vdata[j], vdata[j + 1]), std::min(vdata[j], vdata[j + 1])));
		j += 2;
	}
	if ((vdata.size() % 2) != 0) /* if odd n numbers save the single number */
		vodd = vdata[j];

/*********** sorting pairs then inializing the main container & pair positions container **********/
	std::sort (vPairs.begin(), vPairs.end());
	j = 1;
	vM.push_back(vPairs[0].second);
	vM.push_back(vPairs[0].first);
	vpos.push_back(j++);
	for (i = 1; i < vPairs.size(); i++)
	{
		vM.push_back(vPairs[i].first);
		vpos.push_back(j++);
	}
/*********** initialization of the jacobsthal numbers (orders of pair.second index to insert) **********/
	size_t	j0 = 0;
	size_t	j1 = 1;
	vjacobsthal.push_back(1);
	if (npair > 1) /* if there's only one pair the pair.second is already inserted */
	{
		for (;;)
		{	
			j = j1 + 2 * j0;
			j0 = j1;
			j1 = j;
			if (j1 <= npair)
			{
				vjacobsthal.push_back(j1);
				if (j1 == npair)
					break ;
			}
			else if ( j1 > npair)
			{
				vjacobsthal.push_back(npair);
				break ;
			}
		}
		/*std::cout << "jabcobsthal: ";
		for (i = 0; i < vjacobsthal.size(); i++)
			std::cout << vjacobsthal[i] << " ";
		std::cout << std::endl;*/
		/*********** pair.second insertion in cotainer main **********/

		size_t	k = 0;
		//size_t	hi_bound = vjacobsthal[k]; /* index high bound initialized to 1 */
		//size_t 	lo_bound = 0; /* index low bound initialized to 0 */
		size_t	lft_bound = 0; /* index left bound as low bound for start */
		size_t	rgt_bound = vpos[vjacobsthal[k]]; /* index right bound as low bound for start */
		//size_t	mid_bound = 0; /* index mid bound as low bound for start */
		size_t	pos_fin = vpos.size();
		j = 0;
		while (k < vjacobsthal.size() - 1)
		{
			i = vjacobsthal[k];
			rgt_bound = vpos[k];
			lft_bound = 0; //(k == 0 ? 0 : vpos[k - 1]);
			while ( i > vjacobsthal[k - 1] )
			{
				/*if (vPairs[i].second <= vM[vpos[i]])
				{
					rgt_bound = lft_bound;
					lft_bound = 0;
				}*/
				std::vector<int>::iterator pos = std::lower_bound(vM.begin() + lft_bound
												, vM.begin() + rgt_bound, vPairs[i].second);
				vM.insert(pos, vPairs[i].second);
				j = pos - vM.begin();
				std::cout 	<< "k=" << k << " i=" << i << " pair[i]=" << vPairs[i].first <<  ", " 
							<< vPairs[i].second<< " lft=" << lft_bound << " rgt=" << rgt_bound
							<< " j=" << j << " *pos=" << *pos << " vpos[i]=" << vpos[i] << std::endl;
				for (size_t it = 0; it < pos_fin; it++)
				{	
					if (vpos[it] >= j)
						vpos[it]++;
				}
				i--;
				rgt_bound = vpos[i];
			}
			k++;
		}
	}
/*********** insertion of last odd count number if there's one **********/
	if (vodd != -1)
	{
    std::vector<int>::iterator pos = std::lower_bound(vM.begin(), vM.end(), vodd);
    vM.insert(pos, vodd);
	}
}
void	PmergeMe::dequer_sort( void )
{
	if (ddata.size() == 1)
	{
		dM.push_back(ddata[0]);
		return ;
	}
}

int	PmergeMe::exec( int size, char** argv)
{
	/*********** arguments management ***********/
	int	i = 0;
	long	val =0;

	for (i = 1; i <= size; i++)
	{
		if (is_valid( argv[i] ) == false)
		{
			std::cerr 	<< "Error: invalid number format '" << argv[i] 
						<< "' in sequence" << std::endl;
			return (1);
		}
		val = atol(argv[i]);
		if (val < 0)
		{
			std::cerr 	<< "Error: negative int value " << val 
						<< " in sequence" << std::endl;
			return (1);
		}
		if (val > INT_MAX)
		{
			std::cerr 	<< "Error: overflow int value " << val 
						<< " in sequence" << std::endl;
			return (1);
		}
		vdata.push_back(static_cast<int>(val));
		ddata.push_back(static_cast<int>(val));
	}
	std::cout 	<< "Before:  ";
	for (i = 0; i < size; i++)
		std::cout << vdata[i] << " ";
	std::cout 	<< std::endl;
	/*********** vector sorting ***********/
	clock_t	vstart = clock();
	vector_sort();
	clock_t	vstop = clock();
	/*********** dequer sorting ***********/
	clock_t	dstart = clock();
	dequer_sort();
	clock_t	dstop = clock();
	/***********  sorting output ***********/
	std::cout 	<< "After:   ";
	for (size_t j = 0; j < vM.size(); j++)
		std::cout 	<< vM[j] << " ";	
	std::cout 	<< std::endl;
	double v_us = 1e6 * static_cast<double>(vstop - vstart) / CLOCKS_PER_SEC;
	double d_us = 1e6 * static_cast<double>(dstop - dstart) / CLOCKS_PER_SEC;
	std::cout 	<< "Time to process a range of " << std::setw(NUMBER_SIZE) << vM.size()
				<< " elements with std::vector : " << std::fixed << std::setw (TIME_SIZE) 
				<< std::setprecision(TIME_PREC)	<< v_us	<< " us" << std::endl;
	std::cout 	<< "Time to process a range of " << std::setw(NUMBER_SIZE) << dM.size()
				<< " elements with std::deque  : " << std::fixed << std::setw (TIME_SIZE) 
				<< std::setprecision(TIME_PREC)	<< d_us << " us" << std::endl;
  return (0);

}

