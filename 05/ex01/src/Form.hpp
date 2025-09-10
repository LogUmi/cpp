#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string 	name;
		bool				signing;
		const int			signing_grade;
		const int			executing_grade;

	public:
		Form( void );
		Form( const Form & other );
		~Form ( void );
		Form& operator=( const Form & other);

		const std::string	get_name() const;
		bool				get_signing() const;
		const int			get_signing_grade() const;
		const int			get_executing_grade() const;
		void				beSigned(const Bureaucrat & burct);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
};

std::ostream & operator<<( std::ostream & o, const Form & paper);

#endif