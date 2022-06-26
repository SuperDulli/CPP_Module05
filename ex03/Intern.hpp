#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <ostream>
#include "Form.hpp"

class Intern {

public:

	Intern(void);
	Intern(Intern const& other);
	~Intern(void);

	Intern& operator=(Intern const&);

	Form* makeForm(std::string const& formName, std::string const& target) const;

};

#endif
