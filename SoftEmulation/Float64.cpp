#include "Float64.h"

#define EPS 0.001

const Float64& Float64::operator=(const Float64& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const Float64 Float64::neg () const{
    Float64 tmp(-val);
    return tmp;
}

CMP Float64::cmp (const Float64& rhs) const{
    if (this == &rhs) {
        return CMP::EQ;
    }
    if ((val+EPS) < rhs.val){
        return CMP::LT;
    }
    if ((val-EPS) > rhs.val){
        return CMP::GT;
    }
    return CMP::EQ;
}

Float64::operator float() const {
    return (float)val;
}

const Float64& Float64::operator+= (const Float64& rhs) {
    val += rhs.val;
    return *this;
}

const Float64& Float64::operator-= (const Float64& rhs) {
    val -= rhs.val;
    return *this;
}

const Float64& Float64::operator*= (const Float64& rhs) {
    val *= rhs.val;
    return *this;
}

const Float64& Float64::operator/= (const Float64& rhs) {
    val /= rhs.val;
    return *this;
}
