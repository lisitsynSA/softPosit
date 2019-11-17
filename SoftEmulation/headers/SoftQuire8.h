#include <iostream>
#include "softType.h"
#include "SoftPosit/softposit_cpp.h"

#ifndef SoftQuire8_H
#define SoftQuire8_H

class SoftQuire8 final : public softType<SoftQuire8>
{
public:
    quire8 val;
    SoftQuire8() { val.clr(); }
    SoftQuire8(double init) { val.clr(); val.qma((posit8)init, (posit8)1.0); }
    SoftQuire8(posit8 init) { val.clr(); val.qma((posit8)init, (posit8)1.0); }
    SoftQuire8(quire8 init): val(init) {}
    SoftQuire8(const SoftQuire8& init): val(init.val) {}
    ~SoftQuire8() override {}

    const SoftQuire8& operator=(const SoftQuire8& rhs) noexcept override;
    const SoftQuire8 neg() const override;
    CMP cmp (const SoftQuire8& rhs) const override;
    float getFloat() const override;
    const SoftQuire8& operator+=(const SoftQuire8& rhs) override;
    const SoftQuire8& operator*=(const SoftQuire8& rhs) override;
    const SoftQuire8& operator/=(const SoftQuire8& rhs) override;
    const SoftQuire8& qma(const SoftQuire8& rhs1, const SoftQuire8& rhs2) override;
    const SoftQuire8& qms(const SoftQuire8& rhs1, const SoftQuire8& rhs2) override;
};

#endif // SoftQuire8_H
