#include <iostream>
#include <string>
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		std::cout << "-- test execeptions --" << std::endl;

		ShrubberyCreationForm scf_copy = scf;
		RobotomyRequestForm rrf_copy = rrf;
		PresidentialPardonForm ppf_copy = ppf;

		std::cout << "- Test execute unsigned forms -" << std::endl;
		try {
			president.executeForm(scf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}
		try {
			president.executeForm(rrf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}
		try {
			president.executeForm(ppf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}

		std::cout << "- Test sign & execute forms with low grades -" << std::endl;
		std::cout << "- ShrubberyCreationForm -" << std::endl;
		try {
			creature.signForm(scf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}
		try {
			gardener.signForm(scf_copy);
			creature.executeForm(scf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}

		std::cout << "- RobotomyRequestForm -" << std::endl;
		try {
			gardener.signForm(rrf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}
		try {
			vogon.signForm(rrf_copy);
			gardener.executeForm(rrf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}

		std::cout << "- PresidentialPardonForm -" << std::endl;
		try {
			gardener.signForm(ppf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}
		try {
			president.signForm(ppf_copy);
			assistant.executeForm(ppf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}

	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "-- test positives --" << std::endl;

		ShrubberyCreationForm scf_copy = scf;
		RobotomyRequestForm rrf_copy = rrf;
		PresidentialPardonForm ppf_copy = ppf;

		try {
			gardener.signForm(scf_copy);
			gardener.executeForm(scf_copy);
			vogon.signForm(rrf_copy);
			robot.executeForm(rrf_copy);
			assistant.signForm(ppf_copy);
			president.executeForm(ppf_copy);
		} catch(std::exception& e) {
			handleException(e);
		}

	}
}
