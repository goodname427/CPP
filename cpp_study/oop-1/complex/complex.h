#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>
#include <iostream>

class complex;

complex &__doapl(complex *ths, const complex &r);
double imag(const complex &x);
double real(const complex &x);
complex operator+(const complex &x, const complex &y);
complex operator+(const complex &x, double y);
complex operator+(double x, const complex &y);
complex operator+(const complex &x);
complex operator-(const complex &x);
bool operator==(const complex &x, const complex &y);
bool operator==(const complex &x, double y);
bool operator==(double &x, const complex &y);
bool operator!=(const complex &x, const complex &y);
bool operator!=(const complex &x, double y);
bool operator!=(double &x, const complex &y);
complex conj(const complex &x);
std::ostream &operator<<(std::ostream &os, const complex &x);

class complex
{
private:
    // fields
    double re;
    double im;

    friend complex &__doapl(complex *, const complex &);

public:
    // properties
    double real() const { return re; }
    double imag() const { return im; }

public:
    // constructor
    complex(double r = 0, double i = 0) : re(r),
                                          im(i)
    {
    }

public:
    // operator overwrite
    complex &operator+=(const complex &);
};

// definition
inline complex &__doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline double imag(const complex &x)
{
    return x.imag();
}

inline double real(const complex &x)
{
    return x.real();
}

inline complex operator+(const complex &x, const complex &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(const complex &x, double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex operator+(double x, const complex &y)
{
    return complex(real(y) + x, imag(y));
}

inline complex operator+(const complex &x)
{
    return x;
}

inline complex operator-(const complex &x)
{
    return complex(-real(x), -imag(x));
}

inline bool operator==(const complex &x, const complex &y)
{
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool operator==(const complex &x, double y)
{
    return real(x) == y && imag(x) == 0;
}

inline bool operator==(double &x, const complex &y)
{
    return real(y) == x && imag(y) == 0;
}

inline bool operator!=(const complex &x, const complex &y)
{
    return real(x) != real(y) || imag(x) != imag(y);
}

inline bool operator!=(const complex &x, double y)
{
    return real(x) != y || imag(x) != 0;
}

inline bool operator!=(double &x, const complex &y)
{
    return real(y) != x || imag(y) != 0;
}

inline complex conj(const complex &x)
{
    return complex(real(x), -imag(x));
}

inline std::ostream &operator<<(std::ostream &os, const complex &x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

inline complex &complex::operator+=(const complex &r)
{
    return __doapl(this, r);
}

#endif // __COMPLEX__
