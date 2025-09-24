/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:36:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/24 18:16:24 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
typename T::const_iterator	easyfind(const T & data, const int n)
{
	typename	T::const_iterator it = std::find(data.begin(), data.end(), n);
	if (it == data.end())
		throw std::runtime_error("easyfind: value not found");
	return (it);
}
