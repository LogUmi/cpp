/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:27:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/18 18:15:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "Data.hpp"

class Serializer
{
	private:
						Serializer( void );
						Serializer( const Serializer & other );
						~Serializer( void );
		Serializer & 	operator=( const Serializer & other );

	public:
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};
#endif