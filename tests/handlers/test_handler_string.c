/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_string.c
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/parameterized.h>

#include <stdio.h>

const char *s[] = { NULL, "", "!", "hello", "say my name!" };
const char *flags = "#0-+ ";
int width[] = { 1, 5, 15 };
int prec[] = { 1, 5, 15 };

struct abcd {
    int a;
    int b;
    int c;
    int d;
};

static
void generate_ids(struct abcd *t)
{
    static char a = 0;
    static char b = 0;
    static char c = 0;
    static char d = 0;

    t->d = d;
    t->c = c;
    t->b = b;
    t->a = a;
    for (a++; a > 4; a = 0)
        b++;
    for (; b > 4; b = 0)
        c++;
    for (; c > 2; c = 0)
        d++;
    if (d > 2)
        d = 0;
}

ParameterizedTestParameters(params, simple)
{
    int count_val = 3 * 3 * 4 * 5;
    struct abcd *arr = cr_malloc(sizeof(struct abcd) * count_val);

    for (int i = 0; i < count_val; i++)
        generate_ids(&arr[i]);
    return cr_make_param_array(struct abcd, arr, count_val);
}

ParameterizedTest(struct abcd *t, params, simple, .init = cr_redirect_stdout)
{
    char buf[50];
    char exp[50];
    char out[50];
    FILE *f;

    memset(buf, '\0', 50);
    memset(out, '\0', 50);
    memset(exp, '\0', 50);
    snprintf(buf, 50, "[%%%c%d.%ds]", flags[t->b], width[t->c], prec[t->d]);
    snprintf(exp, 50, buf, s[t->a]);
    my_printf(buf, s[t->a]);
    f = cr_get_redirected_stdout();
    fread(out, 50, 50, f);
    fprintf(
        stderr, "%-10s %-20s %-20s %-20s\n", buf, s[t->a], exp, out);
    cr_assert_str_eq(out, exp);
    cr_assert_eq(1, 1);
}
