#include <iostream>
#include "softType.h"

class Float32 final : public softType<Float32>
{
public:
    float val;
    Float32(): val(0) {}
    Float32(float init): val(init) {}
    Float32(const Float32& init): val(init.val) {}
    ~Float32() override {}

    const Float32& operator=(const Float32& rhs) noexcept override;
    const Float32 neg() const override;
    CMP cmp (const Float32& rhs) const override;
    operator float() const override;
    const Float32& operator+=(const Float32& rhs) override;
    const Float32& operator-=(const Float32& rhs) override;
    const Float32& operator*=(const Float32& rhs) override;
    const Float32& operator/=(const Float32& rhs) override;
};