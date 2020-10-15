/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:48:10 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/15 19:57:26 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_position_b(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		pos;

	pos = 0;
	tmp = *b;
	if (a)
	{
		while (tmp)
		{
			pos++;
			if (tmp->next != NULL)
			{
				if ((*a)->n > tmp->n && (*a)->n < tmp->next->n)
					return (pos);
			}
			tmp = tmp->next;
		}
	}
	return (pos);
}

int		pre_pb(t_stack **a, t_stack **b)
{
	int		i;
	int		pos;

	i = 0;
	pos = find_position_b(a, b);
	i += rb_rrb_num(b, pos) + 1;
	pb(a, b);
	write(1, "pb\n", 3);
	return (i);
}

int		sort_b(t_stack **a, t_stack **b)
{
	long	b_max;
	long	b_min;
	int		b_min_i;
	int		i;

	i = 0;
	b_max = find_max(*b);
	b_min = find_min(*b);
	b_min_i = find_a_min_i(*b, b_min);
	if ((*b)->n < b_min || (*b)->n > b_max)
    {
		i = i + rb_rrb_num(b, b_min_i) + 1;
        pb(a, b);
		write(1, "pb\n", 3);
    }
	return (i);
}
