#include <iostream>
#include "softType.h"

#ifndef SOFTFLOAT64_H
#define SOFTFLOAT64_H

class SoftFloat64 final : public softType<SoftFloat64>
{
public:
    double val;
    SoftFloat64(): val(0) {}
    SoftFloat64(double init): val(init) {}
    SoftFloat64(const SoftFloat64& init): val(init.val) {}
    ~SoftFloat64() override {}

    const SoftFloat64& operator=(const SoftFloat64& rhs) noexcept override;
    const SoftFloat64 neg() const override;
    CMP cmp (const SoftFloat64& rhs) const override;
    float getFloat() const override;
    const SoftFloat64& operator+=(const SoftFloat64& rhs) override;
    const SoftFloat64& operator*=(const SoftFloat64& rhs) override;
    const SoftFloat64& operator/=(const SoftFloat64& rhs) override;
};

#endif // SOFTFLOAT64_H
