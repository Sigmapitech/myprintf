/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_internal.h
*/

#ifndef TEST_INTERNAL_H
    #define TEST_INTERNAL_H

    #include <float.h>
    #include <limits.h>
    #include <math.h>
    #include <stdio.h>

    #define CMP_PRINTF NULL

    #define MK_SCOPE(l, r, ...) l __VA_ARGS__ r
    #define STRUCT(...) MK_SCOPE({, }, __VA_ARGS__)

    #define TEST_CMP(f, e, a, t) STRUCT(f, e, &(union arg){a}, t)
    #define TEST_ENTRY(f, a, t) TEST_CMP(f, CMP_PRINTF, a, t)
    #define TEST_NO_ARG(f) TEST_ENTRY(f, .p = NULL, PTR)
    #define TEST_CMP_NO_ARG(f, e) TEST_CMP(f, e, .p = NULL, PTR)

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

static __attribute__((used))
const printf_test_t TESTS[] = {
    TEST_NO_ARG(""),
    TEST_NO_ARG("Hello"),
    TEST_NO_ARG("\n"),
    TEST_NO_ARG("%%"),
    TEST_NO_ARG("%10%"),
    TEST_NO_ARG("%#-0+ 6.3ll%"),
    TEST_ENTRY("%c", .c = '!', INT),
    TEST_ENTRY("%s", .p = "Hello world", PTR),
    TEST_ENTRY("%u", .i = -3, INT),
    TEST_ENTRY("%u", .i = 5412, INT),
    TEST_ENTRY("%u", .i = 0, INT),
    TEST_ENTRY("%#u", .i = 0, INT),
    TEST_ENTRY("%#u", .i = 692, INT),
    TEST_ENTRY("%#.0u", .i = 0, INT),
    TEST_ENTRY("%#.0u", .i = 4, INT),
    TEST_ENTRY("%s", .p = NULL, PTR),
    TEST_ENTRY("%.2s", .p = NULL, PTR),
    TEST_ENTRY("%.0s", .p = NULL, PTR),
    TEST_ENTRY("%.0s", .p = "hey", PTR),
    TEST_ENTRY("%8s", .p = "Hello!", PTR),
    TEST_ENTRY("%-8s", .p = "Hello!", PTR),
    TEST_ENTRY("%.3s", .p = "Hello!", PTR),
    TEST_ENTRY("%.9s", .p = "Hey", PTR),
    TEST_ENTRY("%5.3s", .p = "Hello!", PTR),
    TEST_ENTRY("%d", .i = -3, INT),
    TEST_ENTRY("%d", .i = 42, INT),
    TEST_ENTRY("%3i", .i = -28, INT),
    TEST_ENTRY("%5d", .i = 3301, INT),
    TEST_ENTRY("%2147483648d", .i = 0, INT),
    TEST_ENTRY("%9999999999d", .i = 0, INT),
    TEST_ENTRY("%1.2147483648d", .i = 0, INT),
    TEST_ENTRY("%1.9999999999d", .i = 0, INT),
    TEST_ENTRY("%-5d", .i = 3301, INT),
    TEST_ENTRY("%0d", .i = 3301, INT),
    TEST_ENTRY("%#d", .i = 987, INT),
    TEST_ENTRY("%.1d", .i = 0, INT),
    TEST_ENTRY("%.0d", .i = 0, INT),
    TEST_ENTRY("%.d", .i = 0, INT),
    TEST_ENTRY("%010d", .i = 3301, INT),
    TEST_ENTRY("%-010d", .i = 3301, INT),
    TEST_ENTRY("%0-10d", .i = 3301, INT),
    TEST_ENTRY("%p", .p = (const void *)&TESTS, PTR),
    TEST_ENTRY("%o", .i = 0, INT),
    TEST_ENTRY("%.0o", .i = 0, INT),
    TEST_ENTRY("%.0o", .i = 1, INT),
    TEST_ENTRY("%o", .i = 3301, INT),
    TEST_ENTRY("%X", .i = 0, INT),
    TEST_ENTRY("%.0X", .i = 0, INT),
    TEST_ENTRY("%.0x", .i = 1, INT),
    TEST_ENTRY("%x", .i = 3301, INT),
    TEST_ENTRY("%5o", .i = 1000, INT),
    TEST_ENTRY("%#o", .i = 0, INT),
    TEST_ENTRY("%#o", .i = 3301, INT),
    TEST_ENTRY("%x", .i = 1234, INT),
    TEST_ENTRY("%-8x", .i = 3890880, INT),
    TEST_ENTRY("%.11d", .i = 3890880, INT),
    TEST_ENTRY("%-.12d", .i = 50949, INT),
    TEST_ENTRY("%.6x", .i = 23, INT),
    TEST_ENTRY("%-.7x", .i = 100002, INT),
    TEST_ENTRY("%.2u", .i = 1, INT),
    TEST_ENTRY("%-.2u", .i = 2, INT),
    TEST_ENTRY("%.4o", .i = 94, INT),
    TEST_ENTRY("%-.10o", .i = 99999, INT),
    TEST_ENTRY("%X", .i = 57893, INT),
    TEST_ENTRY("%#X", .i = 42, INT),
    TEST_ENTRY("%#x", .i = 0, INT),
    TEST_ENTRY("%#015x", .i = 1, INT),
    TEST_ENTRY("%#015o", .i = -1, INT),
    TEST_ENTRY("%+5d", .i = 3301, INT),
    TEST_ENTRY("%+5d", .i = -42, INT),
    TEST_ENTRY("%+5x", .i = 3301, INT),
    TEST_ENTRY("%+5x", .i = -42, INT),
    TEST_ENTRY("% d", .i = -42, INT),
    TEST_ENTRY("% d", .i = 3301, INT),
    TEST_ENTRY("% 5d", .i = 3301, INT),
    TEST_ENTRY("% 5d", .i = -42, INT),
    TEST_ENTRY("% x", .i = -42, INT),
    TEST_ENTRY("% x", .i = 3301, INT),
    TEST_ENTRY("% +d", .i = 0, INT),
    TEST_ENTRY("%+ d", .i = 123, INT),
    TEST_ENTRY("%+ 12d", .i = 123, INT),
    TEST_ENTRY("%+.d", .i = 0, INT),
    TEST_ENTRY("%+.0d", .i = 0, INT),
    TEST_ENTRY("%+0.d", .i = 0, INT),
    TEST_ENTRY("% .d", .i = 0, INT),
    TEST_ENTRY("%ld", .l = LONG_MAX, LONG),
    TEST_ENTRY("%#-4.16ld", .l = LONG_MAX >> 13, LONG),
    TEST_ENTRY("%#-+4.16ld", .l = LONG_MAX >> 13, LONG),
    TEST_ENTRY("%# 0-+4.16zd", .l = LONG_MAX >> 13, LONG),
    TEST_ENTRY("%# 0-+4.16zd", .l = LONG_MIN >> 15, LONG),
    TEST_ENTRY("%# 0-+4.16ld", .l = LONG_MAX >> 15, LONG),
    TEST_ENTRY("%# 0-4.16ld", .l = LONG_MAX >> 15, LONG),
    TEST_ENTRY("%+lld", .l = LONG_MAX, LONG),
    TEST_ENTRY("%-8hd", .l = SHRT_MAX, LONG),
    TEST_ENTRY("% hd", .l = SHRT_MAX + 1, LONG),
    TEST_ENTRY("%0.5hhd", .l = CHAR_MAX + 1, LONG),
    TEST_ENTRY("%.12hhu", .l = INT_MAX, LONG),
    TEST_ENTRY("%+13lx", .l = LONG_MAX, LONG),
    TEST_ENTRY("%0llx", .l = ULLONG_MAX, LONG),
    TEST_ENTRY("%#+ho", .l = ULLONG_MAX, LONG),
    TEST_ENTRY("%-.12jd", .l = LONG_MIN >> 11, LONG),
    TEST_ENTRY("%-zx", .l = LONG_MIN >> 11, LONG),
    TEST_ENTRY("%0+18ju", .l = LONG_MAX >> 11, LONG),
    TEST_ENTRY("% #td", .l = LONG_MAX, LONG),
    TEST_ENTRY("%-0tX", .l = LONG_MIN >> 3, LONG),
    TEST_ENTRY("%f", .d = 123.456, DOUBLE),
    TEST_ENTRY("%f", .d = 0, DOUBLE),
    TEST_ENTRY("%f", .d = 123.0, DOUBLE),
    TEST_ENTRY("%f", .d = 0.456, DOUBLE),
    TEST_ENTRY("%f", .d = -123.456, DOUBLE),
    TEST_ENTRY("%f", .d = -123.0, DOUBLE),
    TEST_ENTRY("%f", .d = -0.456, DOUBLE),
    TEST_ENTRY("%.0f", .d = -0, DOUBLE),
    TEST_ENTRY("%#.0f", .d = -69, DOUBLE),
    TEST_ENTRY("%+f", .d = 123.456, DOUBLE),
    TEST_ENTRY("% f", .d = 123.456, DOUBLE),
    TEST_ENTRY("%+ f", .d = 123.456, DOUBLE),
    TEST_ENTRY("%+f", .d = -123.456, DOUBLE),
    TEST_ENTRY("%-5.3f", .d = -123.456, DOUBLE),
    TEST_ENTRY("%#0- 5.2f", .d = -123.456, DOUBLE),
    TEST_ENTRY("%f", .d = INFINITY, DOUBLE),
    TEST_ENTRY("%f", .d = -INFINITY, DOUBLE),
    TEST_ENTRY("%f", .d = NAN, DOUBLE),
    TEST_ENTRY("%.1f", .d = 3.14, DOUBLE),
    TEST_ENTRY("%08.3f", .d = 3.14, DOUBLE),
};

static
const int TEST_COUNT = sizeof(TESTS) / sizeof(TESTS[0]);

#endif
