/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:16:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/08 18:17:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
	public:
		Bureaucrat( void );
		Bureaucrat (std::string name, unsigned int grade);
		Bureaucrat ( const Bureaucrat & other );
		~Bureaucrat ( void );
		Bureaucrat& operator=(const Bureaucrat & burct);

		std::string		get_name( void ) const;
		unsigned int	get_grade( void ) const;
		void			upgrade(const Bureaucrat & burct);
		void			downgrade(const Bureaucrat & burct);
		
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException( void );
				GradeTooHighException( const GradeTooHighException & gthe);	
				virtual ~GradeTooHighException( void );
				GradeTooHighException& operator=(const GradeTooHighException & ghte);
				
				virtual const char* what() const throw();	
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException( void );
				GradeTooLowException( const GradeTooLowException & gtle);
				virtual ~GradeTooLowException( void );
				GradeTooLowException& operator=(const GradeTooLowException & gtle);
				
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & burct);
#endif;