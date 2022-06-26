#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("PresidentialPardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: Form("PresidentialPardon-" + target, 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
	: Form(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), m_target(other.m_target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
	Form::operator=(other);
	return *this;
}

std::string const& PresidentialPardonForm::getTarget(void) const { return m_target; }

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
throw(Form::FormNotSignedException, Form::GradeTooLowException) {
	Form::execute(executor);

	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
