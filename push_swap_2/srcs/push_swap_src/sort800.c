/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort800.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:47:31 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 18:26:16 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		func1(t_stack **a, t_stack **b, int pos, int len1)
{
	int		len;
	int		max;
	int		i;
	int		pos1;

	len = find_len(*a);
	max = len / 11;
	i = 0;
	pos1 = 0;
	while (range(*a, len1))
	{
		pos = medium_pos(*a, max);
		if ((*a) && !((*a)->n <= len1))
			i = i + ra_rra_num(a, pos);
		if ((*a) && (*a)->n <= len1)
		{
			if (find_len(*b) == 1 || (!*b))
			{
				pb(a, b);
				i++;
			}
		}
		if (find_len(*b) > 1 && (*a) && (*a)->n <= len1)
			i = i + sort_b(a, b);
		if (find_len(*b) > 1 && (*a) && (*a)->n <= len1)
			i = i + pre_pb(a, b);
	}
	return (i);
}

int		large(t_data *d, t_stack **a, t_stack **b)
{
	int		max;
	int		len;
	int		i;
	int		len1;
	int		pos;

	i = 0;
	len = find_len(*a);
	while (*a)
	{
		i++;
		max = len / 11;
		len1 = max * i;
		pos = medium_pos(*a, max);
		if (range(*a, len1) == 1)
			d->op_n = d->op_n + func1(a, b, pos, len1);
		i++;
	}
	if (!(*a))
		d->op_n = d->op_n + r_rr_100(a, b, len);
	return (d->op_n);
}