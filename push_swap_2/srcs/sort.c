/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:56:15 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 20:54:31 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sort3(t_data *d, t_stack **stack_a)
{
	//int		n;
	int		ret;

	//op_n = 0;
	ret = 0;
	/*if (stack_a->n > stack_a->next->n && stack_a->next->n < stack_a->next->next->n
	&& stack_a->next->next->n > stack_a->n)
	{*/
		//ft_putendl("1 if");
		/*d->op_n = d->op_n + sort3_sa(d, stack_a);*/
	//}
	//if ((*stack_a)->n > stack_a->next->n && stack_a->next->n < stack_a->next->next->n
	//&& stack_a->next->next->n < stack_a->n)
	if ((*stack_a)->n > (*stack_a)->next->n && (*stack_a)->next->n < (*stack_a)->next->next->n
	&& (*stack_a)->next->next->n < (*stack_a)->n)
	{
		//ft_putendl("2 if");
		/*d->op_n = d->op_n + */sort3_ra(d, stack_a);
	}
	/*if (stack_a->n < stack_a->next->n && stack_a->next->n > stack_a->next->next->n
	&& stack_a->next->next->n < stack_a->n)
	{
		//ft_putendl("3 if");
		/*d->op_n = d->op_n + sort3_rra(d, stack_a);
	}
	if (stack_a->n < stack_a->next->n && stack_a->next->n > stack_a->next->next->n
	&& stack_a->next->next->n > stack_a->n)
	{
		//ft_putendl("4 if");
		/*d->op_n = d->op_n + sort3_sa_ra(d, stack_a);
	}
	if (stack_a->n > stack_a->next->n && stack_a->next->n > stack_a->next->next->n
	&& stack_a->next->next->n < stack_a->n)
	{
		//ft_putendl("5 if");
		/*d->op_n = d->op_n + sort3_sa_rra(d, stack_a);
	}*/
	ft_putendl("before is_sorted");
	//ret = is_sorted(stack_a);
	ret = 1;
	ft_putendl("after is_sorted");
	if (ret == 1)
		return (d->op_n);
	return (0);
}