#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <criterion/redirect.h>

#include "my.h"
#include "test_internal.h"

static
const printf_test_t TESTS[] = {
#include "test_printf_table.h"
};

ParameterizedTestParameters(test_myprintf, auto_tests)
{
    return cr_make_param_array(printf_test_t, TESTS, LENGTH_OF(TESTS));
}

static
char *clean(char *dest, const char *s)
{
    int len = strlen(s);

    memcpy(dest, s, TEST_BUFFER_SIZE);
    if (len < TEST_BUFFER_SIZE)
        memset(dest + len, '_', (TEST_BUFFER_SIZE - len));
    for (size_t i = 0; i < TEST_BUFFER_SIZE; i++)
        if (!IS_PRINT(dest[i]))
            dest[i] = (dest[i] == '\n') ? '$' : '?';
    return dest;
}

static
void print_clean(
    char const *name, const char *out, const char *exp,
    int ret[2])
{
    char cname[TEST_BUFFER_SIZE] = { '_' };
    char cexp[TEST_BUFFER_SIZE] = { '_' };
    char cout[TEST_BUFFER_SIZE] = { '_' };

    fprintf(
        stderr,
        "[%.14s]: [out: %.*s] (%3d) | [exp: %.*s] (%3d)\n",
        clean(cname, name),
        TEST_PRINT_SIZE, clean(cout, out), ret[1],
        TEST_PRINT_SIZE, clean(cexp, exp), ret[0]
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
        case LONG:
            return my_printf(p->fmt, p->arg->l);
        case DOUBLE:
            return my_printf(p->fmt, p->arg->d);
    }
    __builtin_unreachable();
}

static
int run_snprintf(printf_test_t *p, char *exp)
{
    switch (p->type) {
        case PTR:
            return snprintf(exp, TEST_BUFFER_SIZE, p->fmt, p->arg->p);
        case INT:
            return snprintf(exp, TEST_BUFFER_SIZE, p->fmt, p->arg->i);
        case LONG:
            return snprintf(exp, TEST_BUFFER_SIZE, p->fmt, p->arg->l);
        case DOUBLE:
            return snprintf(exp, TEST_BUFFER_SIZE, p->fmt, p->arg->d);
    }
    __builtin_unreachable();
}

ParameterizedTest(
    printf_test_t *p, test_myprintf, auto_tests, .init = cr_redirect_stdout)
{
    int ret[2];
    char exp[TEST_BUFFER_SIZE] = { '\0' };
    char out[TEST_BUFFER_SIZE] = { '\0' };
    FILE *f;

    if (p->exp == CMP_PRINTF)
        ret[0] = run_snprintf(p, exp);
    else {
        memcpy(exp, p->exp, sizeof exp);
        ret[0] = strlen(exp);
    }
    ret[1] = run_printf(p);
    f = cr_get_redirected_stdout();
    fread(out, LENGTH_OF(out), sizeof *out, f);
    print_clean(p->fmt, out, exp, ret);
    cr_assert(!memcmp(exp, out, LENGTH_OF(out)));
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
    int ret;

    ret = my_printf(NULL);
    cr_assert_eq(ret, -1);
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
