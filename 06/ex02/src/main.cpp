/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/19 17:18:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	switch (rand()%3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (0);
	}
}

void identify(Base* p)
{
	if (!p)
	{
		std::cout << "null pointer" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << " says identify*" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A says identify&" << std::endl;
		return ;
	}
	catch (const std::bad_cast & e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "B says identify&" << std::endl;
		return ;
	}
	catch (const std::bad_cast & e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "C says identify&" << std::endl;
		return ;
	}
	catch (const std::bad_cast & e){}
	std::cout << "Unknown says identify&" << std::endl;
}

int main( void )
{
	Base*	clss[10] = { nullptr };
	int		i = 0;

	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		std::cout << "clss[" << i << "]: ";
		clss[i] = generate();
	}
	std::cout 	<< "****************************************" 
				<< std::endl;
	for (i = 0; i < 10; i++)
	{
		std::cout << "clss[" << i << "]: ";
		identify(clss[i]);
	}
	std::cout 	<< "****************************************" 
				<< std::endl;
	for (i = 0; i < 10; i++)
	{
		std::cout << "clss[" << i << "]: ";
		identify(*clss[i]);
	}
	for (i = 0; i < 10; i++)
	{
		delete clss[i];
	}
	return (0);
}