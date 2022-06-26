#include <iostream>
#include <string>
#include "Color.hpp"
#include "Bureaucrat.hpp"

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

		try
		{
			std::cout << "try to instantiate a Bureaucrat with grade 0" << std::endl;
			Bureaucrat best("Best", 0);
		}
		catch(std::exception& e)
		{
			handleException(e);
		}

		try
		{
			std::cout << "try to instantiate a Bureaucrat with grade 9000" << std::endl;
			Bureaucrat worst("Worst", 9000);
		}
		catch(std::exception& e)
		{
			handleException(e);
		}

		Bureaucrat b;

		try
		{
			std::cout << b << std::endl;
			b.decrementGrade();
		}
		catch(std::exception& e)
		{
			handleException(e);
			std::cout << b << std::endl;
		}

		Bureaucrat c("Avag", 1);

		try
		{
			std::cout << c << std::endl;
			c.incrementGrade();
		}
		catch(std::exception& e)
		{
			handleException(e);
			std::cout << c << std::endl;
		}

	}
	std::cout << std::string(80, '-') << std::endl;
	{
		Bureaucrat bob("Bob", 42);

		std::cout << bob << std::endl;

		try
		{
			while (true) {
				bob.incrementGrade();
			}
		}
		catch(std::exception& e)
		{
			handleException(e);
			std::cout << bob << std::endl;
		}

		Bureaucrat hagrid("Hagrid", 81);
		// Bureaucrat hagrid("Hagrid", 80);
		Bureaucrat hermine("Hermine", 70);

		try
		{
			std::cout << "-- Hermine teaches Hagrid --" << std::endl;
			while (hagrid.getGrade() != hermine.getGrade())
			{
				hermine.decrementGrade();
				hagrid.incrementGrade();
			}
		}
		catch(std::exception& e)
		{
			handleException(e);
		}

		std::cout << hagrid << " " << hermine << std::endl;

	}
}
