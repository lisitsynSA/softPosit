#include "SoftPosit32.h"

#define EPS 0.001

const SoftPosit32& SoftPosit32::operator=(const SoftPosit32& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftPosit32 SoftPosit32::neg () const{
    SoftPosit32 tmp(-val);
    return tmp;
}

CMP SoftPosit32::cmp (const SoftPosit32& rhs) const{
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

float SoftPosit32::getFloat() const {
    return val;
}

const SoftPosit32& SoftPosit32::operator+= (const SoftPosit32& rhs) {
    val += rhs.val;
    return *this;
}

const SoftPosit32& SoftPosit32::operator*= (const SoftPosit32& rhs) {
    val *= rhs.val;
    return *this;
}

const SoftPosit32& SoftPosit32::operator/= (const SoftPosit32& rhs) {
    val /= rhs.val;
    return *this;
}
