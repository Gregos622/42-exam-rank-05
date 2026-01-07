#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) :
	_name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName() const
{
	return (this->_name);
}

const std::string& Warlock::getTitle() const
{	
	return (this->_title);
}

void Warlock::setTitle(const std::string& title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_title  << "!" << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell != nullptr)
    {
        std::map<std::string, ASpell *>::iterator it = _SpellBook.find(spell->getName());
        if (it == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string spellName)
{
    std::map<std::string, ASpell *>::iterator it = _SpellBook.find(spellName);

    if (it != _SpellBook.end())
    {
        delete it->second;
        _SpellBook.erase(spellName);
    }
}

void Warlock::launchSpell(std::string spellName, const ATarget &src)
{
    std::map<std::string, ASpell *>::iterator it = _SpellBook.find(spellName);

    if (it != _SpellBook.end())
        it->second->launch(src);
}