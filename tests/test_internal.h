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

    #define TEST_CMP(n, f, e, a, t) STRUCT(n, f, e, &(union arg){a}, t)
    #define TEST_ENTRY(n, f, a, t) TEST_CMP(n, f, CMP_PRINTF, a, t)
    #define TEST_NO_ARG(n, f) TEST_ENTRY(n, f, .p = NULL, VOID_P)

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
    const char *name;
    const char *fmt;
    const char *exp;
    union arg *arg;
    enum type type;
} printf_test_t;

static __attribute__((used))
const printf_test_t TESTS[] = {
    TEST_NO_ARG("litteral empty string", ""),
    TEST_NO_ARG("literal string without newline", "Hello"),
    TEST_NO_ARG("literal newline", "\n"),
    TEST_ENTRY("basic %c specifier", "%c", .c = '!', CHAR),
    TEST_ENTRY("basic %s specifier", "%s", .s = "Hello world", CHAR_P),
    TEST_ENTRY("basic %u specifier", "%u", .i = -3, INT),
    TEST_ENTRY("NULL %s", "%s", .s = NULL, CHAR_P),
    TEST_ENTRY("NULL %s 2-witdh", "%.2s", .s = NULL, CHAR_P),
    TEST_ENTRY("NULL %s 0-witdh", "%.0s", .s = NULL, CHAR_P),
    TEST_ENTRY("string %s 0-witdh", "%.0s", .s = "hey", CHAR_P),
    TEST_ENTRY("string 8-width right padding", "%8s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("string 8-width left padding", "%-8s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("string with 3 char limit", "%.3s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("3c string with 9 char limit", "%.9s", .s = "Hey", CHAR_P),
    TEST_ENTRY("string 3 char limit and pad", "%5.3s", .s = "Hello!", CHAR_P),
    TEST_ENTRY("basic %d specifier", "%d", .i = 42, INT),
    TEST_ENTRY("digit 5-width right padding", "%5d", .i = 3301, INT),
    TEST_ENTRY("digit 5-width left padding", "%-5d", .i = 3301, INT),
    TEST_ENTRY("digit zero padding", "%0d", .i = 3301, INT),
    TEST_ENTRY("digit 10-zero padding", "%010d", .i = 3301, INT),
    TEST_ENTRY("pointer conversion", "%p", .p = (const void *)&TESTS, INT),
    TEST_ENTRY("octal conversion", "%o", .i = 3301, INT),
    TEST_ENTRY("padded octal conversion", "%5o", .i = 1000, INT),
    TEST_ENTRY("alr octal conversion", "%#o", .i = 3301, INT),
    TEST_ENTRY("lower hex conversion", "%x", .i = 1234, INT),
    TEST_ENTRY("upper hex conversion", "%X", .i = 57893, INT),
    TEST_ENTRY("alt upper hex conversion", "%#X", .i = 42, INT),
    TEST_ENTRY("alt lower hex conversion", "%#x", .i = 42, INT),
};

static
const int TEST_COUNT = sizeof(TESTS) / sizeof(TESTS[0]);

#endif
