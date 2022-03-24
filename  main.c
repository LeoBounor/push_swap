/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:43:31 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/24 15:35:11 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
}

int	test_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (str[i] == '-' && ft_isdigit(str[i + 1]))
				i++;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	verif_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		test_line(list[i]);
		i++;
	}
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

int	error_list(t_stack *stack)
{
	if (!stack)
	{
		ft_putendl_fd("Can't make list!", 1);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 2)
	{
		stack_a = make_list(av[1]);
		if (error_list(stack_a))
			return (0);
		test_stack(stack_a);
	}
	else if (ac > 2)
	{
		stack_a = make_arg_list(av + 1);
		if (error_list(stack_a))
			return (0);
		test_stack(stack_a);
	}
	ft_lstclear(&stack_a);
	return (0);
}
