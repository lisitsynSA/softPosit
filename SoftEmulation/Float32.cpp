#include "Float32.h"

#define EPS 0.001

const Float32& Float32::operator=(const Float32& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const Float32 Float32::neg () const{
    Float32 tmp(-val);
    return tmp;
}

CMP Float32::cmp (const Float32& rhs) const{
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

float Float32::getFloat() const {
    return val;
}

const Float32& Float32::operator+= (const Float32& rhs) {
    val += rhs.val;
    return *this;
}

const Float32& Float32::operator*= (const Float32& rhs) {
    val *= rhs.val;
    return *this;
}

const Float32& Float32::operator/= (const Float32& rhs) {
    val /= rhs.val;
    return *this;
}
