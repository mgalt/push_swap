/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:04:40 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/15 19:56:12 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sort_stack_a(t_stack **a, t_stack **b)
{
	/*long	b_max;
	long	b_min;
	int		b_min_i;
	int		i;

	i = 0;
	b_max = find_max(*b);
	b_min = find_min(*b);*/
	long	a_max;
	long	a_min;
	int		a_min_i;
	int		i;

	i = 0;
	a_max = find_max(*a);
	a_min = find_min(*a);
	a_min_i = find_a_min_i(*a, a_min);
	if ((*b)->n < a_min || (*b)->n > a_max)
		i = i + ra_rra_num(a, a_min_i);
	return (i);

}

int		a_position(t_stack **a, t_stack **b, int i)
{
	t_stack		*tmp;

	tmp = *a;
	if (*b)
	{
		if ((*b)->n > find_max(*a) || (*b)->n < find_min(*a))
			sort_stack_a(a, b);
		else
		{
			while (tmp)
			{
				i++;
				if (tmp->next)
				{
					if ((*b)->n > tmp->n && (*b)->n < tmp->next->n)
						return (i);
				}
				tmp = tmp->next;
			}
		}
	}
	return (i);
}

int		first_two(t_stack **a, t_stack **b)
{
	int		i;

	i = 0;
	//ft_putendl("in first two");
	while (i < 2)
	{
		pb(a, b);
		write(1, "pb\n", 3);
		i++;
	}
	return (2);
}
