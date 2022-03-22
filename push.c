/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:07:57 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/22 15:36:18 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->next;
	ft_lstadd_front(stack_a, stack_b);
	stack_b = tmp;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->next;
	ft_lstadd_front(stack_b, stack_a);
	stack_a = tmp;
	ft_putendl_fd("pb", 1);
}
