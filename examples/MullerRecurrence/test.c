#include <stdio.h>
#define STEPS 20

int main()
{
  int i = 0;
  float x_f[STEPS] = {4.0, 4.25};
  double x_d[STEPS] = {4.0, 4.25};
  printf("[№] | FLOAT | DOUBLE \n");
  printf("[0] | %.3f | %.3lf\n", x_f[0], x_d[0]);
  printf("[1] | %.3f | %.3lf\n", x_f[1], x_d[1]);
  for (i = 2; i < STEPS; i++)
  {
  	x_f[i] = 108.0 - (815.0 - 1500.0/x_f[i-2])/x_f[i-1];
  	x_d[i] = 108.0 - (815.0 - 1500.0/x_d[i-2])/x_d[i-1];
    printf("[%d] | %.3f | %.3lf\n", i, x_f[i], x_d[i]);
  }
  return 0;
}
