/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:04:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/14 12:52:42 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm & other );
		PresidentialPardonForm( std::string target );
		virtual ~PresidentialPardonForm ( void );
		PresidentialPardonForm& 	operator=( const PresidentialPardonForm & other );

		virtual void		execute(Bureaucrat const & executor) const;
};
#endif