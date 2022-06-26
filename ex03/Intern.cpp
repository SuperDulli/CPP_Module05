#include <iostream>
#include <string>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const& other) { (void) other; }

Intern::~Intern(void) {}

Intern& Intern::operator=(Intern const& other) {
	(void) other;
	return *this;
}

Form* Intern::makeForm(std::string const& formName, std::string const& target) const {
	Form* form;
	std::string validNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	size_t const count = 3;

	int formNbr = -1;
	for (size_t i = 0; i < count; i++)
	{
		if (formName == validNames[i]) {
			formNbr = i;
			break;
		}
	}

	switch (formNbr)
	{
	case 0:
		form = new ShrubberyCreationForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new PresidentialPardonForm(target);
		break;
	default:
		form = NULL;
		std::cerr << "There is no form for: " << formName << std::endl;
		break;
	}

	if (form) {
		std::cout << "Intern creates " << *form << std::endl;
	}

	return form;
}
