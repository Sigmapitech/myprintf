#include <stdio.h>

#include "my.h"

static const char BASE_CHARSET[] = "0123456789abcdef";

int my_base_len(int base, size_t n)
{
    int i = 1;

    for (n /= base; n != 0; n /= base)
        i++;
    return i;
}

int my_putnbr_base(char *s, size_t base, size_t n)
{
    int len = my_base_len(base, n);

    for (int i = len; i > 0; n /= base) {
        i--;
        s[i] = BASE_CHARSET[n % base];
    }
    return len;
}
