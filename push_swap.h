/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:08:27 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/12 18:15:30 by mgalt            ###   ########.fr       */
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
int    				sort(t_data *d);
int     			is_sorted(t_stack *s);
int					find_min_max(t_data *d);

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
