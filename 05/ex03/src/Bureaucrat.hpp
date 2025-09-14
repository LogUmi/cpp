/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:16:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/12 17:45:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
	public:
		Bureaucrat( void );
		Bureaucrat (std::string name, int grade);
		Bureaucrat ( const Bureaucrat & other );
		~Bureaucrat ( void );
		Bureaucrat& operator=(const Bureaucrat & burct);

		const std::string		get_name( void ) const;
		int						get_grade( void ) const;
		void					upGrade( void );
		void					downGrade( void );
		void					signForm( AForm & toSign );
		void					executeForm( AForm const & form ) const;
		
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();	
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & burct);
#endif