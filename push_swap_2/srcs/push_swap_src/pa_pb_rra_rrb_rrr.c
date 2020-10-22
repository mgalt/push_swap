/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:55:04 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/22 17:21:57 by mgalt            ###   ########.fr       */
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


    ft_putendl("start of rev rot ab");
    tmp = (*s);
    end = (*s);
    start = (*s);
    if (!(*s))
        exit (-1);
     ft_putendl("after if !*s");
    while (start->next)
    {
         ft_putendl("in while in rev rot ab");
        start = start->next;
        if (start->next)
        {
             ft_putendl("in if start->next in rev rot ab");
            end = end->next;
        }
    }
     ft_putendl("after while in rev rot ab");
    if (!start->next)
    {
        start->next = tmp;
        end->next = NULL;
    }
    (*s) = start;
    ft_putendl("end of rev rot ab");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rot_ab(a);
	rev_rot_ab(b);
}