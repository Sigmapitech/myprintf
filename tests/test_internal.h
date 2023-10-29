/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#ifndef TEST_INTERNAL_H
    #define TEST_INTERNAL_H

    #include <stdio.h>
    #include <float.h>
    #define CMP_PRINTF NULL

    #define MK_SCOPE(l, r, ...) l __VA_ARGS__ r
    #define STRUCT(...) MK_SCOPE({, }, __VA_ARGS__)

    #define TEST_CMP(f, e, a, t) STRUCT(f, e, &(union arg){a}, t)
    #define TEST_ENTRY(f, a, t) TEST_CMP(f, CMP_PRINTF, a, t)
    #define TEST_NO_ARG(f) TEST_ENTRY(f, .p = NULL, VOID_P)

enum type {
    CHAR,
    VOID_P,
    CHAR_P,
    INT,
};

union arg {
    const char c;
    const char *s;
    const int i;
    const void *p;
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
    TEST_ENTRY("%c", .c = '!', CHAR),
    TEST_ENTRY("%s", .s = "Hello world", CHAR_P),
    TEST_ENTRY("%u", .i = -3, INT),
    TEST_ENTRY("%s", .s = NULL, CHAR_P),
    TEST_ENTRY("%.2s", .s = NULL, CHAR_P),
    TEST_ENTRY("%.0s", .s = NULL, CHAR_P),
    TEST_ENTRY("%.0s", .s = "hey", CHAR_P),
    TEST_ENTRY("%8s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("%-8s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("%.3s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("%.9s", .s = "Hey", CHAR_P),
    TEST_ENTRY("%5.3s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("%d", .i = 42, INT),
    TEST_ENTRY("%5d", .i = 3301, INT),
    TEST_ENTRY("%-5d", .i = 3301, INT),
    TEST_ENTRY("%0d", .i = 3301, INT),
    TEST_ENTRY("%010d", .i = 3301, INT),
    TEST_ENTRY("%-010d", .i = 3301, INT),
    TEST_ENTRY("%0-10d", .i = 3301, INT),
    TEST_ENTRY("%p", .p = (const void *)&TESTS, INT),
    TEST_ENTRY("%o", .i = 3301, INT),
    TEST_ENTRY("%5o", .i = 1000, INT),
    TEST_ENTRY("%#o", .i = 3301, INT),
    TEST_ENTRY("%x", .i = 1234, INT),
    TEST_ENTRY("%X", .i = 57893, INT),
    TEST_ENTRY("%#X", .i = 42, INT),
    TEST_ENTRY("%#x", .i = 42, INT),
};

static
const int TEST_COUNT = sizeof(TESTS) / sizeof(TESTS[0]);

#endif
