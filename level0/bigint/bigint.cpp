#include "bigint.hpp"

bigint::bigint() : _val("0"){}

bigint::bigint(const bigint& other)
{
	this->_val = other._val;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		this->_val = other._val;
	}

	return(*this);
}

bigint::~bigint() {}

bigint::bigint(unsigned int val)
{
	while(true)
	{
		this->_val += val % 10 + '0';

		val /= 10;

		if (val == 0)
			break;
	}
}

bigint::bigint(std::string& val) : _val(val) {}

bigint bigint::operator+(const bigint& other) const
{
	std::string val;

	int i = 0;
	int t = 0;
	int o = 0;
	int r = 0;
	int tmp = 0;

	while (true)
	{
		t = '0';
		o = '0';

		if (i >= this->_val.size() && i >= other._val.size())
			break;
		if (i < this->_val.size())
			t = this->_val[i];
		if (i < other._val.size())
			o = other._val[i];

		tmp = (t - '0') + (o - '0') + r;
		val += tmp % 10 + '0';
		r = tmp / 10;

		i++;
	}

	bigint b(val);

	return(b);
}

bigint bigint::operator+=(const bigint& other)
{
	std::string val;

	int i = 0;
	int t = 0;
	int o = 0;
	int r = 0;
	int tmp = 0;

	while (true)
	{
		t = '0';
		o = '0';

		if (i >= this->_val.size() && i >= other._val.size())
			break;
		if (i < this->_val.size())
			t = this->_val[i];
		if (i < other._val.size())
			o = other._val[i];

		tmp = (t - '0') + (o - '0') + r;
		val += tmp % 10 + '0';
		r = tmp / 10;

		i++;
	}

	this-> _val = val;
	return (*this);
}

bigint bigint::operator++()
{
	std::string str("1");
	bigint un = str;

	*this += un;

	return (*this);
}

bigint bigint::operator++(int)
{
	std::string str("1");
	bigint un = str;
	bigint tmp = *this;

	*this += un;

	return (tmp);
}

bigint bigint::operator<<(size_t shift) const
{
	if (this->_val == "0")
		return (*this);

	bigint result(*this);

	for (size_t i = 0; i < shift; i++)
		result._val.insert(result._val.begin(), '0');

	return (result);	
}

bigint bigint::operator>>(size_t shift) const
{
	if (shift >= _val.size())
		return bigint(0);

	bigint result(*this);
	result._val.erase(0, shift);

	return result;
}

bigint& bigint::operator<<=(const bigint& shift)
{
	size_t n = shift.to_size_t(); // conversion bigint → size_t

	if (_val == "0")
		return *this;

	for (size_t i = 0; i < n; i++)
		_val.insert(_val.begin(), '0');

	return *this;
}


bigint& bigint::operator>>=(const bigint& shift)
{
	size_t n = shift.to_size_t();

	if (n >= _val.size())
	{
		_val = "0";
		return *this;
	}

	_val.erase(0, n);
	return *this;
}

size_t bigint::to_size_t() const
{
	size_t t = 0;

	for (size_t i = 0; i <= _val.size() - 1; i++)
	{
		t += (_val[i] - '0') * pow(10, i);
	}

	return (t);
}

std::ostream& operator<<(std::ostream& os, const bigint& big)
{
	for (int i = big._val.size() - 1; i >= 0 ; i--)
	{
		os << big._val[i];
	}

	return (os);
}