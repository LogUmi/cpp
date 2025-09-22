/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/21 21:20:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main( void )
{
	int		i = 0;

	// ******** vector *********
	{
		i = 0;
		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** vector ***" << std::endl;
		std::vector<int> ctnr;
		std::vector<int>::const_iterator it;
		std::cout 	<< "container created" << std::endl;
		std::cout 	<< "easyfind of " << i << " in empty container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		ctnr.push_back(1);
		ctnr.push_back(2);
		ctnr.push_back(3);
		ctnr.push_back(4);
		ctnr.push_back(5);
		std::cout 	<< "container filled with : ";
		for (it = ctnr.begin(); it != ctnr.end(); it++)
			std::cout << &(*it) << " / " << *it << " ";
		std::cout << std::endl;
		std::cout 	<< "easyfind of " << i << " in container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		i = 3;
		std::cout 	<< "easyfind of " << i << " in container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what();
		}
	}
	// ******** list *********
	{
		i = 0;
		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** list ***" << std::endl;
		std::list<int> ctnr;
		std::list<int>::const_iterator it;
		std::cout 	<< "container created" << std::endl;
		std::cout 	<< "easyfind of " << i << " in empty container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		ctnr.push_back(1);
		ctnr.push_back(2);
		ctnr.push_back(3);
		ctnr.push_back(4);
		ctnr.push_back(5);
		std::cout 	<< "container filled with : ";
		for (it = ctnr.begin(); it != ctnr.end(); it++)
			std::cout << &(*it) << " / " << *it << " ";
		std::cout << std::endl;
		std::cout 	<< "easyfind of " << i << " in container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		i = 3;
		std::cout 	<< "easyfind of " << i << " in container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what();
		}
	}
	// ******** deque *********
	{
		i = 0;
		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl;
		std::cout 	<< "*** deque ***" << std::endl;
		std::deque<int> ctnr;
		std::deque<int>::const_iterator it;
		std::cout 	<< "container created" << std::endl;
		std::cout 	<< "easyfind of " << i << " in empty container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		ctnr.push_back(1);
		ctnr.push_back(2);
		ctnr.push_back(3);
		ctnr.push_back(4);
		ctnr.push_back(5);
		std::cout 	<< "container filled with : ";
		for (it = ctnr.begin(); it != ctnr.end(); it++)
			std::cout << &(*it) << " / " << *it << " ";
		std::cout << std::endl;
		std::cout 	<< "easyfind of " << i << " in container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		i = 3;
		std::cout 	<< "easyfind of " << i << " in container -> ";
		try
		{
			it = easyfind(ctnr, i);
			std::cout 	<< "easyfind: " << i << " found at " << &(*it) << " / "
						<< *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what();
		}
	}
	return (0);
}