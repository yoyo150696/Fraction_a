#include <iostream>
#include <sstream>


namespace ariel
{
    class Fraction {
        private:
        int numerator;
        int denominator;

        public:
        // Constructors
        Fraction();
        Fraction(int n);
        Fraction(int n, int d);
        Fraction(float f);

        // Operator overloading
        Fraction operator+(const Fraction& other) const;
        Fraction operator+(float f) const;
        friend Fraction operator+(float f, const Fraction& frac);
        Fraction operator-(const Fraction& other) const;
        Fraction operator-(float f) const;
        friend Fraction operator-(float f, const Fraction& frac);
        Fraction operator*(const Fraction& other) const;
        Fraction operator*(float f) const;
        friend Fraction operator*(float f, const Fraction& frac);
        Fraction operator/(const Fraction& other) const;
        Fraction operator/(float f) const;
        friend Fraction operator/(float f, const Fraction& frac);
        bool operator==(const Fraction& other) const;
        bool operator==(float f) const;
        friend bool operator==(float f, const Fraction& frac);
        bool operator!=(const Fraction& other) const;
        bool operator!=(float f) const;
        friend bool operator!=(float f, const Fraction& frac);
        bool operator>(const Fraction& other) const;
        bool operator>(float f) const;
        friend bool operator>(float f, const Fraction& frac);
        bool operator<(const Fraction& other) const;
        bool operator<(float f) const;
        friend bool operator<(float f, const Fraction& frac);
        bool operator>=(const Fraction& other) const;
        bool operator>=(float f) const;
        friend bool operator>=(float f, const Fraction& frac);
        bool operator<=(const Fraction& other) const;
        bool operator<=(float f) const;
        friend bool operator<=(float f, const Fraction& frac);
        Fraction operator++(); // Prefix ++
        Fraction operator++(int); // Postfix ++
        Fraction operator--(); // Prefix --
        Fraction operator--(int); // Postfix --
        friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
        friend std::ostream& operator<<(std::ostream& os, bool b);

        friend std::ostream& operator<<(std::ostream& os, const bool& value);
        // Other member functions
        Fraction reduce() const;
        float toFloat() const;
    };

    // Constructor with parameters
    Fraction::Fraction(int n, int d) {
        if (d == 0) {
            std::cerr << "Error: denominator cannot be zero" << std::endl;
            numerator = 0;
            denominator = 1;
        } else if (d < 0) {
            numerator = -n;
            denominator = -d;
        } else {
            numerator = n;
            denominator = d;
        }
    }
}

