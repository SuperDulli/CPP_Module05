#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <string>
#include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& other);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

	std::string const& getTarget(void) const;

	void execute(Bureaucrat const& executor) const
		throw(Form::FormNotSignedException, Form::GradeTooLowException);

private:

	std::string const m_target;

};

#endif
