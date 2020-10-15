/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:56:15 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/15 19:55:52 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_position(t_stack *a, int min)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while (a)
	{
		if (min == a->n)
			pos = i;
		i++;
		a = a->next;
	}
	return (pos);
}

int		sort5(t_data *d, t_stack **stack_a, t_stack **stack_b)
{
	int		ret;
	int		i;
	int		min;


	//ft_putendl("in sort 5");
	ret = 0;
	i = 0;
	min = 0;
	d->op_n = d->op_n + first_two(stack_a, stack_b);
	d->op_n = d->op_n + sort3(d, stack_a);
	while (*stack_b)
	{
		i = 0;
		i = a_position(stack_a, stack_b, i);
		d->op_n = d->op_n + ra_rra_num(stack_a, i);
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	min = find_min(*stack_a);
	i = find_position(*stack_a, min);
	d->op_n = d->op_n + ra_rra_num(stack_a, i);
	return (d->op_n);
}

int		sort3(t_data *d, t_stack **stack_a)
{
	//int		n;
	int		ret;

	//op_n = 0;
	//ft_putendl("in sort 3");
	ret = 0;
	if ((*stack_a)->n > (*stack_a)->next->n && (*stack_a)->next->n < (*stack_a)->next->next->n
	&& (*stack_a)->next->next->n > (*stack_a)->n)
	{
		//ft_putendl("1 if");
		/*d->op_n = d->op_n + */sort3_sa(d, stack_a);
	}
	//if ((*stack_a)->n > stack_a->next->n && stack_a->next->n < stack_a->next->next->n
	//&& stack_a->next->next->n < stack_a->n)
	if ((*stack_a)->n > (*stack_a)->next->n && (*stack_a)->next->n < (*stack_a)->next->next->n
	&& (*stack_a)->next->next->n < (*stack_a)->n)
	{
		//ft_putendl("2 if");
		/*d->op_n = d->op_n + */sort3_ra(d, stack_a);
	}
	if ((*stack_a)->n < (*stack_a)->next->n && (*stack_a)->next->n > (*stack_a)->next->next->n
	&& (*stack_a)->next->next->n < (*stack_a)->n)
	{
		//ft_putendl("3 if");
		/*d->op_n = d->op_n + */sort3_rra(d, stack_a);
	}
	if ((*stack_a)->n < (*stack_a)->next->n && (*stack_a)->next->n > (*stack_a)->next->next->n
	&& (*stack_a)->next->next->n > (*stack_a)->n)
	{
		//ft_putendl("4 if");
		/*d->op_n = d->op_n + */sort3_sa_ra(d, stack_a);
	}
	if ((*stack_a)->n > (*stack_a)->next->n && (*stack_a)->next->n > (*stack_a)->next->next->n
	&& (*stack_a)->next->next->n < (*stack_a)->n)
	{
		//ft_putendl("5 if");
		/*d->op_n = d->op_n + */sort3_sa_rra(d, stack_a);
	}
	//ft_putendl("before is_sorted");
	//ret = is_sorted(stack_a);
	ret = 1;
	//ft_putendl("after is_sorted");
	if (ret == 1)
		return (d->op_n);
	return (0);
}