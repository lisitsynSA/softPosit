#include <iostream>
#include "softType.h"

#ifndef SoftFloat32_H
#define SoftFloat32_H

class SoftFloat32 final : public softType<SoftFloat32>
{
public:
    float val;
    SoftFloat32(): val(0) {}
    SoftFloat32(float init): val(init) {}
    SoftFloat32(const SoftFloat32& init): val(init.val) {}
    ~SoftFloat32() override {}

    const SoftFloat32& operator=(const SoftFloat32& rhs) noexcept override;
    const SoftFloat32 neg() const override;
    CMP cmp (const SoftFloat32& rhs) const override;
    float getFloat() const override;
    const SoftFloat32& operator+=(const SoftFloat32& rhs) override;
    const SoftFloat32& operator*=(const SoftFloat32& rhs) override;
    const SoftFloat32& operator/=(const SoftFloat32& rhs) override;
    const SoftFloat32& qma(const SoftFloat32& rhs1, const SoftFloat32& rhs2) override { return *this += (rhs1*rhs2); }
    const SoftFloat32& qms(const SoftFloat32& rhs1, const SoftFloat32& rhs2) override { return *this -= (rhs1*rhs2); }
};

#endif // SoftFloat32_H
