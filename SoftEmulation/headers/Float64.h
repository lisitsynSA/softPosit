#include <iostream>
#include "softType.h"

#ifndef FLOAT64_H
#define FLOAT64_H

class Float64 final : public softType<Float64>
{
public:
    double val;
    Float64(): val(0) {}
    Float64(double init): val(init) {}
    Float64(const Float64& init): val(init.val) {}
    ~Float64() override {}

    const Float64& operator=(const Float64& rhs) noexcept override;
    const Float64 neg() const override;
    CMP cmp (const Float64& rhs) const override;
    float getFloat() const override;
    const Float64& operator+=(const Float64& rhs) override;
    const Float64& operator*=(const Float64& rhs) override;
    const Float64& operator/=(const Float64& rhs) override;
    const Float64& qma(const Float64& rhs1, const Float64& rhs2) override { return *this += (rhs1*rhs2); }
    const Float64& qms(const Float64& rhs1, const Float64& rhs2) override { return *this -= (rhs1*rhs2); }
};

#endif // FLOAT64_H
