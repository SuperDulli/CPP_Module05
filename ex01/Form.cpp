#include <iostream>
#include <string>
#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(std::string const& msg) throw()
	: m_msg(msg) {}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

char const* Form::GradeTooHighException::what(void) const throw() {
	return m_msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string const& msg) throw()
	: m_msg(msg) {}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

char const* Form::GradeTooLowException::what(void) const throw() {
	return m_msg.c_str();
}

char const* Form::FormAlreadySigned::what(void) const throw() {
	return "form is already signed";
}

Form::Form(void): m_isSigned(false), m_gradeToSign(1), m_gradeToExecute(1) {}

Form::Form(std::string const& name, size_t gradeToSign, size_t gradeToExecute)
throw (Form::GradeTooHighException, Form::GradeTooLowException):
	m_name(name),
	m_isSigned(false),
	m_gradeToSign(gradeToSign),
	m_gradeToExecute(gradeToExecute) {
		if (gradeToSign < 1 || gradeToExecute < 1) {
			throw Form::GradeTooHighException("the highest possible Grade is 1");
		}
		if (gradeToSign > 150 || gradeToExecute > 150) {
			throw Form::GradeTooLowException("the lowest possible grade is 150");
		}
}

Form::Form(Form const& other):
	m_name(other.m_name),
	m_isSigned(other.m_isSigned),
	m_gradeToSign(other.m_gradeToSign),
	m_gradeToExecute(other.m_gradeToExecute) {}

Form::~Form(void) {}

Form& Form::operator=(Form const& other) {
	std::cout << "Form Copy assignment operator: only the isSigned value is copied" << std::endl;
	this->m_isSigned = other.m_isSigned;
	return *this;
}

std::string const& Form::getName(void) const { return m_name; }

bool Form::isSigned(void) const { return m_isSigned; }

size_t Form::getGradeToSign(void) const { return m_gradeToSign; }

size_t Form::getGradeToExecute(void) const { return m_gradeToExecute; }

void Form::beSigned(Bureaucrat const& bureaucrat)
throw(Form::GradeTooLowException, Form::FormAlreadySigned) {
	if (this->m_isSigned) {
		throw Form::FormAlreadySigned();
	}
	if (bureaucrat.getGrade() > this->m_gradeToSign) {
		throw Form::GradeTooLowException("the bureaucrat's grade is too low to sign this form");
	}
	this->m_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form const& form) {
	return os
	<< "Form ("
	<< "name=" << form.getName() << ", "
	<< "isSigned=" << form.isSigned() << ", "
	<< "gradeToSign=" << form.getGradeToSign() << ", "
	<< "gradeToExecute=" << form.getGradeToExecute()
	<< ")";
}
