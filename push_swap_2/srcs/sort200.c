/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort200.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:03:56 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/15 14:41:46 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		medium_pos(t_stack *a, int max)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (a)
	{
		if (a->n <= max)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int		range(t_stack *a, int max)
{
	while (a)
	{
		if (a->n <= max)
			return (1);
		a = a->next;
	}
	return (0);
}

int		func(t_stack **a, t_stack **b, int pos, int len1)
{
	int		len;
	int		max;
	int		i;
	int		pos;

	len = find_len(*a);
	max = len / 5;
	i = 0;
	pos = 0;
	while (range(*a, len1))
	{
		pos = medium_pos(*a, max);
		if ((*a) && !((*a)->n <= len1))
			i = i + a_amount(a, pos);
		if ((*a) && (*a)->n <= len1)
		{
			if (find_len(*b) == 1 || (!*b))
				i = i + b_empty_or_one();
		}
	}
}

int		medium(t_data *d, t_stack **a, t_stack **b)
{
	int		max;
	int		len;
	int		i;
	int		len1;
	int		pos;

	i = 1;
	len = find_len(*a);
	while (*a)
	{
		max = len / 2;
		len1 = max * i;
		pos = medium_pos(*a, max);
		if (range(*a, len1))
			d->op_n = d->op_n + func(a, b, pos, len1);
	}
	if (!*a)
		d->op_n = d->op_n + r_rr_100(a, b, len);
	return (d->op_n);
}