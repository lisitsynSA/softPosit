#include "SoftPosit32.h"

const uint64_t MAX_UINT = 18446744073709551615UL;

const SoftPosit32& SoftPosit32::operator=(const SoftPosit32& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftPosit32 SoftPosit32::neg () const{
    SoftPosit32 tmp(val);
    if (val.v0 == 0 && val.v1 == 0 && val.v2 == 0 && val.v3 == 0 &&\
        val.v4 == 0 && val.v5 == 0 && val.v6 == 0 && val.v7 == 0)
        return tmp;
    int getNotZero = 0;
    // 0
    tmp.val.v0 = MAX_UINT - val.v0;
    if (val.v0 != 0)
        getNotZero = 1;
    // 1
    if (!getNotZero)
        tmp.val.v1 = MAX_UINT - val.v1;
    else
        tmp.val.v1 = -val.v1;
    if (val.v1 != 0)
        getNotZero = 1;
    // 2
    if (!getNotZero)
        tmp.val.v2 = MAX_UINT - val.v2;
    else
        tmp.val.v2 = -val.v2;
    if (val.v2 != 0)
        getNotZero = 1;
    // 3
    if (!getNotZero)
        tmp.val.v3 = MAX_UINT - val.v3;
    else
        tmp.val.v3 = -val.v3;
    if (val.v3 != 0)
        getNotZero = 1;
    // 4
    if (!getNotZero)
        tmp.val.v4 = MAX_UINT - val.v4;
    else
        tmp.val.v4 = -val.v4;
    if (val.v4 != 0)
        getNotZero = 1;
    // 5
    if (!getNotZero)
        tmp.val.v5 = MAX_UINT - val.v5;
    else
        tmp.val.v5 = -val.v5;
    if (val.v5 != 0)
        getNotZero = 1;
    // 6
    if (!getNotZero)
        tmp.val.v6 = MAX_UINT - val.v6;
    else
        tmp.val.v6 = -val.v6;
    if (val.v6 != 0)
        getNotZero = 1;
    // 7
    if (!getNotZero)
        tmp.val.v7 = MAX_UINT - val.v7;
    else
        tmp.val.v7 = -val.v7;

    return tmp;
}

CMP SoftPosit32::cmp (const SoftPosit32& rhs) const{
    SoftPosit32 tmp(val);
    SoftPosit32 rtmp(rhs.val);
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

float SoftPosit32::getFloat() const {
    SoftPosit32 tmp(val);
    return (float) tmp.val.toPosit().toDouble();
}

const SoftPosit32& SoftPosit32::operator+= (const SoftPosit32& rhs) {
    SoftPosit32 rtmp(rhs.val);
    // 7
    uint64_t v7 = val.v7;
    val.v7 += rhs.val.v7;
    // 6
    uint64_t v6 = val.v6;
    val.v6 += rhs.val.v6;
    if (val.v7 < rhs.val.v7 || val.v7 < v7)
        val.v6 += 1;
    // 5
    uint64_t v5 = val.v5;
    val.v5 += rhs.val.v5;
    if (val.v6 < rhs.val.v6 || val.v6 < v6)
        val.v5 += 1;
    // 4
    uint64_t v4 = val.v4;
    val.v4 += rhs.val.v4;
    if (val.v5 < rhs.val.v5 || val.v5 < v5)
        val.v4 += 1;
    // 3
    uint64_t v3 = val.v3;
    val.v3 += rhs.val.v3;
    if (val.v4 < rhs.val.v4 || val.v4 < v4)
        val.v3 += 1;
    // 2
    uint64_t v2 = val.v2;
    val.v2 += rhs.val.v2;
    if (val.v3 < rhs.val.v3 || val.v3 < v3)
        val.v2 += 1;
    // 1
    uint64_t v1 = val.v1;
    val.v1 += rhs.val.v1;
    if (val.v2 < rhs.val.v2 || val.v2 < v2)
        val.v1 += 1;
    // 0
    val.v0 += rhs.val.v0;
    if (val.v1 < rhs.val.v1 || val.v1 < v1)
        val.v0 += 1;

    return *this;
}

const SoftPosit32& SoftPosit32::operator*= (const SoftPosit32& rhs) {
    SoftPosit32 tmp(0.0);
    SoftPosit32 rtmp(rhs.val);
    tmp.val.qma(rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftPosit32& SoftPosit32::operator/= (const SoftPosit32& rhs) {
    SoftPosit32 tmp(0.0);
    SoftPosit32 rtmp(rhs.val);
    tmp.val.qma(1.0/rtmp.val.toPosit(), val.toPosit());
    val = tmp.val;
    return *this;
}

const SoftPosit32& SoftPosit32::qma(const SoftPosit32& rhs1, const SoftPosit32& rhs2)
{
    SoftPosit32 rtmp1(rhs1.val);
    SoftPosit32 rtmp2(rhs2.val);
    val.qma(rtmp1.val.toPosit(), rtmp2.val.toPosit());
    return *this;
}

const SoftPosit32& SoftPosit32::qms(const SoftPosit32& rhs1, const SoftPosit32& rhs2)
{
    SoftPosit32 rtmp1(rhs1.val);
    SoftPosit32 rtmp2(rhs2.val);
    val.qms(rtmp1.val.toPosit(), rtmp2.val.toPosit());
    return *this;
}
