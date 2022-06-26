#include <iostream>
#include <string>
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

void handleException(std::exception& e) {
	std::cerr
	<< Color::Modifier(Color::FG_RED)
	<< e.what()
	<< Color::Modifier()
	<< std::endl;
}

int main(void) {
	std::cout << "--- Test begin ---" << std::endl;
	{
		std::cout << "-- test execeptions --" << std::endl;

		try {
			std::cout << "try to create a form with grades 0, 0" << std::endl;
			Form a("A-27b", 0, 0);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 42, 0" << std::endl;
			Form a("A-27b", 42, 0);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 0, 42" << std::endl;
			Form a("A-27b", 0, 42);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 151, 0" << std::endl;
			Form a("A-27b", 151, 0);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 0, 151" << std::endl;
			Form a("A-27b", 0, 151);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 1, 151" << std::endl;
			Form a("A-27b", 1, 151);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 151, 1" << std::endl;
			Form a("A-27b", 151, 1);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "try to create a form with grades 151, 151" << std::endl;
			Form a("A-27b", 151, 151);
			std::cout << a << std::endl;
		} catch (std::exception& e) {
			handleException(e);
		}

		try {
			std::cout << "bob tries to sign a form he should't be able to sign" << std::endl;
			Form a("A-27b", 1, 1);
			Bureaucrat b("Bob", 2);

			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
		} catch (std::exception& e) {
			handleException(e);
		}

	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "-- test positive examples --" << std::endl;

		Form f("Passierschein-A38", 1, 1);

		Bureaucrat caesar("Caesar", 1);
		Bureaucrat brutus("Brutus", 150);


		try {
			std::cout << "Let " << f.getName() << " be signed by Brutus " << brutus << std::endl;
			f.beSigned(brutus);
		} catch (std::exception& e) {
			handleException(e);
			std::cout << "Let caesar sign it" << std::endl;
			caesar.signForm(f);
		}

		brutus.signForm(f);

		std::cout << f << std::endl;
	}
}
