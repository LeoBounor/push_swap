/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:41:48 by Leo               #+#    #+#             */
/*   Updated: 2022/05/09 16:15:57 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_get_dist(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == n)
			return (i);
		stack = stack->next;
	}
	return (i);
}

void	sort_three(t_stack **stack_a)
{
	if (verif_stack_sort(*stack_a))
	{
		while (ft_lstlast(*stack_a)->index != 2)
			ra(stack_a);
		if (verif_stack_sort(*stack_a))
			sa(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	dist;

	if (verif_stack_sort(*stack_a))
	{
		dist = ft_get_dist(*stack_a, 3);
		if (dist <= 1)
			while ((*stack_a)->index != 3)
				ra(stack_a);
		else
			while ((*stack_a)->index != 3)
				rra(stack_a);
		pb(stack_b, stack_a);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (verif_stack_sort(*stack_a))
	{
		while (ft_lstsize(*stack_a) > 2)
		{
			if ((*stack_a)->index < 3)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
		}
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		while ((*stack_b)->index != 2)
			rb(stack_b);
		pa(stack_a, stack_b);
		if ((*stack_b)->index < (*stack_b)->next->index)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
