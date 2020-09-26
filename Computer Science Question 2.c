#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

int jacobi (unsigned long a, unsigned long n);
int is_proth_prime (int proth);


void main ()
{
  int num = 15;
  if (is_proth_prime(num) == 1)
    printf("%d is a prime number", num);
  else
    printf("%d is not a prime number", num);

}

int is_proth_prime (int proth)
{
  int a, e, lhs;
  a = 0;
  while (a < proth){
      if (jacobi(a, proth) != -1){
        a++;
        continue;
      }
      e = (proth - 1) / 2;
      lhs = pow(a, e) + 1;
      if (lhs % proth == 0)
        return 1;
      a++;
  }
  return 0;
}

int jacobi (unsigned long a, unsigned long n)
{
  if (a >= n)
    a %= n;
  int result = 1;
  while (a)
    {
      while ((a & 1) == 0)
	{
	  a >>= 1;
	  if ((n & 7) == 3 || (n & 7) == 5)
	    result = -result;
	}
      SWAP (a, n);
      if ((a & 3) == 3 && (n & 3) == 3)
	result = -result;
      a %= n;
    }
  if (n == 1)
    return result;
  return 0;
}
