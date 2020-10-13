/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:10:29 by mgalt             #+#    #+#             */
/*   Updated: 2019/09/18 23:42:53 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len1;
	char	*haystack1;

	haystack1 = (char*)haystack;
	len1 = (size_t)ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return (haystack1);
	while (*haystack1 && len >= len1)
	{
		if (*haystack1 == *needle)
		{
			if (ft_strncmp(needle, haystack1, len1) == 0)
				return (haystack1);
		}
		haystack1++;
		len--;
		i++;
	}
	return (NULL);
}
