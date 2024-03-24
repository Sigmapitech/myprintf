#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "../my.h"

int my_putnbr(char *s, intmax_t n)
{
    int size = 0;

    if (n >= 0)
        n = -n;
    size += my_intlen(n);
    for (int i = my_intlen(n); i != 0; n /= 10) {
        i--;
        s[i] = -(n % 10) | '0';
    }
    return size;
}
