#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"
#include <string>
#include <iostream>

class Fwoosh : public ASpell
{
	private:

	public:
		Fwoosh();
		~Fwoosh();

		ASpell* clone() const;
};

#endif