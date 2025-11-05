#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>

class vect2 {

    private:
        int _x;
        int _y;

    public:

        vect2(): _x(0), _y(0) {}
        vect2(int x, int y) 
        {
            _x = x;
            _y = y;
        }
        vect2(const vect2 &ref)
        {
            _x = ref._x;
            _y = ref._y;
        }
        vect2& operator=(const vect2 &ref)
        {
            if(this != &ref)
            {
                _x = ref._x;
                _y = ref._y;
            }
            return *this;
        }
        ~vect2(){}

        ////////////////////////////

        int operator[](const int i) const
        {
            if (i == 0)
            {
                return _x;
            }
            return _y;
        }

        int& operator[](const int i)
        {
            if(i == 0)
            {
                return _x;
            }
            return _y;
        }

        ///////////////////////////

        vect2 operator++(int)
        {
            vect2 temp(*this);
            _x += 1;
            _y += 1;
            return temp;
        }

        vect2 operator--(int)
        {
            vect2 temp(*this);
            _x -= 1;
            _y -= 1;
            return temp;
        }

        vect2& operator++()
        {
            _x += 1;
            _y += 1;
            return *this;
        }

        vect2& operator--()
        {
            _x -= 1;
            _y -= 1;
            return *this;
        }

        /////////////////////////////

        bool operator==(const vect2& oth)
        {
            return (_x == oth._x && _y == oth._y);
        }

        bool operator!=(const vect2& oth)
        {
            return !(_x == oth._x && _y == oth._y);
        }

        /////////////////////////////

        vect2 operator-()
        {
            return vect2(-_x, -_y);
        }

        ////////////////////////////

        vect2& operator+=(const vect2 &oth) 
        {
            _x += oth._x;
            _y += oth._y;
            return *this;
        }

        vect2& operator-=(const vect2 &oth) 
        {
            _x -= oth._x;
            _y -= oth._y;
            return *this;
        }

        vect2& operator*=(int nbr) 
        {
            _x *= nbr;
            _y *= nbr;
            return *this;
        }

       ////////////////////////

        vect2 operator-(const vect2 &oth) 
        {
            return vect2(_x - oth._x, _y - oth._y);
        }

        vect2 operator+(const vect2 &oth) const
        {
             return vect2(_x + oth._x, _y + oth._y);
        }

        vect2 operator*(int nbr) const
        {
            return vect2(_x * nbr, _y * nbr);
        }


        
};


std::ostream& operator<<(std::ostream &os, const vect2 &vec);

vect2 operator*(int nbr, const vect2 &vec);

#endif



// 🧠 2. Unary vs. binary operators
// Unary operators act on one operand.
// The operand is the object itself (*this).
// → no explicit parameters.
// Binary operators act on two operands.
// The left operand is the object (*this), the right operand is a parameter.