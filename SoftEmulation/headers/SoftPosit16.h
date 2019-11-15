#include <iostream>
#include "softType.h"
#include "SoftPosit/softposit_cpp.h"

#ifndef SOFTPOSIT16_H
#define SOFTPOSIT16_H

class SoftPosit16 final : public softType<SoftPosit16>
{
public:
    posit16 val;
    SoftPosit16(): val(0) {}
    SoftPosit16(double init): val(init) {}
    SoftPosit16(posit16 init): val(init) {}
    SoftPosit16(const SoftPosit16& init): val(init.val) {}
    ~SoftPosit16() override {}

    const SoftPosit16& operator=(const SoftPosit16& rhs) noexcept override;
    const SoftPosit16 neg() const override;
    CMP cmp (const SoftPosit16& rhs) const override;
    float getFloat() const override;
    const SoftPosit16& operator+=(const SoftPosit16& rhs) override;
    const SoftPosit16& operator*=(const SoftPosit16& rhs) override;
    const SoftPosit16& operator/=(const SoftPosit16& rhs) override;
};

#endif // SOFTPOSIT16_H
