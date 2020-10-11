/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:16:53 by mgalt             #+#    #+#             */
/*   Updated: 2019/09/22 19:18:38 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s1;

	s1 = NULL;
	i = 0;
	if (s && f)
	{
		if ((ft_strlen(s) + 1) < ft_strlen(s))
			return (NULL);
		if (!(s1 = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			s1[i] = f(s[i]);
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
