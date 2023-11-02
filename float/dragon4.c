/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** dragon4.c
*/

#include <float.h>
#include <math.h>
#include "dragon4.h"
#include "my.h"

char *my_dtoa(double d)
{
    dbits_t dbits = *(dbits_t *)&d;
    dpart_t dpart;

    printf("raw float: [%064llb]\n", dbits);
    dpart.sign = (dbits >> 63) & 1;
    dpart.exponant = (dbits >> 52) & 0x7ff;
    dpart.mentissa = dbits & 0x000fffffffffffffL;
    printf(
        "parts: [%1llb][%11llb][%052llb]\n",
        dpart.sign, dpart.exponant, dpart.mentissa);
    return NULL;
}

int main(void)
{
    double pi = 3.141592653589793238462643383279502884L;
    double rand = 348748573910910340036.907308;
    double max = DBL_MAX;

    my_dtoa(pi);
    my_dtoa(rand);
    my_dtoa(max);
}
