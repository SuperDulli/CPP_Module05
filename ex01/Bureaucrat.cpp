#include <iostream>
#include <string>
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): m_grade(150) {}

Bureaucrat::Bureaucrat(std::string const& name, size_t grade)
throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
	: m_name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException("highest possible grade is 1");
	}
	if (150 < grade) {
		throw Bureaucrat::GradeTooLowException("lowest possiblew grade is 150");
	}
	this->m_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& other)
	: m_name(other.m_name), m_grade(other.m_grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
	std::cout << "Bureaucrat copy assignment operator: name will not be copied" << std::endl;
	// this->m_name = other.m_name; // can't assign to const
	this->m_grade = other.m_grade;
	return *this;
}

std::string const& Bureaucrat::getName(void) const { return m_name; }

size_t Bureaucrat::getGrade(void) const { return m_grade; }

void Bureaucrat::incrementGrade(void) throw(Bureaucrat::GradeTooHighException) {
	std::cout
	<< "increment grade(" << this->m_grade << ") of " << this->m_name
	<< std::endl;
	if (this->m_grade == 1) {
		throw Bureaucrat::GradeTooHighException("already the highest grade");
	}
	this->m_grade--;
}

void Bureaucrat::decrementGrade(void) throw(Bureaucrat::GradeTooLowException) {
	std::cout
	<< "decrement grade(" << this->m_grade << ") of " << this->m_name
	<< std::endl;
	if (this->m_grade == 150) {
		throw Bureaucrat::GradeTooLowException("already the lowest grade");
	}
	this->m_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const& msg) throw()
	: m_msg(msg) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

char const* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return m_msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const& msg) throw()
	: m_msg(msg) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

char const* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return m_msg.c_str();
}

void Bureaucrat::signForm(Form& form) const {
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< *this << " couldn't sign " << form << " because " << e.what()
		<< Color::Modifier()
		<< std::endl;
	}

}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b) {
	std::string const displayName = (b.getName().empty()) ? "<no-name>" : b.getName();
	os << "Bureaucrat(name=" << displayName << ", grade=" << b.getGrade() << ")";
	return os;
}

