/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:32:45 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/11 20:43:18 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int    sort(t_data *d)
{
	ft_putendl("in sort");
    if (d->stack_a->next == NULL)
        return (0);
	if ((is_sorted(d->stack_a)) == 1)
		ft_putendl("Sorted");
	else
		ft_putendl("Not sorted");
    //while (!(is_sorted(d->stack_a)) || d->stack_b == NULL) // if stack isn't sorted
    //{

    //}
	return (0);
}

int     is_sorted(t_stack *s)
{
    t_stack     *tmp;

    tmp = s;
	ft_putendl("in is sorted");
    while (tmp->next != NULL)
    {
		ft_putendl("in is sorted while");
        if (tmp->n > tmp->next->n)
            return (0);
        tmp = tmp->next;
    }
	ft_putendl("in is sorted after while");
    return (1);
}