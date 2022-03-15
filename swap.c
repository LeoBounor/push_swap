/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:54:32 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/15 16:07:06 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return ;
	tmp = (stack_a);
	(stack_a) = (stack_a)->next;
	tmp->next = (stack_a)->next;
	(stack_a)->next = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	tmp = (stack_b);
	(stack_b) = (stack_b)->next;
	tmp->next = (stack_b)->next;
	(stack_b)->next = tmp;
	ft_putendl_fd("sb", 1);
}
