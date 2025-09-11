/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/11 19:00:15 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "ex01 Form basic tests" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
	try
	{
		Form burct("High", 0, 42);
	}
	catch(const Form::GradeTooHighException & e)
	{
		std::cerr << "Form high signing_grade constructor error: "  << e.what() << std::endl;
	}
	
	try
	{
		Form burct("High", 42, 0);
	}
		catch(const Form::GradeTooHighException & e)
	{
		std::cerr << "Form high executing_grade constructor error: "  << e.what() << std::endl;
	}
	 try
	{
		Form burct("Low", 151, 42);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Form low signing_grade constructor error: " << e.what() << std::endl;
	}
	 try
	{
		Form burct("Low", 42, 151);
	}
		catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Form low executing_grade constructor error: " << e.what() << std::endl;
	}
	{
		Bureaucrat 	n;
		Bureaucrat 	n1("Big BOSS", 1);
		Form 		pq("PQ", 1, 150);
		n.signForm(pq);
		n1.signForm(pq);
	}

	
    return (0);
}