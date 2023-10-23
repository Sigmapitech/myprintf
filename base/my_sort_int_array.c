/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_sort_int_array.c
*/

#include "my.h"

static
void reorder_elements(int *arr, int i, int j)
{
    if (arr[i] < arr[j])
        my_swap(arr + i, arr + j);
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            reorder_elements(array, i, j);
}
