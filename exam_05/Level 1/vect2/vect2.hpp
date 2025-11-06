
// // 🧠 2. Unary vs. binary operators
// // Unary operators act on one operand.
// // The operand is the object itself (*this).
// // → no explicit parameters.
// // Binary operators act on two operands.
// // The left operand is the object (*this), the right operand is a parameter.


#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>

class vect2{

	private:
	
		int x;
		int y;
		
	public:
		vect2(): x(0), y(0) {}
		vect2(int x_var, int y_var){
			x = x_var;
			y = y_var;
		}
		vect2(const vect2& ref)
		{
			x= ref.x;
			y= ref.y;
		}
		vect2& operator=(const vect2& ref)
		{
			if(this != &ref)
			{
				x= ref.x;
				y= ref.y;	
			}
			return *this;
		}
		~vect2(){}
		
		
	//////////////////////////////////
	
	vect2 operator++(int)
	{
		vect2 temp(*this);
		x++;
		y++;
		return temp;
	}
	
	vect2 operator--(int)
	{
		vect2 temp(*this);
		x--;
		y--;
		return temp;
	}
	vect2& operator++()
	{
		x++;
		y++;
		return *this;
	}
	vect2& operator--()
	{
		x--;
		y--;
		return *this;
	}
	
	//////////////////////////////
	
	vect2& operator+=(const vect2& oth)
	{
		x += oth.x;
		y += oth.y;
		return *this;
	}
	vect2& operator-=(const vect2& oth)
	{
		x -= oth.x;
		y -= oth.y;
		return *this;
	}
	vect2& operator*=(int nbr)
	{
		x *= nbr;
		y *= nbr;
		return *this;
	}
	
	//////////////////////////////
	
	vect2 operator+(const vect2& oth) const
	{
		return vect2(x + oth.x, y + oth.y);
	}
	
	vect2 operator-(const vect2& oth)
	{
		return vect2(x - oth.x, y - oth.y);
	}
	
	vect2 operator*(int nbr) const
	{
		return vect2(x * nbr, y * nbr);
	}
	
	
	/////////////////////////////////
	
	bool operator==(const vect2& oth)
	{
		return (x == oth.x && y == oth.y);
	}
	
	bool operator!=(const vect2& oth)
	{
		return !(x == oth.x && y == oth.y);
	}
	
	////////////////////////////////////
	int operator[](int i) const
	{
		if(i == 0)
		{
			return x;
		}
		return y;
	}
	int& operator[](int i)
	{
		if(i == 0)
		{
			return x;
		}
		return y;
	}
	

	////////////////////////////////
	vect2 operator-()
	{
		return vect2(-x, -y); //NOT: x *= -1, y *= -1 because this modifies the actual object (which is not what we want)
	}
	
};


std::ostream& operator<<(std::ostream &os, const vect2 &vec);
vect2 operator*(int nbr, vect2 &vec);


#endif
