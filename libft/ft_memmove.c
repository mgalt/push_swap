/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:48:04 by mgalt             #+#    #+#             */
/*   Updated: 2019/09/22 18:54:48 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	i = (int)len - 1;
	if (dst > src)
	{
		while (i >= 0)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
