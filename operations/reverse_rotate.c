/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:35:05 by lbounor           #+#    #+#             */
/*   Updated: 2022/04/18 16:49:30 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*stack_a);
	(*stack_a) = tmp->next;
	tmp->next = NULL;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*stack_b);
	(*stack_b) = tmp->next;
	tmp->next = NULL;
	ft_putendl_fd("rrb", 1);
}
