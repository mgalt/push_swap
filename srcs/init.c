/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:00:29 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/11 20:20:28 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    fill_stack(t_data *d, int ac, char **av)
{
    //t_data      data;
    int         i;
    t_stack     *st1;

    i = 1;
    d->stack_a = NULL;
    d->stack_b = NULL;
    st1 = (t_stack*)malloc(sizeof(t_stack));
    if (!(d->stack_a = (t_stack*)malloc(sizeof(t_stack))))
        exit(err_memory());
    if (!(d->stack_b = (t_stack*)malloc(sizeof(t_stack))))
        exit(err_memory());
    d->stack_a = st1;
    while (i < ac)
    {
        st1->n = ft_atoi(av[i]);
		//st1->next = NULL;
		if (i < ac - 1)
		{
			if (!(st1->next = (t_stack*)malloc(sizeof(t_stack))))
				exit(err_memory());
			st1 = st1->next;
		}
		i++;
    }
	d->last_a = st1;
}