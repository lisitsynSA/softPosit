#include <iostream>
#include "softType.h"
#include "half.hpp"
using half_float::half;
using namespace half_float::literal;

#ifndef SoftFloat16_H
#define SoftFloat16_H

class SoftFloat16 final : public softType<SoftFloat16>
{
public:
    half val;
    SoftFloat16(): val(0.0_h) {}
    SoftFloat16(float init): val(init) {}
    SoftFloat16(const SoftFloat16& init): val(init.val) {}
    ~SoftFloat16() override {}

    const SoftFloat16& operator=(const SoftFloat16& rhs) noexcept override;
    const SoftFloat16 neg() const override;
    CMP cmp (const SoftFloat16& rhs) const override;
    float getFloat() const override;
    const SoftFloat16& operator+=(const SoftFloat16& rhs) override;
    const SoftFloat16& operator*=(const SoftFloat16& rhs) override;
    const SoftFloat16& operator/=(const SoftFloat16& rhs) override;
    const SoftFloat16& qma(const SoftFloat16& rhs1, const SoftFloat16& rhs2) override { return *this += (rhs1*rhs2); }
    const SoftFloat16& qms(const SoftFloat16& rhs1, const SoftFloat16& rhs2) override { return *this -= (rhs1*rhs2); }
};

#endif // SoftFloat16_H
