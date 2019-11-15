#include "SoftFloat64.h"

#define DOUBLE_PRECISION
#include "builtins/fp_lib.h"
extern fp_t __negdf2(fp_t a);
extern fp_t __adddf3(fp_t a, fp_t b);
extern fp_t __subdf3(fp_t a, fp_t b);
extern fp_t __muldf3(fp_t a, fp_t b);
extern fp_t __divdf3(fp_t a, fp_t b);

enum LE_RESULT {
    LE_LESS = -1,
    LE_EQUAL = 0,
    LE_GREATER = 1,
    LE_UNORDERED = 1
};
extern enum LE_RESULT __ledf2(fp_t a, fp_t b);

enum GE_RESULT {
    GE_LESS = -1,
    GE_EQUAL = 0,
    GE_GREATER = 1,
    GE_UNORDERED = -1
};
extern enum GE_RESULT __gedf2(fp_t a, fp_t b);

const SoftFloat64& SoftFloat64::operator=(const SoftFloat64& rhs) noexcept {
    if (this != &rhs) {
        val = rhs.val;
    }
    return *this;
}

const SoftFloat64 SoftFloat64::neg () const{
    SoftFloat64 tmp(__negdf2(val));
    return tmp;
}

CMP SoftFloat64::cmp (const SoftFloat64& rhs) const{
    if (this == &rhs) {
        return CMP::EQ;
    }
    if (__ledf2(__adddf3(val, EPS), rhs.val) == LE_RESULT::LE_LESS){
        return CMP::LT;
    }
    if (__gedf2(__subdf3(val, EPS), rhs.val) == GE_RESULT::GE_GREATER){
        return CMP::GT;
    }
    return CMP::EQ;
}

float SoftFloat64::getFloat() const {
    return val;
}

const SoftFloat64& SoftFloat64::operator+= (const SoftFloat64& rhs) {
    val = __adddf3(val, rhs.val);
    return *this;
}

const SoftFloat64& SoftFloat64::operator*= (const SoftFloat64& rhs) {
    val = __muldf3(val, rhs.val);
    return *this;
}

const SoftFloat64& SoftFloat64::operator/= (const SoftFloat64& rhs) {
    val = __divdf3(val, rhs.val);
    return *this;
}
