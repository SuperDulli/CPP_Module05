#include <iostream>
#include <string>
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void handleException(std::exception& e) {
	std::cerr
	<< Color::Modifier(Color::FG_RED)
	<< e.what()
	<< Color::Modifier()
	<< std::endl;
}

int main(void) {
	std::cout << "--- Test begin ---" << std::endl;
	Bureaucrat creature("Agrajag", 150);
	Bureaucrat gardener("Slartibartfast", 100);
	Bureaucrat vogon("Vogon Kwaltz", 50);
	Bureaucrat robot("Marvin the Paranoid Android", 42);
	Bureaucrat assistant("Trillian", 21);
	Bureaucrat president("Zaphod Beeblebrox", 1);

	std::cout << creature << std::endl;
	std::cout << gardener << std::endl;
	std::cout << vogon << std::endl;
	std::cout << robot << std::endl;
	std::cout << assistant << std::endl;
	std::cout << president << std::endl;

	ShrubberyCreationForm const		scf("Vogsphere");
	RobotomyRequestForm const		rrf("Arthur Dent");
	PresidentialPardonForm const	ppf("Ford Prefect");

	{
		std::cout << "-- test negatives --" << std::endl;

		Intern intern;
		Form* form;

		form = intern.makeForm("", "me");
		if (form) {
			std::cout << *form << std::endl;
		} else {
			std::cout << "form pointer is NULL" << std::endl;
		}

		form = intern.makeForm("abdsfsd", "me");
		if (form) {
			std::cout << *form << std::endl;
		} else {
			std::cout << "form pointer is NULL" << std::endl;
		}

		form = intern.makeForm("creation shrubbery", "home");
		if (form) {
			std::cout << *form << std::endl;
		} else {
			std::cout << "form pointer is NULL" << std::endl;
		}
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "-- test positives --" << std::endl;

		Intern intern;
		Form* form;

		form = intern.makeForm("robotomy request", "Bender");

		president.signForm(*form);
		president.executeForm(*form);

		delete form;

		form = intern.makeForm("presidential pardon", "Bender");

		president.signForm(*form);
		president.executeForm(*form);

		delete form;

		form = intern.makeForm("shrubbery creation", "home");

		president.signForm(*form);
		president.executeForm(*form);

		delete form;

	}
}
