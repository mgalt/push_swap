/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:19:28 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/19 18:24:40 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		push_new_min(t_stack **a, t_stack **b, int min)
{
	pb(a, b);
	write(1, "pb\n", 3);
	if (*a)
		min = find_min(*a);
	return (min);
}

int		final_sort(t_stack **a, t_stack **b)
{
	int		min;
	int		len;
	int		i;

	while (*a)
	{
		min = find_min(*a);
		len = find_len(*a);
		i = find_position(*a, min);
		if (min == (*a)->n)
		{
			min = push_new_min(a, b, min);
		}
	}
}