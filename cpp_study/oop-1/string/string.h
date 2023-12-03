#ifndef __MYSTRING__
#define __MYSTRING__

#include <cstring>
#include <iostream>

class String;

std::ostream &operator<<(std::ostream &os, const String &s);

class String
{
private:
    char *m_data;

public:
    String(const char *cstr = 0);
    String(const String &str);
    String &operator=(const String &str);
    ~String();
    char *c_str() const { return m_data; }
};

inline String::String(const char *cstr)
{
    if (cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String &String::operator=(const String &str)
{
    if (this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);

    return *this;
}

inline String::~String()
{
    delete[] m_data;
}

inline std::ostream &operator<<(std::ostream &os, const String &s)
{
    return os << s.c_str();
}

#endif // __MYSTRING__