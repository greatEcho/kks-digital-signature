#include <stdio.h>


#define SPX_N 32
#define CRYPTO_SEEDBYTES 3*SPX_N

void print_seed(unsigned char *x, unsigned long long xlen);

int main()
{
    unsigned char seed[CRYPTO_SEEDBYTES];
    randombytes(seed, CRYPTO_SEEDBYTES);
    print_seed(seed, CRYPTO_SEEDBYTES);

    return 0;
}


void print_seed(unsigned char *x, unsigned long long xlen)
{
    for (unsigned long long i=0; i<xlen; ++i) {
        printf("%02x ", x[i]);
    }
}
