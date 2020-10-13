/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:48:37 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 21:56:06 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     is_sorted(t_stack *s)
{
    t_stack     *tmp;

    tmp = s;
	//ft_putendl("in is sorted");
    while (tmp->next != NULL)
    {
		//ft_putendl("in is sorted while");
        if (tmp->n > tmp->next->n)
            return (0);
        tmp = tmp->next;
    }
	//ft_putendl("in is sorted after while");
    return (1);
}

void	check_digits_overflow(char *arg)
{
	int		i;
	double	n;

	i = 0;
	n = 0.0;
	while (arg[i] != '\0')
	{
		if (!(ft_isdigit(arg[i])))
			exit(err_invalid_arg());
		i++;
	}
	n = ft_strtodbl(arg); // починить strtodbl, он переполняется
	if (n > INT_MAX || n < INT_MIN)
		exit(err_overflow());
}

int		sort_35(t_data *d, int ac)
{
	//int 	n;

	//n = 0;
	if (ac == 4)
		d->op_n = d->op_n + sort3(d, &d->stack_a);
	//if (ac == 6)
	//	d->op_n = d->op_n + sort5(d, d->stack_a);
	return (d->op_n);
}

int     main(int ac, char **av)
{
    int		i;
	t_data	data;
    int     n;
    //int     c;

	i = 1;
    n = -1;
    //c = 0;
    if (ac == 1)
        return(err_no_args());
    while (i < ac)
	{
		check_digits_overflow(av[i]);
		i++;
	}
	fill_stack(&data, ac, av);
    n = is_sorted(data.stack_a);
	//sdata.op_n = 0;
    if (data.stack_a == NULL || n == 1)
        return (0);
    if (ac > 3 && ac < 7)
        data.op_n = data.op_n + sort_35(&data, ac);
    //if (ac >= 7 && ac <= 800)
	//	data.op_n = data.op_n + a_lot(&data, i, ac);
	//if (ac > 800)
	//	data.op_n = data.op_n + too_much(&data, i);
	printf("operations number: %d\n", data.op_n);
	//free_stacks();
	return (0);
}