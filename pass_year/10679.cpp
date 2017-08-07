#include <stdio.h>
long long int phi(long long int n);
int main(void) {
       long long int n,totient;
       scanf("%lld",&n);
    while(n!=0)
    {
      totient= phi(n);
      printf("%lld\n",totient);
      scanf("%lld",&n);
    }
 return 0;
}

long long int phi (long long int n)
{
   long long int result = n;
   long long int i;
   for (i=2; i*i<=n; ++i)
     if (n % i == 0)
       {
          while (n % i == 0)
           n /= i;
           result -= result / i;
        }
     if (n > 1)
     result -= result / n;
     return result;
}
