/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:48:37 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 17:08:08 by mgalt            ###   ########.fr       */
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
	int 	n;

	n = 0;
	if (ac == 4)
		i = i + sort3(d->stack_a);
	if (ac == 6)
		i = i + sort5(d->stack_a);
	return (i);
}

int     main(int ac, char **av)
{
    int		i;
	t_data	data;
    int     n;
    int     c;

	i = 1;
    n = -1;
    c = 0;
    if (ac == 1)
        return(err_no_args());
    while (i < ac)
	{
		check_digits_overflow(av[i]);
		i++;
	}
	fill_stack(&data, ac, av);
    n = is_sorted(data.stack_a);
    if (data.stack_a == NULL || n == 1)
        return (0);
    if (ac > 3 && ac < 7)
        c = c + sort_35(&data, ac);
    if (ac >= 7 && ac <= 800)
		c = c + a_lot(&data, i, ac);
	if (ac > 800)
		c = c + too_much(&data, i);
	
}