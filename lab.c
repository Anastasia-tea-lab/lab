#include <stdio.h>
#include <math.h>

int main() {
   float x,a,u,z;
   float hx = 1.3, ha=1.3;
   float x0=1.0, x1=3.0;
   float a0=2.0, a1=4.0;
   for (float xn = x0; xn <= x1; xn += hx)
{
   for (float an = a0; an <= a1; an += ha)
{
   float u1,u2;
   float z1,z2;

   u1 = tan (an/xn);
   u2 = xn * sin(an) * sin(an);

   u=u1;

   if(u2<u)
     u = u2;

    z1 = an *  sqrt(u);
    z2 = sin(an) / xn;

   z = z1;

   if (z2 < z)
     z = z2;

   printf("x=%.2f a = %.2f u = %.2f z = %.2f\n", xn,an,u,z);
    }
  }
  return 0;
}
