#include "ASpell.hpp"

ASpell::ASpell() : _name("default"), _effect("no effect"){}

ASpell::ASpell(const std::string& name, const std::string& effect) 
	: _name(name), _effect(effect) {}

ASpell::ASpell(const ASpell& other) : _name(other._name), _effect(other._effect) {}

ASpell& ASpell::operator=(const ASpell& other)
{
	_name = other._name;
	_effect = other._effect;
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
	return (this->_name);
}

std::string ASpell::getEffect() const
{
	return (this->_effect);
}

void ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}