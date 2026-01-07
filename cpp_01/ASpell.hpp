#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include "ATarget.hpp"

class ASpell
{
	protected:
		std::string _name;
		std::string _effect;

	public:
		ASpell();
		ASpell(const std::string& name, const std::string& effect);
		ASpell(const ASpell& other);
		ASpell& operator=(const ASpell& other);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffect() const;

		virtual ASpell* clone() const = 0;

		void launch(ATarget const & target) const;
};

#endif