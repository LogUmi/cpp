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
#include <fstream>
#include <string>
#include <iostream>

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

PmergeMe::PmergeMe( void )
:	data()
{}

PmergeMe::PmergeMe( const PmergeMe & other )
:	data(other.data)
{}

PmergeMe::~PmergeMe( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

PmergeMe &	PmergeMe::operator=( PmergeMe other )
{
	std::swap(this->data, other.data);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

int	PmergeMe::exec(std::string str)
{
	size_t	offst = 0;
	size_t	nb = 0;
	int		i = 0;
	
	while (offst != str.size())
	{
		if (isspace(str[offst]))
			nb = 0;
		else if (isdigit(str[offst]))
		{
			if (nb != 0)
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			nb++;
			data.push(str[offst] - 48);
		}
		else if (this->data.size() >= 2 && (str[offst] == '+' || str[offst] == '-'
					|| str[offst] == '*' || str[offst] == '/'))
		{
			if (nb != 0)
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			nb++;
			i = this->data.top();
			this->data.pop();
			switch (str[offst])
			{
				case 42:
					this->data.top() *= i;
					break ;
				case 43:
					this->data.top() += i;
					break ;
				case 45:
					this->data.top() -= i;
					break;
				case 47:
					this->data.top() /= i;
					break ;
				default:
					std::cerr << "Error" << std::endl;
					return (1);
					break ;
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		offst++;
	}
	if (this->data.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::cout << this->data.top() << std::endl;
	return (0);
}

