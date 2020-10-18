/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rrb_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:11:52 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 18:25:50 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		rrb_num(t_stack **a, int i)
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
			write(1, "rrb\n", 4);
			i--;
		}
	}
	return (n);
}

int		rb_num(t_stack **a, int i)
{
	int		n;
	int		len;

	n = i;
	len = find_len(*a);
	//if (i > 0)
	//{
		while (i != 0)
		{
			rotate_a_b(a);
			write(1, "rb\n", 3);
			i--;
		}
	//}
	return (i);
}

int		rb_rrb_num(t_stack **a, int a_min_i)
{
	int		len;
	int		i;

	len = 0;
	len = find_len(*a);
	i = 0;
	if (a_min_i < len / 2)
		i = i + rb_num(a, a_min_i);
	if (a_min_i >= len / 2)
		i = i + rrb_num(a, a_min_i);
	return (i);
}