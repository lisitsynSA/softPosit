#include "SoftQuire8.h"

const SoftQuire8& SoftQuire8::operator=(const SoftQuire8& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftQuire8 SoftQuire8::neg () const{
    SoftQuire8 tmp(val);
    tmp.val.value = -tmp.val.value;
    return tmp;
}

CMP SoftQuire8::cmp (const SoftQuire8& rhs) const{
    SoftQuire8 tmp(val);
    SoftQuire8 rtmp(rhs.val);
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

float SoftQuire8::getFloat() const {
    SoftQuire8 tmp(val);
    return (float) tmp.val.toPosit().toDouble();
}

const SoftQuire8& SoftQuire8::operator+= (const SoftQuire8& rhs) {
    val.value += rhs.val.value;
    return *this;
}

const SoftQuire8& SoftQuire8::operator*= (const SoftQuire8& rhs) {
    SoftQuire8 tmp(0.0);
    SoftQuire8 rtmp(rhs.val);
    tmp.val.qma(rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftQuire8& SoftQuire8::operator/= (const SoftQuire8& rhs) {
    SoftQuire8 tmp(0.0);
    SoftQuire8 rtmp(rhs.val);
    tmp.val.qma(1.0/rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftQuire8& SoftQuire8::qma(const SoftQuire8& rhs1, const SoftQuire8& rhs2)
{
    SoftQuire8 rtmp1(rhs1.val);
    SoftQuire8 rtmp2(rhs2.val);
    val.qma(rtmp1.val.toPosit(), rtmp2.val.toPosit());
    return *this;
}

const SoftQuire8& SoftQuire8::qms(const SoftQuire8& rhs1, const SoftQuire8& rhs2)
{
    SoftQuire8 rtmp1(rhs1.val);
    SoftQuire8 rtmp2(rhs2.val);
    val.qms(rtmp1.val.toPosit(), rtmp2.val.toPosit());
    return *this;
}
