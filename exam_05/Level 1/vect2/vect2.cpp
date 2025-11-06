#include "vect2.hpp"

std::ostream& operator<<(std::ostream &os, const vect2 &vec)
{
	os << "{" << vec[0] << ", " << vec[1] << "}";
	return os;
}

vect2 operator*(int nbr, vect2 &vec)
{
	return vec * nbr;
}
