#include <iostream>
#include "softType.h"
#include "SoftPosit/softposit_cpp.h"

#ifndef SoftQuire16_H
#define SoftQuire16_H

class SoftQuire16 final : public softType<SoftQuire16>
{
public:
    quire16 val;
    SoftQuire16() { val.clr(); }
    SoftQuire16(double init) { val.clr(); val.qma((posit16)init, (posit16)1.0); }
    SoftQuire16(posit16 init) { val.clr(); val.qma((posit16)init, (posit16)1.0); }
    SoftQuire16(quire16 init): val(init) {}
    SoftQuire16(const SoftQuire16& init): val(init.val) {}
    ~SoftQuire16() override {}

    const SoftQuire16& operator=(const SoftQuire16& rhs) noexcept override;
    const SoftQuire16 neg() const override;
    CMP cmp (const SoftQuire16& rhs) const override;
    float getFloat() const override;
    const SoftQuire16& operator+=(const SoftQuire16& rhs) override;
    const SoftQuire16& operator*=(const SoftQuire16& rhs) override;
    const SoftQuire16& operator/=(const SoftQuire16& rhs) override;
    const SoftQuire16& qma(const SoftQuire16& rhs1, const SoftQuire16& rhs2) override;
    const SoftQuire16& qms(const SoftQuire16& rhs1, const SoftQuire16& rhs2) override;
};

#endif // SoftQuire16_H
