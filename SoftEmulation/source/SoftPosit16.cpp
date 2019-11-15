#include "SoftPosit16.h"

const SoftPosit16& SoftPosit16::operator=(const SoftPosit16& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftPosit16 SoftPosit16::neg () const{
    SoftPosit16 tmp(val);
    SoftPosit16 res(0.0);
    res.val.qms((posit16) 1.0, tmp.val.toPosit());
    return res;
}

CMP SoftPosit16::cmp (const SoftPosit16& rhs) const{
    SoftPosit16 tmp(val);
    SoftPosit16 rtmp(rhs.val);
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

float SoftPosit16::getFloat() const {
    SoftPosit16 tmp(val);
    return (float) tmp.val.toPosit().toDouble();
}

const SoftPosit16& SoftPosit16::operator+= (const SoftPosit16& rhs) {
    SoftPosit16 rtmp(rhs.val);
    val.qma(rtmp.val.toPosit(), (posit16)1.0);
    return *this;
}

const SoftPosit16& SoftPosit16::operator*= (const SoftPosit16& rhs) {
    SoftPosit16 tmp(0.0);
    SoftPosit16 rtmp(rhs.val);
    tmp.val.qma(rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftPosit16& SoftPosit16::operator/= (const SoftPosit16& rhs) {
    SoftPosit16 tmp(0.0);
    SoftPosit16 rtmp(rhs.val);
    tmp.val.qma(1.0/rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}
