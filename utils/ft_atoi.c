/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:25:25 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/24 11:25:37 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == ' ');
}

int	ft_atoi(const char *str)
{
	char	signe;
	int		nombre;

	signe = 1;
	nombre = 0;
	while (ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nombre = (nombre * 10) + (*str - '0');
		str++;
	}
	return (nombre * signe);
}
