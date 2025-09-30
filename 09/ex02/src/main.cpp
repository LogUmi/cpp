/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/30 13:24:00 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << "Error: One RPN string parameter needed" << std::endl;
		return (1);
	}
	RPN calcul;
	return (calcul.exec(argv[1]));
}
