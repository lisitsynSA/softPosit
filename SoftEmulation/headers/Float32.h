#include <iostream>
#include "softType.h"

#ifndef FLOAT32_H
#define FLOAT32_H

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
    float getFloat() const override;
    const Float32& operator+=(const Float32& rhs) override;
    const Float32& operator*=(const Float32& rhs) override;
    const Float32& operator/=(const Float32& rhs) override;
};

#endif // FLOAT32_H
