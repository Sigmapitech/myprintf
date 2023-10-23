#include "internal.h"

int print_char(int fd, print_info_t pinfo)
{
    return write(fd, c, 1);
}

int print_int(int fd, print_info_t pinfo)
{
    pinfo->arg.i = va_arg(pinfo->ap, int);
    return put_nbr(fd, pinfo->arg.i);
}
