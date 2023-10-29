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

    #define TEST_ENTRY(n, f, e, a, t) STRUCT(n, f, e, &(union arg){a}, t)

enum type {
    VOID_P,
    CHAR_P,
    INT,
};

union arg {
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
    TEST_ENTRY(
        "litteral empty string",
        "", CMP_PRINTF,
        .p = NULL, VOID_P
    ),
    TEST_ENTRY(
        "literal string without newline",
        "Hello", CMP_PRINTF,
        .p = NULL, VOID_P
    ),
    TEST_ENTRY(
        "literal newline",
        "\n", CMP_PRINTF,
        .p = NULL, VOID_P
    ),
    TEST_ENTRY(
        "basic %s specifier",
        "%s", CMP_PRINTF,
        .s = "Hello world", VOID_P
    ),
    TEST_ENTRY(
        "basic %d specifier",
        "%d", CMP_PRINTF,
        .i = 42, INT
    ),
    TEST_ENTRY(
        "digit 5-width right padding",
        "%5d", CMP_PRINTF,
        .s = "Hello world", CHAR_P
    ),
};

static
const int TEST_COUNT = sizeof(TESTS) / sizeof(TESTS[0]);

#endif
