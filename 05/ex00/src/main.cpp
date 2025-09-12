/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/11 18:36:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "ex00 Bureaucrat basic tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	try
	{
		Bureaucrat burct("High", 0);
	}
	catch(const Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Bureaucrat constructor error: "  << e.what() << std::endl;
	}
	 try
	{
		Bureaucrat burct("Low", 151);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Bureaucrat constructor error: " << e.what() << std::endl;
	}
	
	{
		Bureaucrat burct("Someone", 10);
		for (int i = 10; i > 0; i--)
		{
	    	try
	    	{
				burct.upGrade();
				std::cout << burct << std::endl;
	    	}
	    	catch(const Bureaucrat::GradeTooHighException& e)
	    	{
	        	std::cerr << burct << ": upGrade error: " << e.what() << std::endl;
	    	}
		}
	}
	{
		Bureaucrat burct("downgrade", 140);
    	for (int i = 0; i <= 10; i++)
		{
	    	try
	    	{
				burct.downGrade();
				std::cout << burct << std::endl;
	    	}
	    	catch(const Bureaucrat::GradeTooLowException& e)
	    	{
	        	std::cerr << burct << ": downGrade error: " << e.what() << std::endl;
	    	}
		}
	}
    return (0);
}