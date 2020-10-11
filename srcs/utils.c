/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:40:46 by mgalt             #+#    #+#             */
/*   Updated: 2020/10/11 19:48:58 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_atoi(const char *str)
{
	static unsigned long		i;
	unsigned long long			num;
	static int					mod;

	i = 0;
	num = 0;
	if (!str)
		return (0);
	while (*(str + i) == '\n' || *(str + i) == '\t'  \
	|| *(str + i) == '\r' || *(str + i) == '\v' \
	|| *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	mod = (*(str + i) == '-') ? -1 : 1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		num = (unsigned long long)(num * 10 + (*(str + i++) - '0'));
		if (num > (long long)MAX_LONG_LONG && mod == 1)
			return (-1);
		if (num > (long long)MAX_LONG_LONG && mod == -1)
			return (0);
	}
	return ((int)(num * mod));
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}

int		len_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	check_tab_len(char **tab)
{
	if (len_tab(tab) != 2)
	{
		free_tab(tab);
		//error_output(INVALID);
		exit(-1);
	}
}

double	ft_strtodbl(char *s)
{
	char		**tab;
	double		x;
	double		y;
	int			i;
	int			len;
	int			dot;

	x = 0.0;
	i = -1;
	y = 0;
	dot = 0;
	while (s[++i] != '\0')
		if (s[i] == '.')
			dot++;
	if (!dot)
		return ((double)ft_atoi(s));
	tab = ft_strsplit(s, '.');
	check_tab_len(tab);
	x = (double)ft_atoi(tab[0]);
	y = (double)ft_atoi(tab[1]);
	len = ft_strlen(tab[1]);
	while (--len > -1)
		y /= 10;
	if (s[0] == '-')
        x -= y;
    else
	    x += y;
	free_tab(tab);
	return (x);
}
