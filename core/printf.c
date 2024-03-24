#include <stdarg.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

int my_printf(const char *format, ...)
{
    int written;
    va_list ap;

    if (format == NULL)
        return -1;
    va_start(ap, format);
    written = my_vdprintf(STDOUT_FILENO, format, ap);
    va_end(ap);
    return written;
}
