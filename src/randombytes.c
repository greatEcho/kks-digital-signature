/*
This code was taken from the SPHINCS reference implementation and is public domain.
*/

#include <fcntl.h>
#include <unistd.h>

#include "randombytes.h"
#define byte unsigned char

static int fd = -1;

/* this function generates randombytes using /dev/urandom
 * *x - pointer to an array
 * xlen - length of the array
 * */
void randombytes(unsigned char *x, unsigned long long xlen)
{
    unsigned long long i;

    if (fd == -1) {
        for (;;) {
            fd = open("/dev/urandom", O_RDONLY);
            if (fd != -1) {
                break;
            }
            sleep(1);
        }
    }

    while (xlen > 0) {
        if (xlen < 1048576) {
            i = xlen;
        }
        else {
            i = 1048576;
        }

        i = (unsigned long long)read(fd, x, i);
        if (i < 1) {
            sleep(1);
            continue;
        }

        x += i;
        xlen -= i;
    }
}

unsigned char random_byte(void)
{
    byte result;
    if (fd == -1) {
        // try open /dev/urandom until we can
        for (;;) {
            fd = open("/dev/urandom", O_RDONLY);
            if (fd != -1) {
                break;
            }
            sleep(1);
        }
    }

    read(fd, &result, 1);
    return result;
}

