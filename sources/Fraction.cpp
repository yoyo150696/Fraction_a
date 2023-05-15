#include "Fraction.hpp"
namespace ariel{
   
    void Fraction::reduce(){
        int gcd = std::__gcd(abs(numerator),abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
    }
    Fraction Fraction::reduce(int rnumerator,int rdenominator){
        int gcd = std::__gcd(abs(rnumerator),abs(rdenominator));
        rnumerator /= gcd;
        rdenominator /= gcd;
        return{rnumerator,rdenominator};
    }


    Fraction::Fraction(){
        numerator = 0;
        denominator = 1;
    }
    Fraction::~Fraction(){

    }
    Fraction::Fraction(Fraction& other){}
    Fraction& Fraction::operator=(Fraction& other){
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }
    Fraction::Fraction(float f){
        int power = 1;
        while (f != (int)f && power < 1000)
        {
            f *= 10;
            power *= 10;
        }
        numerator = f;
        denominator = power;
        reduce();
    }

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
        reduce();
    }
    Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    }

    //overload +
    Fraction Fraction::operator+(const Fraction& other){
        int new_numerator = (numerator*other.denominator) + (other.numerator * denominator);
        int new_denominator = (denominator*other.denominator);
        return reduce(new_numerator,new_denominator);
    }
    Fraction Fraction::operator+(float f){
        return (*this + Fraction(f));
    }
    Fraction operator+(float f, const Fraction& other) {
        return Fraction(f) + other;
    }
    //overload -
    Fraction Fraction::operator-(const Fraction& other){
        int new_numerator = (numerator*other.denominator) - (other.numerator * denominator);
        int new_denominator = (denominator*other.denominator);
        return reduce(new_numerator,new_denominator);
    }
    Fraction Fraction::operator-(float f){
        return (*this - Fraction(f));
    }
    
    Fraction operator-(float f, const Fraction& other) {
        return Fraction(f) - other;
    }
    //overload *
    Fraction Fraction::operator*(const Fraction& other){
        int new_numerator = (numerator*other.numerator);
        int new_denominator = (denominator*other.denominator);
        return reduce(new_numerator,new_denominator);
    }
    Fraction Fraction::operator*(float f){
        return (*this * Fraction(f));
    }
    
    Fraction operator*(float f, const Fraction& other) {
        return Fraction(f) * other;
    }
    //overload /
    Fraction Fraction::operator/(const Fraction& other){
        if(other.numerator == 0)
            throw ("frac canot be 0");
        int new_numerator = (numerator*other.denominator);
        int new_denominator = (denominator*other.numerator);
        return reduce(new_numerator,new_denominator);
    }
    Fraction Fraction::operator/(float f){
        return (*this / Fraction(f));
    }
    
    Fraction operator/(float f, const Fraction& other) {
        return Fraction(f) / other;
    }
    //overload ==
    bool Fraction::operator==(Fraction other){
        int this_gcd = std::__gcd(abs(numerator),abs(denominator));
        int other_gcd = std::__gcd(abs(numerator),abs(denominator));
        return ((numerator/this_gcd == other.numerator/other_gcd) && (denominator/this_gcd == other.denominator/this_gcd));
    }
    bool Fraction::operator==(float f){
        return *this == Fraction(f);
    }
    bool operator==(float f, const Fraction& frac){
        return (f == frac);
    }
    //ovaerload >
    bool Fraction::operator>(const Fraction& other){
        return ((numerator * other.denominator) > (other.numerator * denominator));
    }
    bool Fraction::operator>(float f){
        return (*this > Fraction(f));
    }
    bool operator>(float f, const Fraction& frac){
        return (Fraction(f) > frac);
    }
    //ovaerload <
    bool Fraction::operator<(const Fraction& other){
        return ((numerator * other.denominator) < (other.numerator * denominator));
    }
    bool Fraction::operator<(float f){
        return (*this < Fraction(f));
    }
    bool operator<(float f, const Fraction& frac){
        return (Fraction(f) < frac);
    }
    //overload >=
    bool Fraction::operator>=(const Fraction& other){
        return !(*this < other);
    }
    bool Fraction::operator>=(float f){
        return !(*this < f);
    }
    bool operator>=(float f,const Fraction& frac){
        return !(Fraction(f) < frac);
    }
    //overload <=
    bool Fraction::operator<=(const Fraction& other){
        return !(*this > other);
    }
    bool Fraction::operator<=(float f){
        return !(*this > f);
    }
    bool operator<=(float f,const Fraction& frac){
        return !(Fraction(f) > frac);
    }
    //overload prefix and postfix for ++ and --
    
    Fraction Fraction::operator++() {
        numerator += denominator;

        reduce();

        return *this;
    }
    

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction Fraction::operator--() {
        numerator -= denominator;

        reduce();

        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }
    //overload =
    Fraction& Fraction::operator=(const Fraction& other){
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }
    Fraction& Fraction::operator=(float f){
        *this = Fraction(f);
        return *this;
    }
    //overload <<
    std::ostream& operator<<(std::ostream& os, const ariel::Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
        }
    //overload >>
    std::istream& operator>>(std::istream& is, Fraction& frac){
        int n,d;
        char s;
        is >> n >> s >> d;
        if ( s != '/')
            throw("need to be slash");
        frac = Fraction(n,d);
        return is;
    }    
}
