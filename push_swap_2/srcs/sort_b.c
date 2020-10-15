/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:48:10 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/15 14:53:21 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		pre_pb(t_stack **a, t_stack **b)
{
	int		i;
	int		pos;

	i = 0;
	pos = find_position(b, a);
	i += a_amount(b, pos) + 1;
	pb(a, b);
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
		i = i + a_amount(b, b_min_i) + 1;
        pb(a, b);
    }
	return (i);
}
