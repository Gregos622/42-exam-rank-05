#include "ATarget.hpp"

ATarget::ATarget() : _type("default"){}

ATarget::ATarget(const std::string& type) : _type(type) {}

ATarget::ATarget(const ATarget& other) : _type(other._type) {}

ATarget& ATarget::operator=(const ATarget& other)
{
	_type = other._type;
}

ATarget::~ATarget()
{

}

const std::string& ATarget::getType() const
{
	return (this->_type);
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << this->_type << " has been " << spell.getEffect() << "!" << std::endl;
}