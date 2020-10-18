/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 21:51:10 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 19:19:46 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int			is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == ' ' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

void		err_no_op(void)
{
	ft_putstr("\33[31mError\033[0330m\n");
	exit(1);
}

void		do_op(char *s, t_stack **a, t_stack **b)
{
	if (ft_strcmp(s, "sa") == 0)
		swap_a_b(a);
	else if (ft_strcmp(s, "sb") == 0)
		swap_a_b(b);
	else if (ft_strcmp(s, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(s, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(s, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(s, "ra") == 0)
		rotate_a_b(a);
	else if (ft_strcmp(s, "rb") == 0)
		rotate_a_b(b);
	else if (ft_strcmp(s, "rr") == 0)
		rr(a, b, 2);
	else if (ft_strcmp(s, "rra") == 0)
		rev_rot_ab(a);
	else if (ft_strcmp(s, "rrb") == 0)
		rev_rot_ab(b);
	else if (ft_strcmp(s, "rrr") == 0)
		rrr(a, b);
	else
		err_no_op();
}