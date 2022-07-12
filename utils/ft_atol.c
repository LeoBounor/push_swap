/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:25:25 by lbounor           #+#    #+#             */
/*   Updated: 2022/07/12 16:43:20 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == ' ');
}

long long	ft_atol(const char *str)
{
	long long	signe;
	long long	nombre;

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
