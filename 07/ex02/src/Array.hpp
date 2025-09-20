#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstddef>

template < typename T >
class Array
{
	private:
		T*				data;
		unsigned int	n;
	public:
		Array ( void ):data(0), n(0){};
		Array ( unsigned int n ):data(0), n(n)
		{
			data = new T[n]();
		}
		Array ( const Array & other)
		{
			this->n = other.n;
			this->data = new T[this->n];
			for (unsigned int i = 0; i < this->n; i++)
				this->data[i] = other.data[i];
		}
		~Array ( void ){delete[] this->data;}
		
		Array &	operator=( const Array & other)
		{
			if (this != &other)
			{
				this->n = other.n;
				delete[] this->data;
				this->data = new T[this->n];
				for (unsigned int i = 0; i < this->n; i++)
					this->data[i] = other.data[i];
			}
			return (*this);
		}
		
		T & operator[]( const std::size_t idx )
		{
			if (idx >= this->n)
				throw std::out_of_range("array index");
			return (this->data[idx]);
		}
		const T & operator[]( const std::size_t idx ) const
		{
			if (idx >= this->n)
				throw std::out_of_range("array index");
			return (this->data[idx]);
		}

		unsigned int size() const { return this->n; }
};
#endif