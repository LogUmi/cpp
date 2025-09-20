#ifndef ITER_HPP
# define ITER_HPP

//#include <cstddef>   // std::size_t
#include <iostream> 

template < typename T >
void	Iter( const T* ptr, const size_t l, void (*ft)( const T &))
{
	for (size_t i = 0; i < l; i++)
		ft( ptr[i] );
	return ;
}

template < typename T >
void	print_member (const T & memb)
{
	std::cout << memb << " ";
	return ;
}
#endif