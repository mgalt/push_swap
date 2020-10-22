/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:00:29 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/22 12:33:30 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    fill_stack(t_data *d, int ac, char **av)
{
    //t_data      data;
    int         i;
    t_stack     *st1;

    i = 1;
    //d->min = INT_MAX;
   // d->max = INT_MIN;
    d->stack_a = NULL;
    d->stack_b = NULL;
    //d->min_num = 1;
    d->op_n = 0;
    if (!(st1 = (t_stack*)malloc(sizeof(t_stack))))
        exit(err_memory());
    d->stack_a = st1;
    while (i < ac)
    {
        st1->n = ft_atoi(av[i]);
		st1->next = NULL;
		if (i < ac - 1)
		{
			if (!(st1->next = (t_stack*)malloc(sizeof(t_stack))))
				exit(err_memory());
			st1 = st1->next;
		}
		i++;
    }
	//d->last_a = st1;
}

t_stack		*parse_stack(int argc,
				char **argv, t_data *d)
{
	t_stack	*stack;
	int		size;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		exit(err_memory());
	size = 0;
	if (argc == 2 && !ft_isnum(argv[1], 10))
		d->stack_a = parse_str(stack, argv[1], d);
	else
	{
		d->len = argc - 1;
		parse_arr(stack, argc, argv, d);
	}
	if (!d->len)
		return (NULL);
	return (d->stack_a);
}	
