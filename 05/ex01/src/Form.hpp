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
		Form(std::string name, int signing_grade, int executing_grade);
		~Form ( void );
		Form& operator=( const Form & other);

		const std::string	get_name( void ) const;
		bool				get_signing( void ) const;
		int					get_signing_grade( void ) const;
		int					get_executing_grade( void ) const;
		void				beSigned(const Bureaucrat & burct);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char *	what ( void ) const throw ();
		};
};

std::ostream & operator<<( std::ostream & o, const Form & paper);

#endif