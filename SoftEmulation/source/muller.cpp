#include <iostream>
#include <iomanip>
#include "Float32.h"
#include "Float64.h"
#include "SoftFloat16.h"
#include "SoftFloat32.h"
#include "SoftFloat64.h"
#include "SoftQuire32.h"
#include "SoftQuire16.h"
#include "SoftQuire8.h"

#define STEPS 20

//#include <cstdio>

int main()
{
    /*SoftQuire32 a(-2.0);
    SoftQuire32 b(1.0);

    printf("a = %f[%lX;%lX;%lX;%lX;%lX;%lX;%lX;%lX]\n", a.getFloat(), a.val.v0, a.val.v1, a.val.v2, a.val.v3, a.val.v4, a.val.v5, a.val.v6, a.val.v7);
    printf("b = %f[%lX;%lX;%lX;%lX;%lX;%lX;%lX;%lX]\n", b.getFloat(), b.val.v0, b.val.v1, b.val.v2, b.val.v3, b.val.v4, b.val.v5, b.val.v6, b.val.v7);
    printf("a-b = %f[%lX;%lX;%lX;%lX;%lX;%lX;%lX;%lX]\n", (a-b).getFloat(), (a-b).val.v0, (a-b).val.v1, (a-b).val.v2, (a-b).val.v3, (a-b).val.v4, (a-b).val.v5, (a-b).val.v6, (a-b).val.v7);
    */
    /*SoftQuire8 b(1.0);
    SoftQuire8 a(2.0);

    printf("a = %f [%X]\n", a.getFloat(), a.val.value);
    printf("b = %f [%X]\n", b.getFloat(), b.val.value);
    printf("(b/a) = %f [%X]\n", (b/a).getFloat(), (b/a).val.value);*/

    /*SoftQuire16 ar(-375.0);
    SoftQuire16 arg(375.0);
    SoftQuire16 arg1(108.0);
    SoftQuire16 arg2(815.0);
    SoftQuire16 arg3(1500.0);
    SoftQuire16 x0(4.0);
    SoftQuire16 x1(4.25);
    printf("ar = %f [%lX;%lX]\n", ar.getFloat(), ar.val.lvalue, ar.val.rvalue);
    printf("arg = %f [%lX;%lX]\n", arg.getFloat(), arg.val.lvalue, arg.val.rvalue);
    printf("-arg = %f [%lX;%lX]\n", (-arg).getFloat(), (-arg).val.lvalue, (-arg).val.rvalue);
    printf("arg1 = %f [%lX;%lX]\n", arg1.getFloat(), arg1.val.lvalue, arg1.val.rvalue);
    printf("arg2 = %f [%lX;%lX]\n", arg2.getFloat(), arg2.val.lvalue, arg2.val.rvalue);
    printf("arg3 = %f [%lX;%lX]\n", arg3.getFloat(), arg3.val.lvalue, arg3.val.rvalue);
    printf("x0 = %f [%lX;%lX]\n", x0.getFloat(), x0.val.lvalue, x0.val.rvalue);
    printf("x1 = %f [%lX;%lX]\n", x1.getFloat(), x1.val.lvalue, x1.val.rvalue);
    printf("-arg3/x0 = %f [%lX;%lX] %f\n", (-arg3/x0).getFloat(), (-arg3/x0).val.lvalue, (-arg3/x0).val.rvalue, 1500.0/4.0);
    printf("arg2 - arg3/x0 = %f [%lX;%lX] %f\n", (arg2 - arg3/x0).getFloat(), (arg2 - arg3/x0).val.lvalue, (arg2 - arg3/x0).val.rvalue, 815.0 - 1500.0/4.0);
    printf("(arg2 - arg3/x0)/x1 = %f [%lX;%lX] %f\n", ((arg2 - arg3/x0)/x1).getFloat(), ((arg2 - arg3/x0)/x1).val.lvalue, ((arg2 - arg3/x0)/x1).val.rvalue, (815.0 - 1500.0/4.0)/4.25);
    printf("arg1 - (arg2 - arg3/x0)/x1 = %f [%lX;%lX] %f\n", (arg1 - (arg2 - arg3/x0)/x1).getFloat(), (arg1 - (arg2 - arg3/x0)/x1).val.lvalue, (arg1 - (arg2 - arg3/x0)/x1).val.rvalue, 108.0 - (815.0 - 1500.0/4.0)/4.25);
    */

    SoftFloat64 x_f64[STEPS] = {4.0, 4.25};
    SoftFloat32 x_f32[STEPS] = {4.0, 4.25};
    SoftFloat16 x_f16[STEPS] = {4.0, 4.25};
    SoftQuire32 x_pq32[STEPS] = {4.0, 4.25};
    SoftQuire16 x_pq16[STEPS] = {4.0, 4.25};
    SoftQuire8 x_pq8[STEPS] = {4.0, 4.25};
    posit32 x_p32[STEPS] = {4.0, 4.25};
    posit16 x_p16[STEPS] = {4.0, 4.25};
    posit8 x_p8[STEPS] = {4.0, 4.25};
    posit32 x_p32_fma[STEPS] = {4.0, 4.25};
    posit16 x_p16_fma[STEPS] = {4.0, 4.25};
    posit8 x_p8_fma[STEPS] = {4.0, 4.25};

    std::cout << "[##] | S_DOUBLE| S_FLOAT | QPOSIT32| POSIT32'| POSIT32 |  S_HALF | QPOSIT16| POSIT16'| POSIT16| QPOSIT8 |  POSIT8'|  POSIT8 |\n"
              << "-----------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < STEPS; i++)
    {
        if (i >= 2)
        {
            x_f64[i] = 108.0 - (815.0 - 1500.0/x_f64[i-2])/x_f64[i-1];
            x_f32[i] = 108.0 - (815.0 - 1500.0/x_f32[i-2])/x_f32[i-1];
            x_f16[i] = 108.0 - (815.0 - 1500.0/x_f16[i-2])/x_f16[i-1];
            x_pq32[i] = 108.0 - (815.0 - 1500.0/x_pq32[i-2])/x_pq32[i-1];
            x_pq16[i] = 108.0 - (815.0 - 1500.0/x_pq16[i-2])/x_pq16[i-1];
            x_pq8[i] = 108.0 - (815.0 - 1500.0/x_pq8[i-2])/x_pq8[i-1];
            x_p32[i] = 108.0 - (815.0 - 1500.0/x_p32[i-2])/x_p32[i-1];
            x_p16[i] = 108.0 - (815.0 - 1500.0/x_p16[i-2])/x_p16[i-1];
            x_p8[i] = 108.0 - (815.0 - 1500.0/x_p8[i-2])/x_p8[i-1];
            x_p32_fma[i] = fma(fma((posit32)1500.0, -1.0/x_p32_fma[i-2], (posit32)815.0), -1.0/x_p32_fma[i-1], (posit32)108.0);
            x_p16_fma[i] = fma(fma((posit16)1500.0, -1.0/x_p16_fma[i-2], (posit16)815.0), -1.0/x_p16_fma[i-1], (posit16)108.0);
            x_p8_fma[i] = fma(fma((posit8)1500.0, -1.0/x_p8_fma[i-2], (posit8)815.0), -1.0/x_p8_fma[i-1], (posit8)108.0);
        }
        std::cout << std::setprecision(3)<< std::fixed
                  << "[" << std::setw(2) << std::setfill('0') << i << "] | "
                  << std::setw(7) << std::setfill(' ') << x_f64[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_f32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_pq32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p32_fma[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p32[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_f16[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_pq16[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p16_fma[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p16[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_pq8[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p8_fma[i] << " | "
                  << std::setw(7) << std::setfill(' ') << x_p8[i] << " |\n";
    }
    return 0;
}
