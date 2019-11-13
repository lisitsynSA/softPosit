#include <stdio.h>
#define STEPS 20

//#define SINGLE_PRECISION
#define DOUBLE_PRECISION

#include "fp_lib.h"

#if defined SINGLE_PRECISION
extern fp_t __divsf3(fp_t a, fp_t b);
extern fp_t __subsf3(fp_t a, fp_t b);
#elif defined DOUBLE_PRECISION
extern fp_t __divdf3(fp_t a, fp_t b);
extern fp_t __subdf3(fp_t a, fp_t b);
#else
#error SINGLE_PRECISION or DOUBLE_PRECISION must be defined.
#endif

int main()
{
  int i = 0;
  float x_f[STEPS] = {4.0, 4.25};
  double x_d[STEPS] = {4.0, 4.25};
  fp_t x_soft[STEPS] = {4.0, 4.25};

#if defined SINGLE_PRECISION
  printf("[##] | FLOAT | DOUBLE| SOFT FLOAT\n");
#elif defined DOUBLE_PRECISION
  printf("[##] | FLOAT | DOUBLE| SOFT DOUBLE\n");
#endif

  printf("[00] | 4.000 | 4.000 | 4.000\n");
  printf("[01] | 4.250 | 4.250 | 4.250\n");
  for (i = 2; i < STEPS; i++)
  {
    x_f[i] = 108.0 - (815.0 - 1500.0/x_f[i-2])/x_f[i-1];
    x_d[i] = 108.0 - (815.0 - 1500.0/x_d[i-2])/x_d[i-1];

#if defined SINGLE_PRECISION
    x_soft[i] = __subsf3((fp_t)108.0, __divsf3(__subsf3((fp_t)815.0, __divsf3((fp_t)1500.0, x_soft[i-2])), x_soft[i-1]));
    printf("[%02d] | %.3f | %.3lf | %.3f\n", i, x_f[i], x_d[i], x_soft[i]);
#elif defined DOUBLE_PRECISION
    x_soft[i] = __subdf3((fp_t)108.0, __divdf3(__subdf3((fp_t)815.0, __divdf3((fp_t)1500.0, x_soft[i-2])), x_soft[i-1]));
    printf("[%02d] | %.3f | %.3lf | %.3lf\n", i, x_f[i], x_d[i], x_soft[i]);
#endif

  }
  return 0;
}
