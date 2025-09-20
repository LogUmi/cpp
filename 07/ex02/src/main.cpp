/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/20 18:52:19 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"


int main( void )
{
	int			i[5] = {1, 2, 3, 4, 5};
	float		f[5] = {6.5, 7.5, 8.5, 9.5, 10.5};
	double		d[5] = {11.5, 12.5, 13.5, 14.5, 15.5};
	void*		p[5] = {&i[0], &i[1], &i[2], &i[3], &i[4]};
	std::string	s[5] = {"un", "deux", "trois", "quatre", "cinq"};
	char		c[15] = "ceci est char*";
	int			j = 0;

	// ******** int *********
	{
		try
		{
			std::cout 	<< "********************************************" 
						<< "********************************************" 
						<< std::endl;
			std::cout 	<< "*** int ***" << std::endl;
			int	len = 5;
			Array<int> def;
			Array<int> a(len);
			for (j = 0; j < len; j++)
				a[j] = i[j];
			Array<int> cpy(a);
			std::cout << "Array def default created. size : " << def.size() << std::endl;
			std::cout << "Array a created        : ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() << std::endl;
			std::cout << "Array cpy copy created : ";
			for (j = 0; j < len; j++)
				std::cout << cpy[j] << " ";
			std::cout << " - size : " << cpy.size() << std::endl;
			std::cout << "Array cpy = def(empty) : ";
			cpy = def;
			std::cout << " - size : " << def.size() << std::endl;
			std::cout << "Array def(empty) = a   : ";
			def = a;
			for (j = 0; j < len; j++)
				std::cout << def[j] << " ";
			std::cout << " - size : " << def.size() <<std::endl;
			a[len - 1] = a[len - 1] + 10;
			std::cout << "change the a last index: ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() <<std::endl;
			std::cout << "trying bad index " << len << " ..." << std::endl;
			std::cout << a[len] << "It's strangely worked !!! "  << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// ******** floats *********
	{
		try
		{
			std::cout 	<< "********************************************" 
						<< "********************************************" 
						<< std::endl;
			std::cout 	<< "*** float ***" << std::endl;
			int	len = 5;
			Array<float> def;
			Array<float> a(len);
			for (j = 0; j < len; j++)
				a[j] = f[j];
			Array<float> cpy(a);
			std::cout << "Array def default created. size : " << def.size() << std::endl;
			std::cout << "Array a created        : ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() << std::endl;
			std::cout << "Array cpy copy created : ";
			for (j = 0; j < len; j++)
				std::cout << cpy[j] << " ";
			std::cout << " - size : " << cpy.size() << std::endl;
			std::cout << "Array cpy = def(empty) : ";
			cpy = def;
			std::cout << " - size : " << def.size() << std::endl;
			std::cout << "Array def(empty) = a   : ";
			def = a;
			for (j = 0; j < len; j++)
				std::cout << def[j] << " ";
			std::cout << " - size : " << def.size() <<std::endl;
			a[len - 1] = a[len - 1] + 10;
			std::cout << "change the a last index: ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() <<std::endl;
			std::cout << "trying bad index " << len << " ..." << std::endl;
			std::cout << a[len] << "It's strangely worked !!! "  << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// ******** double *********
	{
		try
		{
			std::cout 	<< "********************************************" 
						<< "********************************************" 
						<< std::endl;
			std::cout 	<< "*** double ***" << std::endl;
			int	len = 5;
			Array<double> def;
			Array<double> a(len);
			for (j = 0; j < len; j++)
				a[j] = d[j];
			Array<double> cpy(a);
			std::cout << "Array def default created. size : " << def.size() << std::endl;
			std::cout << "Array a created        : ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() << std::endl;
			std::cout << "Array cpy copy created : ";
			for (j = 0; j < len; j++)
				std::cout << cpy[j] << " ";
			std::cout << " - size : " << cpy.size() << std::endl;
			std::cout << "Array cpy = def(empty) : ";
			cpy = def;
			std::cout << " - size : " << def.size() << std::endl;
			std::cout << "Array def(empty) = a   : ";
			def = a;
			for (j = 0; j < len; j++)
				std::cout << def[j] << " ";
			std::cout << " - size : " << def.size() <<std::endl;
			a[len - 1] = a[len - 1] + 10;
			std::cout << "change the a last index: ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() <<std::endl;
			std::cout << "trying bad index " << len << " ..." << std::endl;
			std::cout << a[len] << "It's strangely worked !!! "  << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// ******** pointer *********
	{
		try
		{
			std::cout 	<< "********************************************" 
						<< "********************************************" 
						<< std::endl;
			std::cout 	<< "*** void* pointer ***" << std::endl;
			int	len = 5;
			Array<void*> def;
			Array<void*> a(len);
			for (j = 0; j < len; j++)
				a[j] = p[j];
			Array<void*> cpy(a);
			std::cout << "Array def default created. size : " << def.size() << std::endl;
			std::cout << "Array a created        : ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() << std::endl;
			std::cout << "Array cpy copy created : ";
			for (j = 0; j < len; j++)
				std::cout << cpy[j] << " ";
			std::cout << " - size : " << cpy.size() << std::endl;
			std::cout << "Array cpy = def(empty) : ";
			cpy = def;
			std::cout << " - size : " << def.size() << std::endl;
			std::cout << "Array def(empty) = a   : ";
			def = a;
			for (j = 0; j < len; j++)
				std::cout << def[j] << " ";
			std::cout << " - size : " << def.size() <<std::endl;
			a[len - 1] = a[0];
			std::cout << "change the a last index: ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() <<std::endl;
			std::cout << "trying bad index " << len << " ..." << std::endl;
			std::cout << a[len] << "It's strangely worked !!! "  << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// ******** std::string *********
	{
		try
		{
			std::cout 	<< "********************************************" 
						<< "********************************************" 
						<< std::endl;
			std::cout 	<< "*** std::string ***" << std::endl;
			int	len = 5;
			Array<std::string> def;
			Array<std::string> a(len);
			for (j = 0; j < len; j++)
				a[j] = s[j];
			Array<std::string> cpy(a);
			std::cout << "Array def default created. size : " << def.size() << std::endl;
			std::cout << "Array a created        : ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() << std::endl;
			std::cout << "Array cpy copy created : ";
			for (j = 0; j < len; j++)
				std::cout << cpy[j] << " ";
			std::cout << " - size : " << cpy.size() << std::endl;
			std::cout << "Array cpy = def(empty) : ";
			cpy = def;
			std::cout << " - size : " << def.size() << std::endl;
			std::cout << "Array def(empty) = a   : ";
			def = a;
			for (j = 0; j < len; j++)
				std::cout << def[j] << " ";
			std::cout << " - size : " << def.size() <<std::endl;
			a[len - 1] = a[len - 1] + "!!!";
			std::cout << "change the a last index: ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() <<std::endl;
			std::cout << "trying bad index " << len << " ..." << std::endl;
			std::cout << a[len] << "It's strangely worked !!! "  << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// ******** char *********
	{
		try
		{
			std::cout 	<< "********************************************" 
						<< "********************************************" 
						<< std::endl;
			std::cout 	<< "*** char ***" << std::endl;
			int	len = 15;
			Array<char> def;
			Array<char> a(len);
			for (j = 0; j < len; j++)
				a[j] = c[j];
			Array<char> cpy(a);
			std::cout << "Array def default created. size : " << def.size() << std::endl;
			std::cout << "Array a created        : ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() << std::endl;
			std::cout << "Array cpy copy created : ";
			for (j = 0; j < len; j++)
				std::cout << cpy[j] << " ";
			std::cout << " - size : " << cpy.size() << std::endl;
			std::cout << "Array cpy = def(empty) : ";
			cpy = def;
			std::cout << " - size : " << def.size() << std::endl;
			std::cout << "Array def(empty) = a   : ";
			def = a;
			for (j = 0; j < len; j++)
				std::cout << def[j] << " ";
			std::cout << " - size : " << def.size() <<std::endl;
			a[len - 1] = '!';
			std::cout << "change the a last index: ";
			for (j = 0; j < len; j++)
				std::cout << a[j] << " ";
			std::cout << " - size : " << a.size() <<std::endl;
			std::cout << "trying bad index " << len << " ..." << std::endl;
			std::cout << a[len] << "It's strangely worked !!! "  << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}