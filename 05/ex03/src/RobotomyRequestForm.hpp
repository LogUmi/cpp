/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:05:00 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/14 13:02:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm & other );
		RobotomyRequestForm( std::string target );
		virtual ~RobotomyRequestForm ( void );
		RobotomyRequestForm& 	operator=( const RobotomyRequestForm & other );

		virtual void		execute(Bureaucrat const & executor) const;
};
#endif