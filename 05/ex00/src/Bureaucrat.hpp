/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:16:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/05 18:14:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat (std::string name, unsigned int grade);
		Bureaucrat ( const Bureaucrat & other );
		~Bureaucrat ( void );
		Bureaucrat& operator=(const Bureaucrat & burct);

		std::string		get_name( void ) const;
		unsigned int	get_grade( void ) const;
		
	private:
		const std::string	name;
		unsigned int		grade;
		
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & burct);
#endif;