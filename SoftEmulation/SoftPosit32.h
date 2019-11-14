#include <iostream>
#include "softType.h"

#ifndef SOFTPOSIT32_H
#define SOFTPOSIT32_H

class SoftPosit32 final : public softType<SoftPosit32>
{
public:
    float val;
    SoftPosit32(): val(0) {}
    SoftPosit32(float init): val(init) {}
    SoftPosit32(const SoftPosit32& init): val(init.val) {}
    ~SoftPosit32() override {}

    const SoftPosit32& operator=(const SoftPosit32& rhs) noexcept override;
    const SoftPosit32 neg() const override;
    CMP cmp (const SoftPosit32& rhs) const override;
    float getFloat() const override;
    const SoftPosit32& operator+=(const SoftPosit32& rhs) override;
    const SoftPosit32& operator*=(const SoftPosit32& rhs) override;
    const SoftPosit32& operator/=(const SoftPosit32& rhs) override;
};

#endif // SOFTPOSIT32_H
