/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:16:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/05 17:34:08 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat (std::string name, unsigned int grad);
		~Bureaucrat ( void );
		Bureaucrat& operator=(const Bureaucrat& burct);
		
	private:
		const std::string	name;
		unsigned int		grade;
		
};
#endif;