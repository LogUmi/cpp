#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	name;
		bool				signing;
		const int			signing_grade;
		const int			executing_grade;

	public:
				AForm( void );
				AForm( const AForm & other );
				AForm( std::string name, int signing_grade, int executing_grade );
		virtual	~AForm ( void );
		AForm& 	operator=( const AForm & other );

		const std::string	get_name( void ) const;
		bool				get_signing( void ) const;
		int					get_signing_grade( void ) const;
		int					get_executing_grade( void ) const;
		void				beSigned(const Bureaucrat & burct);
		void				is_Executable(Bureaucrat const & executor) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class FormNotSignedException: public std::exception
		{
			public:
			virtual const char *	what ( void ) const throw ();
		};

};

std::ostream & operator<<( std::ostream & o, const AForm & paper );

#endif