/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 05:07:30 by mgalt             #+#    #+#             */
/*   Updated: 2019/09/23 17:40:55 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s1, int len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s1[i] == '-')
	{
		s2[i] = '-';
		i++;
	}
	while (len > 0 && s1[len - 1] != '-')
	{
		s2[i] = s1[len - 1];
		len--;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
