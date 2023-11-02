/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** dragon4.h
*/

#ifndef DRAGON4_H
    #define DRAGON4_H

typedef unsigned long long dbits_t;

typedef struct {
    int sign;
    dbits_t exponant;
    dbits_t mentissa;
} dpart_t;

char *my_dtoa(double d);

#endif
