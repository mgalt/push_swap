/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:19:28 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/22 13:30:58 by mgalt            ###   ########.fr       */
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

int		ra_rra_2(t_stack **a, int len1, int op_n)
{
	while (len1 > 0)
	{
		rev_rot_ab(a);
		write(1, "rra\n", 4);
		len1--;
		op_n++;
	}
	return (op_n);
}

int		ra_rra(t_stack **a, int len, int pos)
{
	int		op_n;
	int		h;
	int		len1;

	op_n = 0;
	h = len / 2;
	len1 = len - pos;
	if (pos <= h)
	{
		while (pos > 0)
		{
			rotate_a_b(a);
			write(1, "ra\n", 3);
			pos--;
			op_n++;
		}
	}
	if (pos > h)
		op_n = op_n + ra_rra_2(a, len1, op_n);
	return (op_n);
}

int		final_sort(t_stack **a, t_stack **b)
{
	int		min;
	int		len;
	int		i;
	int		op_n;

	op_n = 0;
	while (*a)
	{
		min = find_min(*a);
		len = find_len(*a);
		i = find_position(*a, min);
		if (min == (*a)->n)
		{
			min = push_new_min(a, b, min);
			len = find_len(*a);
			i = find_position(*a, min);
			op_n++;
		}
		if (*a)
			op_n = op_n + ra_rra(a, len, i);
		if (is_sorted_2(*a, *b) == 1)
			return (op_n);
		if (*a)
		{
			pb(a, b);
			op_n++;
			write(1, "pb\n", 3);
		}
	}
	return (op_n);
}