#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


/* primeGap takes to integers, a and b of time mpz_t and returns the
   largest prime gap in the interval [a,b]. If no such a gap, primeGap
   returns 0. */
extern unsigned long primeGap(const mpz_t a, const mpz_t b);
extern double getTime();

int main(int argc, char* argv[])
{
  if (argc < 3)
    {
      printf("Usage: ./primesgap a b\n");
      return 0;
    }

  /* start timing */
  double time = getTime();

  mpz_t a, b;

  /* obtain the input bounds as long inttegers */
  unsigned long int la, lb;
  sscanf(argv[1],"%lu",&la);
  sscanf(argv[2],"%lu",&lb);

  /* convert the arguments to gmp integers */
  mpz_init_set_str (a, argv[1], 10);
  mpz_init_set_str (b, argv[2], 10);

  unsigned long max_gap = primeGap(a,b);
  printf("\nLargest prime gap in [%ld, %ld] is %ld\n", la, lb, max_gap);
  time = getTime()-time;
  printf("computed in %.1e seconds\n\n", time);

  return 0;
}
 
