#include "SoftFloat16.h"

const SoftFloat16& SoftFloat16::operator=(const SoftFloat16& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftFloat16 SoftFloat16::neg () const{
    SoftFloat16 tmp(-val);
    return tmp;
}

CMP SoftFloat16::cmp (const SoftFloat16& rhs) const{
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

float SoftFloat16::getFloat() const {
    return (float) val;
}

const SoftFloat16& SoftFloat16::operator+= (const SoftFloat16& rhs) {
    val += rhs.val;
    return *this;
}

const SoftFloat16& SoftFloat16::operator*= (const SoftFloat16& rhs) {
    val *= rhs.val;
    return *this;
}

const SoftFloat16& SoftFloat16::operator/= (const SoftFloat16& rhs) {
    val /= rhs.val;
    return *this;
}
