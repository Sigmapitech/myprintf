/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
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
