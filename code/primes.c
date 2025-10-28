#include "primes.h"
#include <stdio.h>



// Sieve
int* getPrimes(int m, int* maxPrime) {
    if (m <= 0) {
        *maxPrime = 0;
        return NULL;
    }


    
    // guesss sieve limit
    long long maxSieveLimit = (long long)m * 15;
    if (m > 100000) {
         maxSieveLimit = 1500000 + (long long)m * 15;
    }

    if (maxSieveLimit < 2000) maxSieveLimit = 2000; // minimum
    
    // printf("sieve limit %lld\n", maxSieveLimit);

    char* sieve = (char*)calloc(maxSieveLimit + 1, sizeof(char));
    if (sieve == NULL) {
        perror("malloc faild for sieve");
        exit(0);
    }
    
    sieve[0] = 1;
    sieve[1] = 1;
    for (long long p = 2; p * p <= maxSieveLimit; p++) {
        if (sieve[p] == 0) {
            for (long long i = p * p; i <= maxSieveLimit; i += p)
                sieve[i] = 1; // not prime
        }
    }

    // array for primes
    int* primes = (int*)malloc(sizeof(int) * m);
    if (primes == NULL) {
        perror("malloc faild for primes arr");
        free(sieve);
        exit(0);
    }

  
    int count = 0;
    
    
    *maxPrime = 0;
    
    for (long long i = 2; i <= maxSieveLimit && count < m; i++) {
        if (sieve[i] == 0) {
            primes[count] = i;
            *maxPrime = i;
            count++;
        }
    }
    

    if (count < m) {
        // this is bad
        fprintf(stderr, "sieve limit too small, only found %d primes\n", count);
    }

    free(sieve);
    return primes;
}



















