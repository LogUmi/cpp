/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/28 16:01:37 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <list>
#include "MutantStack.hpp"

int main( void )
{
	// ******** Subject test *********
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl << "*** Subject test ***" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl; // the last pushed so 17
		mstack.pop(); // erase 17
		std::cout << mstack.size() << std::endl; // after pop remain only 1
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;// must print 5, 3, 5, 737 then 0
		++it;
		}
		std::stack<int> s(mstack);
		std::cout << "MutantStack copied " << s.size() << " members in a std::stack ... what's in stack :";
		for (int i = s.size(); i != 0; i--)
		{
			std::cout << s.top() << " ... "; //  must print 0, 737, 5, 3, then 5
			s.pop();
		}
		std::cout << "end" << std::endl;
		// ******** complementary tests on MutantStack *********
		std::cout 	<< "********************************************" 
					<< "********************************************" 
					<< std::endl << "*** complementary tests on MutantStack ***" << std::endl;
		std::cout << "default constructor test : is empty : ";
		MutantStack<int> ms;
		std::cout << ms.empty() << " and size = " << ms.size() << std::endl;
		std::cout << "assignation operator test : assignated content : ";
		ms = mstack;
		it = ms.begin();
		ite = ms.end();
		while (it != ite)
		{
			std::cout << *it << " ... ";// must print 5, 3, 5, 737 then 0
			++it;
		}
		std::cout << "end" << std::endl;
		std::cout << "copy constructor test : copy content : ";
		MutantStack<int> mss(ms);
		it = mss.begin();
		ite = mss.end();
		while (it != ite)
		{
			std::cout << *it << " ... ";// must print 5, 3, 5, 737 then 0
			++it;
		}
		std::cout << "end" << std::endl;
	}
	// ******** Subject test with list instead *********
	std::cout 	<< "********************************************" 
				<< "********************************************" 
				<< std::endl << "*** Subject test with list instead ***" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl; // the last pushed so 17
		mstack.pop_back(); // erase 17
		std::cout << mstack.size() << std::endl; // after pop remain only 1
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;// must print 5, 3, 5, 737 then 0
		++it;
		}
	}
return (0);
}
