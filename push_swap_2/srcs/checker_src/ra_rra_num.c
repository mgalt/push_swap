/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rra_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:48 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 18:25:14 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		find_len(t_stack *a)
{
	int		i;

	i = 0;
	while (a)
	{
		if (a)
			i++;
		a = a->next;
	}
	return (i);
}

int		rra_num(t_stack **a, int i)
{
	int		n;
	int		len;

	len = find_len(*a);
	i = len - i;
	n = i;
	if (i > 0)
	{
		while (i != 0)
		{
			rev_rot_ab(a);
			write(1, "rra\n", 4);
			i--;
		}
	}
	return (n);
}

int		ra_num(t_stack **a, int i)
{
	int		n;
	int		len;

	n = i;
	len = find_len(*a);
	if (i > 0)
	{
		while (i != 0)
		{
			rotate_a_b(a);
			write(1, "ra\n", 3);
			i--;
		}
	}
	return (i);
}

int		ra_rra_num(t_stack **a, int a_min_i)
{
	int		len;
	int		i;

	len = 0;
	len = find_len(*a);
	i = 0;
	if (a_min_i < len / 2)
		i = i + ra_num(a, a_min_i);
	if (a_min_i >= len / 2)
		i = i + rra_num(a, a_min_i);
	return (i);
}
