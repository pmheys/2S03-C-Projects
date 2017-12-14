#include <gmp.h>
#include <stdio.h>
#include <assert.h>

unsigned long primeGap(const mpz_t a, const mpz_t b){

  mpz_t current; mpz_init(current);
  mpz_t next; mpz_init(next);
  mpz_t gap; mpz_init(gap);
  mpz_t maxGap; mpz_init(maxGap);

  mpz_set(current, a);
  mpz_set_ui(next, 0);
  mpz_set_ui(maxGap, 0);

  if(mpz_probab_prime_p(current, 40) != 2){
    mpz_nextprime(current, current);
  }

  while(mpz_cmp(b, current) > 0){


    mpz_nextprime(next, current);

    if(mpz_cmp(next, b) > 0){
      break;
    }

    mpz_sub(gap, next, current);

    if(mpz_cmp(gap, maxGap) > 0){
      mpz_set(maxGap, gap);
    }

    mpz_set(current, next);



  }/* while */

  return mpz_get_ui(maxGap);


}/*primeGap*/
