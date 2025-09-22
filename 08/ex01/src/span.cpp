/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/21 21:10:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
typename T::const_iterator	easyfind(const T & data, const int n)
{
	typename	T::const_iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		if (*it == n)
			break ;
	}
	if (it == data.end())
		throw std::runtime_error("easyfind: value not found");
	return (it);
}
