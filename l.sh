#include <stdio.h>

void summa(int n, int k)
{
     if (n == 0)
     {
        printf("n\"):
        return;
      }

      for (int i = k; i >= 1; i--)
      {
          if (i <= n)
           {

             printf("%d", i);

             if (n - i > 0)
                 printf ("+")

             summa(n-i,i);
          }
     }
}

int main()
{
    int n;

    printf("Enter N: ");

    if (skanf("%d", &n) !=1 || n <= 0)
    {
       printf("Error!\n");
       return 1;
    }

    summa(n,n)


    return 0;
}
