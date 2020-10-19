/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:48:37 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/19 18:19:18 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdbool.h>

//gcc -o exec srcs/main.c srcs/error.c srcs/utils.c srcs/init.c srcs/sort.c srcs/pa_pb_rra_rrb_rrr.c srcs/ra_rra_num.c srcs/sa_sb_ss_ra_rb_rr.c srcs/sort3.c srcs/sort5.c srcs/utils2.c -I libft/*.c

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
	//ft_putendl("in sort 35");
	if (/*ac == 4 || */d->len == 3)
		d->op_n = d->op_n + sort3(d, &d->stack_a);
	if (/*ac == 6 || */d->len == 5)
		d->op_n = d->op_n + sort5(d, &d->stack_a, &d->stack_b);
	return (d->op_n);
}

int		ft_isspace(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}


int	ft_isprefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (ft_toupper(str[i]) == 'B'))
			return (1);
		if (base == 16 && (ft_toupper(str[i]) == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}


/*int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}*/


int		ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (ft_toupper(c) == digits[i])
			return (i);
		i++;
	}
	return (-1);
}


int	ft_isint(const char *str, int strict)
{
	unsigned int	result;
	unsigned int	border;
	int				i;
	int				sign;
	int				digits;

	result = 0;
	digits = 0;
	border = (unsigned int)(INT_MAX / 10);
	i = 0;
	while (!strict && ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((result > border || (result == border && (str[i] - '0') > 7))
				&& sign == 1)
			|| ((result > border || (result == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (false);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}


int	ft_isnum(char *str, int base)
{
	size_t	i;
	size_t	digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_isprefix(&str[i], base))
		return (false);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	return ((!str[i] && digits) ? 1 : 0);
}

int		a_lot(t_data *d, int ac)
{
	if (ac <= 200)
		d->op_n = d->op_n + medium(d, &d->stack_a, &d->stack_b);
	else if (ac <= 800)
		d->op_n = d->op_n + large(d, &d->stack_a, &d->stack_b);
	return (d->op_n);
}

static void	parse_arr(t_stack *stack,
				int argc,
				char **argv, t_data *d)
{
	int i;

	i = 1;
	if (!ft_isint(argv[i], 0))
		return ;
	fill_stack(d, argc, argv);
}

t_stack	 *parse_str(t_stack *stack,
				char *str, t_data *d)
{
	char	**numbers;
	size_t	i;
	t_stack	*st1;

	numbers = ft_strsplit(str, ' ');
	i = 0;
	d->len = len_tab(numbers);
	if (!ft_isint(numbers[i], 0))
		return (0);
	if (!(st1 = (t_stack*)malloc(sizeof(t_stack))))
		exit(err_memory());
	stack = st1;
	i = 0;
	while (i < d->len)
	{
		st1->n = ft_atoi(numbers[i]);
		st1->next = NULL;
		if (str[i + 1] != '\0')
		{
			if (!(st1->next = (t_stack*)malloc(sizeof(t_stack))))
				exit(err_memory());
			st1 = st1->next;
		}
		i++;
	}
	return (stack);
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

int     is_sorted_2(t_stack *s, t_stack *s1)
{
    //t_stack     *tmp;

    //tmp = s;
	//ft_putendl("in is sorted");
	if (!s)
		return (0);
	if (s1)
		return (0);
    while (s != NULL)
    {
		//ft_putendl("in is sorted while");
        if (s->next != NULL)
		{
			if (s->n > s->next->n)
				return (0);
		}
		s = s->next;
    }
	//ft_putendl("in is sorted after while");
    return (1);
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
    /*while (i < ac)
	{
		check_digits_overflow(av[i]);
		i++;
	}*/
	//fill_stack(&data, ac, av);
	data.len = 0;
	parse_stack(ac, av, &data);
	//printf("stack_a in main: %d %d %d\n", data.stack_a->n, data.stack_a->next->n, data.stack_a->next->next->n);
    n = is_sorted(data.stack_a);
	//sdata.op_n = 0;
    if (data.stack_a == NULL || n == 1)
        return (0);
	//printf("data.len in main %d\n", data.len);
    if ((data.len > 2 && data.len < 6))
        data.op_n = data.op_n + sort_35(&data, ac);
    if (ac >= 7 && ac <= 800)
		data.op_n = data.op_n + a_lot(&data, ac);
	if (!(is_sorted_2(data.stack_a, data.stack_b))) // not sorted
		data.op_n = final_sort(&data.stack_a, &data.stack_b);
	//if (ac > 800)
	//	data.op_n = data.op_n + too_much(&data, i);
	printf("operations number: %d\n", data.op_n);
	//free_stacks(&data);
	return (0);
}