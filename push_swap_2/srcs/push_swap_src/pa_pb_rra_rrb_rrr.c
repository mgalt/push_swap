/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:55:04 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 18:25:42 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack     *tmp;

    if (!(*stack_b))
        return ;
    tmp = (*stack_b)->next;
    (*stack_b)->next = *stack_a;
    *stack_a = *stack_b;
    *stack_b = tmp;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack     *tmp;

    if (!(*stack_a))
        exit (-1);
    tmp = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = tmp;
}

void	rev_rot_ab(t_stack **s)
{
    t_stack     *start;
    t_stack     *end;
    t_stack     *tmp;


    //ft_putendl("start of rev rot ab");
    tmp = (*s);
    end = (*s);
    start = (*s);
    if (!(*s))
        exit (-1);
    while (start->next)
    {
        start = start->next;
        if (start->next)
            end = end->next;
    }
    if (!start->next)
    {
        start->next = tmp;
        end->next = NULL;
    }
    (*s) = start;
    //ft_putendl("end of rev rot ab");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rot_ab(a);
	rev_rot_ab(b);
}