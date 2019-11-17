#include "SoftQuire16.h"

const uint64_t MAX_UINT = 18446744073709551615UL;

const SoftQuire16& SoftQuire16::operator=(const SoftQuire16& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftQuire16 SoftQuire16::neg () const{
    SoftQuire16 tmp(val);
    tmp.val.lvalue = MAX_UINT - val.lvalue;
    tmp.val.rvalue = -val.rvalue;
    return tmp;
}

CMP SoftQuire16::cmp (const SoftQuire16& rhs) const{
    SoftQuire16 tmp(val);
    SoftQuire16 rtmp(rhs.val);
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

float SoftQuire16::getFloat() const {
    SoftQuire16 tmp(val);
    return (float) tmp.val.toPosit().toDouble();
}

const SoftQuire16& SoftQuire16::operator+= (const SoftQuire16& rhs) {
    uint64_t rvalue = val.rvalue;
    val.rvalue += rhs.val.rvalue;
    val.lvalue += rhs.val.lvalue;
    if (val.rvalue < rhs.val.rvalue || val.rvalue < rvalue)
        val.lvalue += 1;
    return *this;
}

const SoftQuire16& SoftQuire16::operator*= (const SoftQuire16& rhs) {
    SoftQuire16 tmp(0.0);
    SoftQuire16 rtmp(rhs.val);
    tmp.val.qma(rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftQuire16& SoftQuire16::operator/= (const SoftQuire16& rhs) {
    SoftQuire16 tmp(0.0);
    SoftQuire16 rtmp(rhs.val);
    tmp.val.qma(1.0/rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftQuire16& SoftQuire16::qma(const SoftQuire16& rhs1, const SoftQuire16& rhs2)
{
    SoftQuire16 rtmp1(rhs1.val);
    SoftQuire16 rtmp2(rhs2.val);
    val.qma(rtmp1.val.toPosit(), rtmp2.val.toPosit());
    return *this;
}

const SoftQuire16& SoftQuire16::qms(const SoftQuire16& rhs1, const SoftQuire16& rhs2)
{
    SoftQuire16 rtmp1(rhs1.val);
    SoftQuire16 rtmp2(rhs2.val);
    val.qms(rtmp1.val.toPosit(), rtmp2.val.toPosit());
    return *this;
}
