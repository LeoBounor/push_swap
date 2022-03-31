/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:43:31 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/31 16:34:36 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d", stack->index);
		printf("%s", " : ");
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
			i++;
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

void	*tri_bulle(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < (size - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	set_index(t_stack *stack)
{
	t_stack	*tmp;
	int		*stack_index;
	int		size;
	int		i;

	tmp = stack;
	size = ft_lstsize(stack);
	stack_index = malloc(size * (sizeof * stack_index));
	i = -1;
	while (tmp)
	{
		stack_index[++i] = tmp->number;
		tmp = tmp->next;
	}
	stack_index = tri_bulle(stack_index, size);
	tmp = stack;
	while (tmp)
	{
		i = -1;
		while (stack_index[++i])
		{
			if (stack_index[i] == tmp->number)
			{
				tmp->index = i;
			}
		}
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 2)
	{
		stack = make_list(av[1]);
		if (error_list(stack))
			return (0);
		set_index(stack);
		test_stack(stack);
	}
	else if (ac > 2)
	{
		stack = make_arg_list(av + 1);
		if (error_list(stack))
			return (0);
		set_index(stack);
		test_stack(stack);
	}
	ft_lstclear(&stack);
	return (0);
}
