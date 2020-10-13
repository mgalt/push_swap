/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:08:27 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/13 18:03:22 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_LONG_LONG	9223372036854775807

typedef struct      s_stack
{
    int                n;
    struct s_stack  *next;
}                   t_stack;

typedef struct      s_data
{
    t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack			*last_a;
    int             max;
    int             min;
    int             min_num;
}					t_data;

/*
** errors---------------------------------
*/
int					err_no_args(void);
int     			err_invalid_arg(void);
int					err_overflow(void);
int					err_memory(void);

/*
** parsing--------------------------------
*/
void				check_digits_overflow(char *arg);

void    			fill_stack(t_data *d, int ac, char **av);

/*
** sorting--------------------------------
*/
//int    				sort(t_data *d);
int     			is_sorted(t_stack *s);
int					find_min_max(t_data *d);
int		            sort_35(t_data *data, int ac);
int		            sort3(t_stack *stack_a);
int					sort3_sa(t_stack *stack_a);
void				swap_a_b(t_stack *s);
void				ss(t_stack *a, t_stack *b);
void				rotate_a_b(t_stack *s);
void				rr(t_stack *a, t_stack *b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				rev_rot_ab(t_stack *s);
void				rrr(t_stack *a, t_stack *b);

/*
** utils----------------------------------
*/
double				ft_strtodbl(char *s);
void				check_tab_len(char **tab);
int					len_tab(char **tab);
void				free_tab(char **tab);
int					ft_atoi(const char *str);
int					ft_abs(int n);

#endif
