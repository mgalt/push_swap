/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_ra_rb_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:44:31 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 20:52:56 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a_b(t_stack *s)
{
	t_stack		*tmp;

	if (!s)
		exit(-1);
	tmp = s;
	s = s->next;
	tmp->next = s->next;
	s->next = tmp;
	//ft_putendl("end of swap a b");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_a_b(a);
	swap_a_b(b);
}

void	rotate_a_b(t_stack **s)
{
	t_stack		*tmp;

	tmp = (*s);
	if (!(*s))
		exit(-1);
	while ((*s)->next)
		(*s) = (*s)->next;
	(*s)->next = tmp;
	tmp = tmp->next;
	(*s) = (*s)->next;
	(*s)->next = NULL;
	(*s) = tmp;
	//ft_putendl("end of ra");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_a_b(a);
	rotate_a_b(b);
}