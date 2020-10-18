/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:36:29 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/18 18:25:35 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		err_no_args(void)
{
	ft_putstr_fd("Error: no arguments!\n", 2);
	return (-1);
}

int     err_invalid_arg(void)
{
    ft_putstr_fd("Error: invalid argument\n", 2);
    return (-1);
}

int		err_overflow(void)
{
	ft_putstr_fd("Error: argument value is too large or too low!\n", 2);
	return (-1);
}

int		err_memory(void)
{
	ft_putstr_fd("Error: memory allocation failed\n", 2);
	return (-1);
}