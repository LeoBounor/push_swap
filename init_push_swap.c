/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:41:35 by Leo               #+#    #+#             */
/*   Updated: 2022/07/12 17:45:47 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

t_stack	*make_list(char *list)
{
	char	**list_split;
	t_stack	*stack;
	t_stack	*new;
	int		i;

	list_split = ft_split(list, ' ');
	if (!list_split)
		return (NULL);
	stack = NULL;
	i = -1;
	while (list_split[++i])
	{
		new = ft_lstnew(ft_atoi(list_split[i]));
		if (!new)
		{
			ft_lstclear(&stack);
			break ;
		}
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

	stack = NULL;
	i = -1;
	while (list[++i])
	{
		new = ft_lstnew(ft_atoi(list[i]));
		if (!new)
		{
			ft_lstclear(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, new);
	}
	return (stack);
}
