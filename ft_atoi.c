/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussein <hussein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:51:08 by hussein           #+#    #+#             */
/*   Updated: 2025/11/04 15:23:33 by hussein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(const char *p)
{
    int i;

    i = 0;
    while(p[i] && p[i] >= '0' && p[i] <= '9')
        i++;
    return (i);
}

int nb(const char *p)
{
    int mult;
    int n;
    int sum;
    int i;
    int j;
    
    i= 0;
    sum = 0;
    n = ft_strlen(p);
    while(p[i] && p[i] >= '0' && p[i] <= '9')
    {
        j = 1;
        mult = 1;
        while(j < n)
        {
            j++;
            mult *= 10;
        }
        n--;
        sum += (p[i] - '0') * mult;
        i++;
    }
    return sum;
}

int ft_atoi(const char *nptr)
{
   const char* ptr;
    int i;
    int sign;
    int n;

    i = 0;
    sign = 1;
    ptr = nptr;
    while (ptr[i] && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32))
        i++;
    if (ptr[i] == '-')
    {
        i++;
        sign *= -1;
    }
    else if (ptr[i] == '+')
        i++;
    n = nb(&ptr[i]);
    return n * sign;
}
