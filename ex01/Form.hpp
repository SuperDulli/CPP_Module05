#ifndef FORM_H
#define FORM_H

#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class Form {

public:

	class GradeTooHighException : public std::exception {
		std::string m_msg;
	public:
		GradeTooHighException(std::string const& msg) throw();
		~GradeTooHighException(void) throw();
		char const* what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
		std::string m_msg;
	public:
		GradeTooLowException(std::string const& msg) throw();
		~GradeTooLowException(void) throw();
		char const* what(void) const throw();
	};

	class FormAlreadySigned : public std::exception {
	public:
		char const* what(void) const throw();
	};

	Form(void);
	Form(std::string const& name, size_t gradeToSign, size_t gradeToExecute)
		throw (Form::GradeTooHighException, Form::GradeTooLowException);
	Form(Form const& other);
	~Form(void);

	Form& operator=(Form const& other);

	std::string const&	getName(void) const;
	bool				isSigned(void) const;
	size_t				getGradeToSign(void) const;
	size_t				getGradeToExecute(void) const;

	void beSigned(Bureaucrat const& bureaucrat)
		throw(Form::GradeTooLowException, Form::FormAlreadySigned);

private:

	std::string const	m_name;
	bool				m_isSigned;
	size_t const		m_gradeToSign;
	size_t const		m_gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif
