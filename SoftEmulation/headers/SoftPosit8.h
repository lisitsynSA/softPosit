#include <iostream>
#include "softType.h"
#include "SoftPosit/softposit_cpp.h"

#ifndef SOFTPOSIT8_H
#define SOFTPOSIT8_H

class SoftPosit8 final : public softType<SoftPosit8>
{
public:
    posit8 val;
    SoftPosit8(): val(0) {}
    SoftPosit8(double init): val(init) {}
    SoftPosit8(posit8 init): val(init) {}
    SoftPosit8(const SoftPosit8& init): val(init.val) {}
    ~SoftPosit8() override {}

    const SoftPosit8& operator=(const SoftPosit8& rhs) noexcept override;
    const SoftPosit8 neg() const override;
    CMP cmp (const SoftPosit8& rhs) const override;
    float getFloat() const override;
    const SoftPosit8& operator+=(const SoftPosit8& rhs) override;
    const SoftPosit8& operator*=(const SoftPosit8& rhs) override;
    const SoftPosit8& operator/=(const SoftPosit8& rhs) override;
    const SoftPosit8& qma(const SoftPosit8& rhs1, const SoftPosit8& rhs2) override { return *this += (rhs1*rhs2); }
    const SoftPosit8& qms(const SoftPosit8& rhs1, const SoftPosit8& rhs2) override { return *this -= (rhs1*rhs2); }
};

#endif // SOFTPOSIT8_H
