/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:19 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/28 13:22:25 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	tmp = *stack_b;
	stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
	ft_putendl_fd("rb", 1);
}
