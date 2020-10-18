/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 21:42:04 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 19:15:22 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


// gcc -o checker srcs/checker_src/*.c -I libft/*.c

int		read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		do_op(line, a, b);
		free(line);
	}
	if (*b)
	{
		ft_putstr("\33[31mKO\033[0m\n");
		//exit(-1);
		return (0);
	}
	if (is_sorted(*a) == 1)
		ft_putstr("\033[32mOK\033[0m\n");
	else
		ft_putstr("\033[31mKO\033[0m\n");
	return (0);
}

int		main(int ac, char **av)
{
	t_data	d;
	int		n;

	n = 0;
	if (ac < 2)
		return (0);
	fill_stack(&d, ac, av);
	//n = is_sorted(d.stack_a);
    if (d.stack_a == NULL)
        return (0);
	read_instructions(&d.stack_a, &d.stack_b);
	return (0);
}
