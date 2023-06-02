#include "../../include/check.h"

//
// Created by laura on 31-5-23.
//
static int phi_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int phi_atoi(const char *str)
{
    int		count;
    int		nbr;

    count = 0;
    nbr = 0;
    while (phi_isdigit(str[count]) != 0)
    {
        nbr = ((nbr * 10) + (str[count] - 48));
        count++;
    }
    return (nbr);
}