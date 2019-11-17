#include "SoftPosit8.h"

const SoftPosit8& SoftPosit8::operator=(const SoftPosit8& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftPosit8 SoftPosit8::neg () const{
    SoftPosit8 tmp(-val);
    return tmp;
}

CMP SoftPosit8::cmp (const SoftPosit8& rhs) const{
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

float SoftPosit8::getFloat() const {
    return (float) val.toDouble();
}

const SoftPosit8& SoftPosit8::operator+= (const SoftPosit8& rhs) {
    val += rhs.val;
    return *this;
}

const SoftPosit8& SoftPosit8::operator*= (const SoftPosit8& rhs) {
    val *= rhs.val;
    return *this;
}

const SoftPosit8& SoftPosit8::operator/= (const SoftPosit8& rhs) {
    val /= rhs.val;
    return *this;
}
