#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "randombytes.h"

#define byte unsigned char

void print_matrice(byte matrice[], uint32_t size);
uint32_t tobytes(uint32_t value);

int main()
{
    // set initial params
    const uint32_t N = 3000, K = 2808, n = 1100, k = 963, t1 = 352, t2 = 672;
    //N = 3000; K = 2808; n = 1100; k = 963; t1 = 352; t2 = 672;

    uint32_t size_matrice_H = tobytes((N-K)*N);

    byte matrice_H[size_matrice_H]; // N-K rows and N columns
    memset(matrice_H, 0, size_matrice_H*sizeof(byte));
    randombytes(matrice_H, size_matrice_H*sizeof(byte));
    print_matrice(matrice_H, size_matrice_H);


    return 0;
}

void print_matrice(byte matrice[], uint32_t size)
{
    for (size_t i=0; i<size; i++) {
        printf("%x ", matrice[i]);
    }
}

uint32_t tobytes(uint32_t value)
{
    uint32_t in_bytes;
    if (!(value % 8))
        in_bytes = value / 8;
    else 
        in_bytes = value / 8 + 1;

    return in_bytes;
}
