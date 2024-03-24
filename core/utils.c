#include <unistd.h>


int putnchar(int fd, char c, int nb)
{
    for (int n = nb; n--;)
        write(fd, &c, sizeof(char));
    return nb;
}
