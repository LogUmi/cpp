/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:05:09 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/12 17:43:49 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm & other );
		ShrubberyCreationForm( std::string target );
		virtual ~ShrubberyCreationForm ( void );
		ShrubberyCreationForm& 	operator=( const ShrubberyCreationForm & other );

		virtual void		execute(Bureaucrat const & executor) const;
		
		class FileIssueException: std::exception
		{
			public:
			virtual const char * what ( void ) const throw();
		};
};
#endif