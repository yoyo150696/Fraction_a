#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>

namespace ariel
{
    class Fraction {

        public:
            int numerator;
            int denominator;
            void reduce();
            Fraction reduce(int rnumerator,int rdenominator);
            // Constructors
            Fraction();
            Fraction(const Fraction& f);
            Fraction(int n, int d);
            Fraction(float fnum);
            ~Fraction();
            Fraction(Fraction& other);
            Fraction& operator=(Fraction& other);

            // Operator overloading

            // + overload
            Fraction operator+(const Fraction& other);
            Fraction operator+( float f);
            friend Fraction operator+(float f, const Fraction& frac);
            // - overload
            Fraction operator-(const Fraction& other);
            Fraction operator-(float f);
            friend Fraction operator-(float f, const Fraction& frac);
            // * overload
            Fraction operator*(const Fraction& other);
            Fraction operator*(float f);
            friend Fraction operator*(float f, const Fraction& frac);
            // / overload
            Fraction operator/(const Fraction& other);
            Fraction operator/(float f);
            friend Fraction operator/(float f, const Fraction& frac);
            // == overload
            bool operator==(Fraction other);
            bool operator==(float f);
            friend bool operator==(float f, const Fraction& frac);
            // != overload
            bool operator!=(const Fraction& other);
            bool operator!=(float f);
            friend bool operator!=(float f, const Fraction& frac);
            // > overload
            bool operator>(const Fraction& other);
            bool operator>(float f);
            friend bool operator>(float f, const Fraction& frac);
            // < overload
            bool operator<(const Fraction& other);
            bool operator<(float f);
            friend bool operator<(float f, const Fraction& frac);
            // >= overload
            bool operator>=(const Fraction& other);
            bool operator>=(float f);
            friend bool operator>=(float f, const Fraction& frac);
            // <= overload
            bool operator<=(const Fraction& other);
            bool operator<=(float f);
            friend bool operator<=(float f, const Fraction& frac);
            //prefix and postfix for ++ and --
            Fraction operator++();
            Fraction operator++(int);
            Fraction operator--();
            Fraction operator--(int);
            //overload =
            Fraction& operator=(const Fraction& other);
            Fraction& operator=(float f);
            friend std::ostream& operator<<(std::ostream& os, const ariel::Fraction& frac);
            friend std::istream& operator>>(std::istream& is, const ariel::Fraction& frac);
    };
}

