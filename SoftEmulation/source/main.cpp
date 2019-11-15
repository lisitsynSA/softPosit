#include <iostream>
#include <iomanip>
#include "Float32.h"
#include "Float64.h"
#include "SoftFloat32.h"
#include "SoftFloat64.h"
#include "SoftPosit32.h"
#include "SoftPosit16.h"
#define STEPS 20

int main()
{
    int i = 0;
    Float32 x_f[STEPS] = {4.0, 4.25};
    Float64 x_d[STEPS] = {4.0, 4.25};
    SoftFloat32 x_f32[STEPS] = {4.0, 4.25};
    SoftFloat64 x_f64[STEPS] = {4.0, 4.25};
    SoftPosit32 x_p32[STEPS] = {4.0, 4.25};
    SoftPosit16 x_p16[STEPS] = {4.0, 4.25};
    posit8 x_p8[STEPS] = {4.0, 4.25};

    std::cout << "[##] |  FLOAT  |  DOUBLE | S_FLOAT | S_DOUBLE| POSIT32 | POSIT16 | POSIT8\n"
              << "---------------------------------------------------\n"
              << "[00] |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |   4.000 |   4.000\n"
              << "[01] |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |   4.250 |   4.250\n";
    for (i = 2; i < STEPS; i++)
    {
        x_f[i] = 108.0 - (815.0 - 1500.0/x_f[i-2])/x_f[i-1];
        x_d[i] = 108.0 - (815.0 - 1500.0/x_d[i-2])/x_d[i-1];
        x_f32[i] = 108.0 - (815.0 - 1500.0/x_f32[i-2])/x_f32[i-1];
        x_f64[i] = 108.0 - (815.0 - 1500.0/x_f64[i-2])/x_f64[i-1];
        x_p32[i] = 108.0 - (815.0 - 1500.0/x_p32[i-2])/x_p32[i-1];
        x_p16[i] = 108.0 - (815.0 - 1500.0/x_p16[i-2])/x_p16[i-1];
        x_p8[i] = 108.0 - (815.0 - 1500.0/x_p8[i-2])/x_p8[i-1];
        std::cout << std::setprecision(3)<< std::fixed
                  << "[" << std::setw(2) << std::setfill('0') << i << "] | "
                  << std::setw(7) << std::setfill(' ') << x_f[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_d[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_f32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_f64[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p16[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p8[i] << "\n";
    }
    return 0;
}
