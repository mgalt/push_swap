/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:41:20 by mgalt             #+#    #+#             */
/*   Updated: 2019/09/22 17:43:59 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
