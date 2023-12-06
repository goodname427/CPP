#include <bits/stdc++.h>
using namespace std;

class Fraction;

std::ostream &operator<<(std::ostream &os, const Fraction &f);

class Fraction
{
private:
    int m_numerator; // 分子
    int m_denominator; // 分母

    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);

public:
    explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den)
    {
    }

    operator double() const
    {
        return static_cast<double>(m_numerator * 1.0 / m_denominator);
    }

    Fraction operator+(const Fraction &r)
    {
        return Fraction(m_numerator + r.m_numerator, m_denominator + r.m_denominator);
    }
};

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    return os << f.m_numerator << "/" << f.m_denominator;
}
