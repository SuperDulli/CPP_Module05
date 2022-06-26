#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("ShrubberyCreation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: Form("ShrubberyCreation-" + target, 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
	: Form(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), m_target(other.m_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
	Form::operator=(other);
	return *this;
}

std::string const& ShrubberyCreationForm::getTarget(void) const { return m_target; }

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
throw(Form::FormNotSignedException, Form::GradeTooLowException, Form::CannotExecuteException) {
	Form::execute(executor);

	std::ifstream tree;
	std::ofstream file;

	std::string const treeFileName = "./trees_ASCII/jgs.txt";
	std::string const targetFileName = m_target + "_shrubbery";

	// tree.exceptions(std::ifstream::failbit);
	// file.exceptions(std::ifstream::failbit);

	tree.open(treeFileName.c_str());
	if (!tree.is_open()) {
		std::string const msg = "no trees found: can't open file " + treeFileName;
		throw Form::CannotExecuteException(msg);
	}
	file.open(targetFileName.c_str());
	if (!file.is_open()) {
		std::string const msg = "bad target: can't open file " + targetFileName;
		throw Form::CannotExecuteException(msg);
	}
	file << tree.rdbuf(); // copy the file

	tree.close();
	file.close();
}
