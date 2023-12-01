#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

class ostream;
class complex;

complex &__doapl(complex *ths, const complex &r);

class complex
{
private:
    double re;
    double im;

    friend complex &__doapl(complex *, const complex &);

public:
    complex(double r = 0, double i = 0) : re(r),
                                          im(i)
    {
    }

    complex &operator+=(const complex &);

    double real() const { return re; }
    double imag() const { return im; }
};

complex &complex::operator+=(const complex &other)
{
    return *this;
}

#endif // __COMPLEX__
