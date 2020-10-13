/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:35:20 by mgalt             #+#    #+#             */
/*   Updated: 2019/09/18 23:29:06 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*haystack1;
	int		len;

	len = ft_strlen(needle);
	haystack1 = (char*)haystack;
	if (len == 0)
		return (haystack1);
	while (*haystack1)
	{
		if (*haystack1 == *needle)
		{
			if (ft_strncmp(needle, haystack1, len) == 0)
				return (haystack1);
		}
		haystack1++;
	}
	return (NULL);
}
