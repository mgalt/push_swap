/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:32:45 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/12 18:22:45 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_min_max(t_data *d)
{
	int		n;
	int		min_num;
	t_stack	*tmp;

	n = 1;
	min_num = 1;
	d->min = INT_MAX;
    d->max = INT_MIN;
    d->min_num = 1;
	tmp = d->stack_a;
	printf("tmp: %d %d %d %d\n", tmp->n, tmp->next->n, tmp->next->next->n, tmp->next->next->next->n);
	while (tmp != NULL)
	{
		/*if (d->min > tmp->n)
		{
			min_num = n;
			d->min = tmp->n;
		}
		else
		{
			d->min = 0;
			min_num = 0;
		}
		if (d->max < tmp->n)
			d->max = tmp->n;
		else
			d->max = 0;
		tmp = tmp->next;
		n++;*/
		d->min > tmp->n ? min_num = n : 0;
		d->min > tmp->n ? d->min = tmp->n : 0;
		d->max < tmp->n ? d->max = n : 0;
		tmp = tmp->next;
		n++;
	}
	d->min_num = min_num;
	/*if (min_num > n / 2)
		d->min_num = ft_abs(n - min_num + 1);
	else
		d->min_num = 0;*/
	min_num > (n / 2) ? d->min_num = ft_abs((n - min_num + 1)) : 0;
	n /= 2;
	//if (min_num > n)
	//	return (1);
	//return (0);
	return (min_num > n ? 1 : 0);
}

int    sort(t_data *d)
{
    int     n = 0;

	ft_putendl("in sort");
    if (d->stack_a->next == NULL)
        return (0);
    n = is_sorted(d->stack_a);
	//printf("n = %d\n", n);
	if (n == 1)
		ft_putendl("Sorted");
	else
		ft_putendl("Not sorted");
    //while (!(is_sorted(d->stack_a)) || d->stack_b == NULL) // if stack isn't sorted
    //{
		n = find_min_max(d); // неправильно работает
		printf("min_num: %d\nmin: %d\nmax: %d\nn = %d\n", d->min_num, d->min, d->max, n);
    //}
	return (0);
}

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