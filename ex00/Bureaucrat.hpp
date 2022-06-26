#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <ostream>

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception {
		std::string m_msg;
	public:
		GradeTooHighException(std::string const& msg) throw();
		virtual ~GradeTooHighException(void) throw();
		virtual char const* what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
		std::string m_msg;
	public:
		GradeTooLowException(std::string const& msg) throw();
		virtual ~GradeTooLowException(void) throw();
		virtual char const* what(void) const throw();
	};

	Bureaucrat(void);
	Bureaucrat(std::string const& name, size_t grade)
		throw (Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat(Bureaucrat const& other);
	~Bureaucrat(void);

	Bureaucrat& operator=(Bureaucrat const&);

	std::string const&	getName(void) const;
	size_t				getGrade(void) const;

	void	incrementGrade(void) throw(Bureaucrat::GradeTooHighException);
	void	decrementGrade(void) throw(Bureaucrat::GradeTooLowException);


private:

	std::string const	m_name;
	size_t				m_grade;


};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif
