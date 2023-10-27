/*
** EPITECH PROJECT, 2023
** Day05-Recursivity
** File description:
** Task03 - return nb to the power of p
*/
int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    return nb * my_compute_power_rec(nb, p -1);
}
