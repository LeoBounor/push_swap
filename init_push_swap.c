/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:41:35 by Leo               #+#    #+#             */
/*   Updated: 2022/04/18 19:52:27 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_doublons(char **params)
{
	int	i;
	int	j;

	i = 0;
	while (params[i])
	{
		j = 0;
		while (params[j])
		{
			if ((ft_strcmp(params[i], params[j]) == 0 && i != j)
				|| ft_strcmp(params[j], "") == 0)
				return (1);
			if ((ft_strcmp(params[i], "-0") == 0
					&& ft_strcmp(params[j], "0") == 0)
				|| (ft_strcmp(params[i], "0") == 0
					&& ft_strcmp(params[j], "-0") == 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (list[i][0] == '-' && test_line(list[i] + 1))
			return (1);
		if (ft_isdigit(list[i][0]) && test_line(list[i] + 1))
			return (1);
		else if (list[i][0] != '-')
		{
			if (test_line(list[i]))
				return (1);
		}
		i++;
	}
	if (ft_check_doublons(list))
		return (1);
	return (0);
}

t_stack	*make_list(char *list)
{
	char	**list_split;
	t_stack	*stack;
	t_stack	*new;
	int		i;

	list_split = ft_split(list, ' ');
	if (!list_split || verif_list(list_split))
		return (NULL);
	stack = NULL;
	i = -1;
	while (list_split[++i])
	{
		new = ft_lstnew(ft_atoi(list_split[i]));
		if (!new)
			return (NULL);
		free(list_split[i]);
		ft_lstadd_back(&stack, new);
	}
	free(list_split);
	return (stack);
}

t_stack	*make_arg_list(char **list)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	if (verif_list(list))
		return (NULL);
	stack = NULL;
	i = -1;
	while (list[++i])
	{
		new = ft_lstnew(ft_atoi(list[i]));
		if (!new)
			return (NULL);
		ft_lstadd_back(&stack, new);
	}
	return (stack);
}

int	verif_stack_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (1);
		stack = stack->next;
	}
	return (0);
}
