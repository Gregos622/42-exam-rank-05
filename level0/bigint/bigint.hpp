#pragma once

#include <string>
#include <iostream>
#include <cmath>

class bigint
{

	private:
		std::string _val;

	public:
		bigint();
		bigint (const bigint& other);
		bigint& operator=(const bigint& other);
		~bigint();

		bigint(unsigned int val);
		bigint(std::string& val);
		bigint operator+(const bigint& other) const;
		bigint operator+=(const bigint& other);
		bigint operator++();
		bigint operator++(int);
		bigint operator<<(size_t shift) const;
		bigint operator>>(size_t shift) const;
		bigint& operator<<=(const bigint& shift);
		bigint& operator>>=(const bigint& shift);

		size_t to_size_t() const;

		friend std::ostream& operator<<(std::ostream& os, const bigint& big);
};