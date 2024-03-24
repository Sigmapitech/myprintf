#ifndef TEST_INTERNAL_H
    #define TEST_INTERNAL_H

    #include <float.h>
    #include <limits.h>
    #include <math.h>
    #include <stdio.h>

    #define TEST_BUFFER_SIZE 256
    #define TEST_PRINT_SIZE 20

enum type {
    PTR,
    INT,
    LONG,
    DOUBLE
};

union arg {
    const char c;
    const int i;
    const long l;
    const void *p;
    const double d;
};

typedef struct printf_test {
    const char *fmt;
    const char *exp;
    union arg *arg;
    enum type type;
} printf_test_t;

#endif
