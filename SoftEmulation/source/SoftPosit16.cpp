#include "SoftPosit16.h"

const SoftPosit16& SoftPosit16::operator=(const SoftPosit16& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftPosit16 SoftPosit16::neg () const{
    SoftPosit16 tmp(-val);
    return tmp;
}

CMP SoftPosit16::cmp (const SoftPosit16& rhs) const{
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

float SoftPosit16::getFloat() const {
    return (float) val.toDouble();
}

const SoftPosit16& SoftPosit16::operator+= (const SoftPosit16& rhs) {
    val += rhs.val;
    return *this;
}

const SoftPosit16& SoftPosit16::operator*= (const SoftPosit16& rhs) {
    val *= rhs.val;
    return *this;
}

const SoftPosit16& SoftPosit16::operator/= (const SoftPosit16& rhs) {
    val /= rhs.val;
    return *this;
}
