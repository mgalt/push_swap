/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:08:27 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/19 18:20:12 by mgalt            ###   ########.fr       */
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
	//t_stack			*last_a;
    //int             max;
    //int             min;
    //int             min_num;
    int				op_n;
    int             len;
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
int		            sort3(t_data *d, t_stack **stack_a);
int					sort3_sa(t_data *d, t_stack **stack_a);
int					sort3_ra(t_data *d, t_stack **stack_a);
int					sort3_rra(t_data *d, t_stack **stack_a);
int					sort3_sa_ra(t_data *d, t_stack **stack_a);
int					sort3_sa_rra(t_data *d, t_stack **stack_a);
void				swap_a_b(t_stack **s);
void				ss(t_stack **a, t_stack **b);
void				rotate_a_b(t_stack **s);
void				rr(t_stack **a, t_stack **b, int flag);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				rev_rot_ab(t_stack **s);
void				rrr(t_stack **a, t_stack **b);
int					sort5(t_data *d, t_stack **stack_a, t_stack **stack_b);
int					first_two(t_stack **a, t_stack **b);
int					a_position(t_stack **a, t_stack **b, int i);
int					find_len(t_stack *a);
int					rra_num(t_stack **a, int i);
int					ra_num(t_stack **a, int i);
int					ra_rra_num(t_stack **a, int a_min_i);
int					sort_stack_a(t_stack **a, t_stack **b);
int					find_position(t_stack *a, int min);
int					a_lot(t_data *d, int ac);
int					medium(t_data *d, t_stack **a, t_stack **b);
int					sort_b(t_stack **a, t_stack **b);
int					pre_pb(t_stack **a, t_stack **b);
int		            rb_rrb_num(t_stack **a, int a_min_i);
int					rb_num(t_stack **a, int i);
int					rrb_num(t_stack **a, int i);
int					find_position_100(t_stack *b, int n, int pos);
int					large(t_data *d, t_stack **a, t_stack **b);
int					medium_pos(t_stack *a, int max);
int					r_rr_100(t_stack **a, t_stack **b, int len);
int					range(t_stack *a, int max);
int		            final_sort(t_stack **a, t_stack **b);

/*
** utils----------------------------------
*/
double				ft_strtodbl(char *s);
void				check_tab_len(char **tab);
int					len_tab(char **tab);
void				free_tab(char **tab);
int					ft_atoi(const char *str);
int					ft_abs(int n);
int					find_max(t_stack *a);
int					find_min(t_stack *a);
int					find_a_min_i(t_stack *a, int a_min);

void	            free_stacks(t_data *d);

/*
** checker--------------------------------
*/
int					read_instructions(t_stack **a, t_stack **b);
void				do_op(char *s, t_stack **a, t_stack **b);
void				err_no_op(void);
int					is_space(char c);

#endif
