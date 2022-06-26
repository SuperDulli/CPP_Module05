#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include <string>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& other);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

	std::string const& getTarget(void) const;

	void execute(Bureaucrat const& executor) const
		throw(Form::FormNotSignedException, Form::GradeTooLowException, Form::CannotExecuteException);

private:

	std::string const m_target;

};

#endif
