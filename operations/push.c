/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:07:57 by lbounor           #+#    #+#             */
/*   Updated: 2022/04/18 16:56:01 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lstadd_front(stack_a, (*stack_b));
	(*stack_b) = tmp;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lstadd_front(stack_b, (*stack_a));
	(*stack_a) = tmp;
	ft_putendl_fd("pb", 1);
}
