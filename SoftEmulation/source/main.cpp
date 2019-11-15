#include <iostream>
#include <iomanip>
#include "Float32.h"
#include "Float64.h"
#include "SoftFloat32.h"
#include "SoftFloat64.h"
#include "SoftPosit32.h"
#include "SoftPosit16.h"
#include "SoftPosit8.h"
#include "SoftPosit/softposit_cpp.h"
#include "half.hpp"
using half_float::half;
using namespace half_float::literal;

#define STEPS 20

int main()
{
    int i = 0;
    SoftFloat64 x_f64[STEPS] = {4.0, 4.25};
    SoftFloat32 x_f32[STEPS] = {4.0, 4.25};
    half x_f16[STEPS] = {4.0_h, 4.25_h};
    posit32 x_p32[STEPS] = {4.0, 4.25};
    posit16 x_p16[STEPS] = {4.0, 4.25};
    posit8 x_p8[STEPS] = {4.0, 4.25};
    posit32 x_p32_fma[STEPS] = {4.0, 4.25};
    posit16 x_p16_fma[STEPS] = {4.0, 4.25};
    posit8 x_p8_fma[STEPS] = {4.0, 4.25};

    std::cout << "[##] | S_DOUBLE| S_FLOAT | POSIT32'| POSIT32 |  S_HALF | POSIT16'| POSIT16 |  POSIT8'|  POSIT8 |\n"
              << "------------------------------------------------------------------------------------------------\n"
              << "[00] |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |\n"
              << "[01] |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |\n";
    for (i = 2; i < STEPS; i++)
    {
        x_f64[i] = 108.0 - (815.0 - 1500.0/x_f64[i-2])/x_f64[i-1];
        x_f32[i] = 108.0 - (815.0 - 1500.0/x_f32[i-2])/x_f32[i-1];
        x_f16[i] = 108.0 - (815.0 - 1500.0/x_f16[i-2])/x_f16[i-1];
        x_p32[i] = 108.0 - (815.0 - 1500.0/x_p32[i-2])/x_p32[i-1];
        x_p16[i] = 108.0 - (815.0 - 1500.0/x_p16[i-2])/x_p16[i-1];
        x_p8[i] = 108.0 - (815.0 - 1500.0/x_p8[i-2])/x_p8[i-1];
        x_p32_fma[i] = fma(fma((posit32)1500.0, -1.0/x_p32_fma[i-2], (posit32)815.0), -1.0/x_p32_fma[i-1], (posit32)108.0);
        x_p16_fma[i] = fma(fma((posit16)1500.0, -1.0/x_p16_fma[i-2], (posit16)815.0), -1.0/x_p16_fma[i-1], (posit16)108.0);
        x_p8_fma[i] = fma(fma((posit8)1500.0, -1.0/x_p8_fma[i-2], (posit8)815.0), -1.0/x_p8_fma[i-1], (posit8)108.0);
        std::cout << std::setprecision(3)<< std::fixed
                  << "[" << std::setw(2) << std::setfill('0') << i << "] | "
                  << std::setw(7) << std::setfill(' ') << x_f64[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_f32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p32_fma[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_f16[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p16_fma[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p16[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p8_fma[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p8[i] << " |\n";
    }
    return 0;
}
