#include "../my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n == 0)
        return 0;
    for (; n > 1 && *s1 && *s1 == *s2; --n) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
