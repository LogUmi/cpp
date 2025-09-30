/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 13:31:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <fstream>
#include <string>
#include <iostream>

/******************************************************************************/
/* Constructors and destructor                                                */
/******************************************************************************/

RPN::RPN( void )
:	data()
{}

RPN::RPN( const RPN & other )
:	data(other.data)
{}

RPN::~RPN( void )
{}

/******************************************************************************/
/* overload of operators                                                      */
/******************************************************************************/

RPN &	RPN::operator=( RPN other )
{
	std::swap(this->data, other.data);
	return (*this);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

int	RPN::exec(std::string str)
{
	if (str.empty() == true)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	size_t	offst = 0;
	size_t	nb = 0;
	while (offst != str.size())
	{
		if (isspace(str[offst]))
		{
			nb = 0;
			offst++;
		}
		else if (isdigit(str[offst]))
		{
			if (nb != 0)
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			nb++;
			data.push(str[offst++] - 48);
		}
		else if (str[offst] == '+' || str[offst] == '-'
					|| str[offst] == '*' || str[offst] == '/')
		{
			if (nb != 0)
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			nb++;
			switch (str[offst++])
			{
				
			}
		}
	}

}

