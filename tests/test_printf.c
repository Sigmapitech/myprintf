/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_string.c
*/

#include "my.h"
#include "test_internal.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/parameterized.h>

#include <stdio.h>

ParameterizedTestParameters(test_myprintf, auto_tests)
{
    return cr_make_param_array(struct printf_test, TESTS, TEST_COUNT);
}

static
char *clean(char *dest, const char *s)
{
    strncpy(dest, s, 500);
    for (char *p = dest; *p != '\0'; p++)
        if (!IS_PRINT(*p))
            *p = '.';
    return dest;
}

static
void print_clean(char const *name, const char *out, const char *exp)
{
    static char cname[500];
    static char cexp[500];
    static char cout[500];

    fprintf(
        stderr,
        "[%14s]: [out: %-20s] [exp: %-20s]\n",
        clean(cname, name), clean(cout, out), clean(cexp, exp)
    );
}

static
void run_printf(printf_test_t *p)
{
    switch (p->type) {
        case VOID_P:
            my_printf(p->fmt, p->arg->p);
            break;
        case CHAR_P:
            my_printf(p->fmt, p->arg->s);
            break;
        case CHAR:
        case INT:
            my_printf(p->fmt, p->arg->i);
            break;
    }
}

static
void run_snprintf(printf_test_t *p, char *exp)
{
    switch (p->type) {
        case VOID_P:
            snprintf(exp, 500, p->fmt, p->arg->p);
            break;
        case CHAR_P:
            snprintf(exp, 500, p->fmt, p->arg->s);
            break;
        case CHAR:
        case INT:
            snprintf(exp, 500, p->fmt, p->arg->i);
            break;
    }
}

ParameterizedTest(
    struct printf_test *p,
    test_myprintf, auto_tests, .init = cr_redirect_stdout)
{
    static char exp[500];
    static char out[500];
    FILE *f;

    memset(out, '\0', sizeof(out));
    memset(exp, '\0', sizeof(exp));
    if (p->exp == CMP_PRINTF)
        run_snprintf(p, exp);
    else
        strncpy(exp, p->exp, 500);
    run_printf(p);
    f = cr_get_redirected_stdout();
    fread(out, 500, 500, f);
    print_clean(p->fmt, out, exp);
    cr_assert_str_eq(out, exp);
}
