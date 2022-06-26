#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& other);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

	std::string const& getTarget(void) const;

	void execute(Bureaucrat const& executor) const
		throw(Form::FormNotSignedException, Form::GradeTooLowException);

private:

	std::string const m_target;
};

#endif
