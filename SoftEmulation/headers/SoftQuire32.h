#include <iostream>
#include "softType.h"
#include "SoftPosit/softposit_cpp.h"

#ifndef SoftQuire32_H
#define SoftQuire32_H

class SoftQuire32 final : public softType<SoftQuire32>
{
public:
    quire32 val;
    SoftQuire32() { val.clr(); }
    SoftQuire32(double init) { val.clr(); val.qma((posit32)init, (posit32)1.0); }
    SoftQuire32(posit32 init) { val.clr(); val.qma((posit32)init, (posit32)1.0); }
    SoftQuire32(quire32 init): val(init) {}
    SoftQuire32(const SoftQuire32& init): val(init.val) {}
    ~SoftQuire32() override {}

    const SoftQuire32& operator=(const SoftQuire32& rhs) noexcept override;
    const SoftQuire32 neg() const override;
    CMP cmp (const SoftQuire32& rhs) const override;
    float getFloat() const override;
    const SoftQuire32& operator+=(const SoftQuire32& rhs) override;
    const SoftQuire32& operator*=(const SoftQuire32& rhs) override;
    const SoftQuire32& operator/=(const SoftQuire32& rhs) override;
    const SoftQuire32& qma(const SoftQuire32& rhs1, const SoftQuire32& rhs2) override;
    const SoftQuire32& qms(const SoftQuire32& rhs1, const SoftQuire32& rhs2) override;
};

#endif // SoftQuire32_H
