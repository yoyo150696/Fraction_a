#include <iostream>
#include <sstream>

class Fraction {
private:
    int numerator;
    int denominator;
    
public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n) : numerator(n), denominator(1) {}
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
    friend std::istream& operator>>(std::istream& is, Fraction& frac);
    
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

// Constructor from float
Fraction::Fraction(float f) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3) << f;
    std::string s = ss.str();
    size_t dotPos = s.find('.');
    size_t len = s.length();
    int n = 0;
    int d = 1;
    if (dotPos != std::string::npos) {
        int wholePart = std::stoi(s.substr(0, dotPos));
        n = wholePart * 10;
        int decimalPart = std::stoi(s.substr(dotPos+1, len-dotPos-1));
        int numDigits = len - dotPos - 1;
        while
