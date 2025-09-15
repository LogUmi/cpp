/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:22:09 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/15 17:05:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	private:
		AForm* 		createShrubbery( std::string const & target );
       	AForm*		createRobotomy( std::string const & target );
       	AForm*		createPresidential( std::string const & target );

	public:
					Intern ( void );
					Intern ( Intern const & other );
					~Intern ( void );
		Intern & 	operator=( Intern const & other );

		AForm*	makeForm(std::string name, std::string target);

		class WrongFormException: std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
};
#endif