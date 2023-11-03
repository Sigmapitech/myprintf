/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#ifndef FLOAT_INTERNAL_H
    #define FLOAT_INTERNAL_H

typedef struct {
    int sign;
    unsigned long long exponant;
    unsigned long long mentissa;
} dpart_t;
void init_dpart(double d, dpart_t *dpart);

int handle_non_numbers(char *out, dpart_t dpart);
int put_in_str(char *out, const char *in);
void round_up(char *out, int len);

#endif
