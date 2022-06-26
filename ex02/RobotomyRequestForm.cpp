#include <stdlib.h> // rand
#include <time.h>
#include <iostream>
#include <string>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequest", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: Form("RobotomyRequest-" + target, 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
	: Form(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), m_target(other.m_target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
	Form::operator=(other);
	return *this;
}

std::string const& RobotomyRequestForm::getTarget(void) const { return m_target; }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
throw(Form::FormNotSignedException, Form::GradeTooLowException) {
	Form::execute(executor);

	std::cout << "* drrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr *" << std::endl;
	srand(time(NULL));
	if (rand() % 2) {
		std::cout << m_target << " has been robotomized." << std::endl;
	} else {
		std::cout << "The robotomy failed. " << m_target << " remains human." << std::endl;
	}
}
