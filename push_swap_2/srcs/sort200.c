/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort200.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:03:56 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/15 20:04:37 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		r_or_rr_2(t_stack **a, t_stack **b, int pos, int len)
{
	int		op_n;
	int		max;

	op_n = 0;
	max = find_max(*b);
	while (len > pos)
	{
		rev_rot_ab(b);
		write(1, "rrb\n", 4);
		pos++;
		op_n++;
	}
	if ((*b)->n == max)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
	return (op_n);
}

int		r_or_rr(t_stack **a, t_stack **b, int pos)
{
	int		op_n;

	op_n = 0;
	while (pos > 0)
	{
		rotate_a_b(b);
		write(1, "rb\n", 3);
		pos--;
		op_n++;
	}
	if (pos == 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		op_n++;
	}
	return (op_n);
}

int		find_position_100(t_stack *b, int n, int pos)
{
	//int		pos;
	int		i;

	//pos = 0;
	i = -1;
	while (b)
	{
		i++;
		if (n == b->n)
			pos = i;
		b = b->next;
	}
	return (pos);
}

int		r_rr_100(t_stack **a, t_stack **b, int len)
{
	int		pos;
	int		n;
	int		max;
	int		op_n;

	op_n = 0;
	while (*b)
	{
		len = find_len(*b);
		n = len / 2;
		pos = 0;
		max = find_max(*b);
		pos = find_position_100(*b, max, pos);
		if (pos <= n)
			op_n = op_n + r_or_rr(a, b, pos); // мб тут лажа с op_n
		if (pos > n)
			op_n = op_n + r_or_rr_2(a, b, pos, len);
	}
	return (op_n);
}

int		medium_pos(t_stack *a, int max)
{
	int		n;
	int		i;

	n = 0;
	i = -1;
	while (a)
	{
		i++;
		//ft_putendl("in while in medium pos");
		if (a->n <= max)
			return (i);
		a = a->next;
		//i++;
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
	int		pos1;

	len = find_len(*a);
	max = len / 5;
	i = 0;
	pos1 = 0;
	while (range(*a, len1))
	{
		//ft_putendl("while in func");
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

int		medium(t_data *d, t_stack **a, t_stack **b)
{
	int		max;
	int		len;
	int		i;
	int		len1;
	int		pos;

	i = 1;
	len = find_len(*a);
	//printf("len in medium = %d\n", len);
	//ft_putendl("in medium\n");
	while (*a)
	{
		max = len / 5;
		len1 = max * i;
		pos = medium_pos(*a, max);
		if (range(*a, len1) == 1)
			d->op_n = d->op_n + func(a, b, pos, len1);
		i++;
	}
	if (!(*a))
		d->op_n = d->op_n + r_rr_100(a, b, len);
	return (d->op_n);
}
