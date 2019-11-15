#include "SoftFloat32.h"

#define SINGLE_PRECISION
#include "builtins/fp_lib.h"
extern fp_t __negsf2(fp_t a);
extern fp_t __addsf3(fp_t a, fp_t b);
extern fp_t __subsf3(fp_t a, fp_t b);
extern fp_t __mulsf3(fp_t a, fp_t b);
extern fp_t __divsf3(fp_t a, fp_t b);

enum LE_RESULT {
    LE_LESS = -1,
    LE_EQUAL = 0,
    LE_GREATER = 1,
    LE_UNORDERED = 1
};
extern enum LE_RESULT __lesf2(fp_t a, fp_t b);

enum GE_RESULT {
    GE_LESS = -1,
    GE_EQUAL = 0,
    GE_GREATER = 1,
    GE_UNORDERED = -1
};
extern enum GE_RESULT __gesf2(fp_t a, fp_t b);

const SoftFloat32& SoftFloat32::operator=(const SoftFloat32& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftFloat32 SoftFloat32::neg () const{
    SoftFloat32 tmp(__negsf2(val));
    return tmp;
}

CMP SoftFloat32::cmp (const SoftFloat32& rhs) const{
    if (this == &rhs) {
        return CMP::EQ;
    }
    if (__lesf2(__addsf3(val, EPS), rhs.val) == LE_RESULT::LE_LESS){
        return CMP::LT;
    }
    if (__gesf2(__subsf3(val, EPS), rhs.val) == GE_RESULT::GE_GREATER){
        return CMP::GT;
    }
    return CMP::EQ;
}

float SoftFloat32::getFloat() const {
    return val;
}

const SoftFloat32& SoftFloat32::operator+= (const SoftFloat32& rhs) {
    val = __addsf3(val, rhs.val);
    return *this;
}

const SoftFloat32& SoftFloat32::operator*= (const SoftFloat32& rhs) {
    val = __mulsf3(val, rhs.val);
    return *this;
}

const SoftFloat32& SoftFloat32::operator/= (const SoftFloat32& rhs) {
    val = __divsf3(val, rhs.val);
    return *this;
}
