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
    int len = strlen(s);

    memcpy(dest, s, 20);
    if (len < 20)
        memset(dest + len, '_', (20 - len));
    for (char *p = dest; *p != '\0'; p++)
        if (!IS_PRINT(*p))
            *p = (*p == '\n') ? '$' : '?';
    return dest;
}

static
void print_clean(
    char const *name,
    const char *out,
    const char *exp,
    int ret[2])
{
    static char cname[20];
    static char cexp[20];
    static char cout[20];

    memset(cexp, '_', 20);
    memset(cout, '_', 20);
    fprintf(
        stderr,
        "[%14s]: [out: %s] (%3d) | [exp: %s] (%3d)\n",
        clean(cname, name),
        clean(cout, out), ret[1],
        clean(cexp, exp), ret[0]
    );
}

static
int run_printf(printf_test_t *p)
{
    switch (p->type) {
        case PTR:
            return my_printf(p->fmt, p->arg->p);
        case INT:
            return my_printf(p->fmt, p->arg->i);
        case DOUBLE:
            return my_printf(p->fmt, p->arg->d);
    }
    return -1;
}

static
int run_snprintf(printf_test_t *p, char *exp)
{
    switch (p->type) {
        case PTR:
            return snprintf(exp, 500, p->fmt, p->arg->p);
        case INT:
            return snprintf(exp, 500, p->fmt, p->arg->i);
        case DOUBLE:
            return snprintf(exp, 500, p->fmt, p->arg->d);
    }
    return -1;
}

ParameterizedTest(
    printf_test_t *p, test_myprintf, auto_tests, .init = cr_redirect_stdout)
{
    int ret[2];
    static char exp[20];
    static char out[20];
    FILE *f;

    memset(out, '\0', sizeof(out));
    memset(exp, '\0', sizeof(exp));
    if (p->exp == CMP_PRINTF)
        ret[0] = run_snprintf(p, exp);
    else {
        strncpy(exp, p->exp, 20);
        ret[0] = strlen(exp);
    }
    ret[1] = run_printf(p);
    f = cr_get_redirected_stdout();
    fread(out, 20, 20, f);
    print_clean(p->fmt, out, exp, ret);
    cr_assert_str_eq(out, exp);
    cr_assert_eq(ret[0], ret[1]);
}

Test(my_printf, n_conversion, .init = cr_redirect_stdout)
{
    int out[2];
    int ret[2];

    ret[0] = my_printf("Hello%n world!", &out[0]);
    ret[1] = printf("Hello%n world!", &out[1]);
    cr_assert_eq(out[0], out[1]);
    cr_assert_eq(ret[0], ret[1]);
}

Test(my_printf, null_format, .init = cr_redirect_stdout)
{
    int ret[2];

    ret[0] = printf(NULL);
    ret[1] = my_printf(NULL);
    cr_assert_eq(ret[0], ret[1]);
}

/* Only test that the the code is crash-free
 * C99: If a conversion specification is invalid, the behavior is undefined */
Test(my_printf, invalid_conv_specifier, .init = cr_redirect_stdout)
{
    my_printf("[%&] [%.R] [%#1M] [%9.2~] [% +!]");
    my_printf("%");
    my_printf("%0");
    my_printf("%.");
    my_printf("%#-12");
    my_printf("%+.");
    my_printf("% .8");
}
