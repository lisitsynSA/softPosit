#include "SoftPosit8.h"

const SoftPosit8& SoftPosit8::operator=(const SoftPosit8& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftPosit8 SoftPosit8::neg () const{
    SoftPosit8 tmp(val);
    tmp.val.value = -tmp.val.value;
    return tmp;
}

CMP SoftPosit8::cmp (const SoftPosit8& rhs) const{
    SoftPosit8 tmp(val);
    SoftPosit8 rtmp(rhs.val);
    if (this == &rhs) {
        return CMP::EQ;
    }
    if ((tmp.val.toPosit()+EPS) < rtmp.val.toPosit()){
        return CMP::LT;
    }
    if ((tmp.val.toPosit()-EPS) > rtmp.val.toPosit()){
        return CMP::GT;
    }
    return CMP::EQ;
}

float SoftPosit8::getFloat() const {
    SoftPosit8 tmp(val);
    return (float) tmp.val.toPosit().toDouble();
}

const SoftPosit8& SoftPosit8::operator+= (const SoftPosit8& rhs) {
    val.value += rhs.val.value;
    return *this;
}

const SoftPosit8& SoftPosit8::operator*= (const SoftPosit8& rhs) {
    SoftPosit8 tmp(0.0);
    SoftPosit8 rtmp(rhs.val);
    tmp.val.qma(rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftPosit8& SoftPosit8::operator/= (const SoftPosit8& rhs) {
    SoftPosit8 tmp(0.0);
    SoftPosit8 rtmp(rhs.val);
    tmp.val.qma(1.0/rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}
