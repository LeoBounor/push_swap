/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:44:02 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/22 15:51:36 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int			number;
	int			index;
	t_stack		*next;
}	t_stack;

void	ft_lstadd_front(t_stack *alst, t_stack *new);
void	ft_lstadd_back(t_stack *alst, t_stack *new);

#endif