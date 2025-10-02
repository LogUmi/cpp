/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/10/02 17:03:08 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int main( int argc, char** argv )
{
	if (argc < 3)
	{
		std::cerr 	<< "Error: please type as parameters a positive integer sequence to be sorted (so more than one)"
					<< std::endl;
		return (1);
	}
	PmergeMe sorting;
	return (sorting.exec(argc - 1, argv));
}
