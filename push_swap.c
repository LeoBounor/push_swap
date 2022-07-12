/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:44:05 by lbounor           #+#    #+#             */
/*   Updated: 2022/07/12 16:41:58 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*stack_index;
	int		i;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		stack_index = *stack;
		while (stack_index)
		{
			if (tmp->number > stack_index->number)
				i++;
			stack_index = stack_index->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}

static int	zero_counter(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if ((stack->index >> n & 1) == 1)
			i++;
		stack = stack->next;
	}
	return (i);
}

static void	ft_sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	n;
	int	size;

	n = 0;
	while (verif_stack_sort(*stack_a))
	{
		i = 0;
		size = zero_counter(*stack_a, n);
		while (i < size)
		{
			if (((*stack_a)->index >> n & 1) == 0)
				pb(stack_b, stack_a);
			else
			{
				ra(stack_a);
				i++;
			}
		}
		while (ft_lstsize(*stack_b))
			pa(stack_a, stack_b);
		n++;
	}
}

static void	ft_sort_short(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
	{
		if (verif_stack_sort(*stack_a) == 1)
			sa(stack_a);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, &stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, &stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_args(ac, av);
	if (ac == 2)
		stack_a = make_list(av[1]);
	else if (ac > 2)
		stack_a = make_arg_list(av + 1);
	else
		return (0);
	if (!stack_a)
	{
		ft_putendl_fd("Can't make list!", 1);
		return (0);
	}
	stack_b = NULL;
	set_index(&stack_a);
	if (ft_lstsize(stack_a) < 6)
		ft_sort_short(&stack_a);
	else
		ft_sort_radix(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
