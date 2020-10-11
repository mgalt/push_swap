/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:12:17 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/11 20:41:27 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -o exec srcs/main.c srcs/error.c srcs/utils.c srcs/init.c srcs/sort.c -I libft/*.c

#include "../push_swap.h"

/*int		err_no_args(void)
{
	ft_putstr_fd("Error: no arguments!\n", 2);
	return (-1);
}*/

// в check args пройтись по аргументам, проверить являются ли цифрами, потом проверить на переполнения, переведя аргументы в дабл

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

int     main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 1;
    if (ac == 1)
        return(err_no_args());
	while (i < ac)
	{
		check_digits_overflow(av[i]);
		i++;
	}
	fill_stack(&data, ac, av);
	/*i = 1;
	while (i < 4)
	{
		printf("%d\n", data.stack_a->n);
		data.stack_a = data.stack_a->next;
		i++;
	}*/
	sort(&data);
	return (0);
}