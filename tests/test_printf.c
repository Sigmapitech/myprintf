/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_printf.c
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
void print_clean(
    char const *name,
    const char *out,
    const char *exp,
    int ret[2])
{
    static char cname[500];
    static char cexp[500];
    static char cout[500];

    fprintf(
        stderr,
        "[%14s]: [out: %-20s] (%3d) | [exp: %-20s] (%3d)\n",
        clean(cname, name),
        clean(cout, out), ret[1],
        clean(cexp, exp), ret[0]
    );
}

static
int run_printf(printf_test_t *p)
{
    switch (p->type) {
        case VOID_P:
            return my_printf(p->fmt, p->arg->p);
        case CHAR_P:
            return my_printf(p->fmt, p->arg->s);
        case CHAR:
        case INT:
            return my_printf(p->fmt, p->arg->i);
    }
    return -1;
}

static
int run_snprintf(printf_test_t *p, char *exp)
{
    switch (p->type) {
        case VOID_P:
            return snprintf(exp, 500, p->fmt, p->arg->p);
        case CHAR_P:
            return snprintf(exp, 500, p->fmt, p->arg->s);
        case CHAR:
        case INT:
            return snprintf(exp, 500, p->fmt, p->arg->i);
    }
    return -1;
}

ParameterizedTest(
    printf_test_t *p, test_myprintf, auto_tests, .init = cr_redirect_stdout)
{
    int ret[2];
    static char exp[500];
    static char out[500];
    FILE *f;

    memset(out, '\0', sizeof(out));
    memset(exp, '\0', sizeof(exp));
    if (p->exp == CMP_PRINTF)
        ret[0] = run_snprintf(p, exp);
    else {
        strncpy(exp, p->exp, 500);
        ret[0] = strlen(exp);
    }
    ret[1] = run_printf(p);
    f = cr_get_redirected_stdout();
    fread(out, 500, 500, f);
    print_clean(p->fmt, out, exp, ret);
    cr_assert_str_eq(out, exp);
    cr_assert_eq(ret[0], ret[1]);
}
