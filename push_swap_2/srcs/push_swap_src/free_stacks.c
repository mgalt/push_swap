/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:58:35 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 19:58:55 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stacks(t_data *d)
{
	t_stack		*tmp;
	t_stack		*tmp1;

	while (d->stack_a)
	{
		tmp = d->stack_a;
		tmp->n = 0;
		d->stack_a = d->stack_a->next;
		free(tmp);
	}
	while (d->stack_b)
	{
		tmp1 = d->stack_b;
		tmp1->n = 0;
		d->stack_b = d->stack_b->next;
		free(tmp1);
	}
}