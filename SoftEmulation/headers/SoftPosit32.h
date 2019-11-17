#include <iostream>
#include "softType.h"
#include "SoftPosit/softposit_cpp.h"

#ifndef SOFTPOSIT32_H
#define SOFTPOSIT32_H

class SoftPosit32 final : public softType<SoftPosit32>
{
public:
    quire32 val;
    SoftPosit32() { val.clr(); }
    SoftPosit32(double init) { val.clr(); val.qma((posit32)init, (posit32)1.0); }
    SoftPosit32(posit32 init) { val.clr(); val.qma((posit32)init, (posit32)1.0); }
    SoftPosit32(quire32 init): val(init) {}
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
