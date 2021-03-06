#ifndef SOFTTYPE_H
#define SOFTTYPE_H

#define EPS 0.001

enum CMP{
    EQ = 0,
    GT = 1,
    LT = 2
};

template <class T>
class softType
{
public:
    softType() {}
    virtual ~softType() {}

    virtual const T& operator=(const T& rhs) noexcept = 0;
    virtual const T neg() const = 0;
    virtual CMP cmp(const T& rhs) const = 0;
    virtual float getFloat() const = 0;

    virtual const T& operator+=(const T& rhs) = 0;
    virtual const T& operator*=(const T& rhs) = 0;
    virtual const T& operator/=(const T& rhs) = 0;
    virtual const T& qma(const T& rhs1, const T& rhs2)  { return *this += (rhs1*rhs2); };
    virtual const T& qms(const T& rhs1, const T& rhs2)  { return *this -= (rhs1*rhs2); };

    const T& operator-=(const T& rhs) { return *this += rhs.neg(); }
    const T operator+() const { return *this; }
    const T operator-() const { return neg(); }

    friend std::ostream& operator<<(std::ostream &os, const T& rhs)
    { return os << rhs.getFloat(); }
};

template <class T>
const T operator+(const T lhs, const T rhs)
{
    T tmp(lhs);
    tmp += rhs;
    return tmp;
}
template <class T>
const T operator+(const double lhs, const T rhs)
{
    T tmp(lhs);
    tmp += rhs;
    return tmp;
}

template <class T>
const T operator-(const T lhs, const T rhs)
{
    T tmp(lhs);
    tmp -= rhs;
    return tmp;
}

template <class T>
const T operator-(const double lhs, const T rhs)
{
    T tmp(lhs);
    tmp -= rhs;
    return tmp;
}

template <class T>
const T operator*(const T lhs, const T rhs)
{
    T tmp(lhs);
    tmp *= rhs;
    return tmp;
}

template <class T>
const T operator*(const double lhs, const T rhs)
{
    T tmp(lhs);
    tmp *= rhs;
    return tmp;
}

template <class T>
const T operator/(const T lhs, const T rhs)
{
    T tmp(lhs);
    tmp /= rhs;
    return tmp;
}

template <class T>
const T operator/(const double lhs, const T rhs)
{
    T tmp(lhs);
    tmp /= rhs;
    return tmp;
}

template <class T>
bool operator==(const T& lhs, const T& rhs)
{
    CMP res = lhs.cmp(rhs);
    if (res == CMP::EQ)
        return true;
    return false;
}

template <class T>
bool operator!=(const T& lhs, const T& rhs)
{
    CMP res = lhs.cmp(rhs);
    if (res != CMP::EQ)
        return true;
    return false;
}

template <class T>
bool operator<(const T& lhs, const T& rhs)
{
    CMP res = lhs.cmp(rhs);
    if (res == CMP::LT)
        return true;
    return false;
}

template <class T>
bool operator<=(const T& lhs, const T& rhs)
{
    CMP res = lhs.cmp(rhs);
    if (res == CMP::EQ || res == CMP::LT)
        return true;
    return false;
}

template <class T>
bool operator>(const T& lhs, const T& rhs)
{
    CMP res = lhs.cmp(rhs);
    if (res == CMP::GT)
        return true;
    return false;
}

template <class T>
bool operator>=(const T& lhs, const T& rhs)
{
    CMP res = lhs.cmp(rhs);
    if (res == CMP::EQ || res == CMP::GT)
        return true;
    return false;
}

#endif // SOFTTYPE_H
