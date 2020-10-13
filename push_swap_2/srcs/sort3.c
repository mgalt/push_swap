/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:40:29 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 20:55:13 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     sort3_sa_rra(t_data *d, t_stack *stack_a)
{
    //int     n;

    //n = 2;
    d->op_n = d->op_n + 2;
    swap_a_b(stack_a);
    rev_rot_ab(stack_a);
    write(1, "sa\n", 3);
    write(1, "rra\n", 4);
    return (d->op_n);
}

int     sort3_sa_ra(t_data *d, t_stack *stack_a)
{
    //int     n;

    //n = 2;
    d->op_n = d->op_n + 2;
    swap_a_b(stack_a);
    rotate_a_b(&stack_a);
    write(1, "sa\n", 3);
    write(1, "ra\n", 3);
    return (d->op_n);
}

int     sort3_rra(t_data *d, t_stack *stack_a)
{
    //int     n;

    //n = 1;
    d->op_n++;
    rev_rot_ab(stack_a);
    write(1, "rra\n", 4);
    ft_putendl("before return in sort3 rra");
    return (d->op_n);
}

int     sort3_ra(t_data *d, t_stack **stack_a)
{
    //int     n;

    //n = 1;
    d->op_n++;
    rotate_a_b(stack_a);
    write(1, "ra\n", 3);
    return (d->op_n);
}

int     sort3_sa(t_data *d, t_stack *stack_a)
{
    //int     n;

    //n = 1;
    d->op_n++;
    swap_a_b(stack_a);
    write(1, "sa\n", 3);
    return (d->op_n);
}
