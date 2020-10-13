/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:56:15 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 17:40:20 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sort3(t_stack *stack_a)
{
	int		n;
	int		ret;

	n = 0;
	ret = 0;
	if (stack_a->n > stack_a->next->n && stack_a->next->n < stack_a->next->next->n
	&& stack_a->next->next->n > stack_a->n)
		n = n + sort3_sa(stack_a);
	if (stack_a->n > stack_a->next->n && stack_a->next->n < stack_a->next->next->n
	&& stack_a->next->next->n < stack_a->n)
		n = n + sort3_ra(stack_a);
	if (stack_a->n < stack_a->next->n && stack_a->next->n > stack_a->next->next->n
	&& stack_a->next->next->n < stack_a->n)
		n = n + sort3_rra(stack_a);
	if (stack_a->n < stack_a->next->n && stack_a->next->n > stack_a->next->next->n
	&& stack_a->next->next->n > stack_a->n)
		n = n + sort3_sa_ra(stack_a);
	if (stack_a->n > stack_a->next->n && stack_a->next->n > stack_a->next->next->n
	&& stack_a->next->next->n < stack_a->n)
		n = n + sort3_sa_rra(stack_a);
	ret = is_sorted(stack_a);
	if (ret == 1)
		return (n);
	return (0);
}