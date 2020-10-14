/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:51:19 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/14 17:38:26 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_a_min_i(t_stack *a, int a_min)
{
	int		i;

	i = 0;
	while (a)
	{
		if (a->n == a_min)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int		find_min(t_stack *a)
{
    int     min;

    min = INT_MAX;
    while (a)
    {
        if (min >= a->n)
            min = a->n;
        a = a->next;
    }
    return (min);
}

int		find_max(t_stack *a)
{
    int     max;

    max = INT_MIN;
    while (a)
    {
        if (max <= a->n)
            max = a->n;
        a = a->next;
    }
    return (max);
}

int     ft_abs(int n)
{
    if (n < 0)
        n = -n;
    return (n);
}