/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:44:02 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/31 14:33:36 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int					number;
	int					index;
	struct s_stack		*next;
}	t_stack;

//	-------- FONCTION PUSHSWAP --------
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);

//	-------- FONCTION DE LA LIBFT --------
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *str);
t_stack	*ft_lstnew(int content);
void	ft_lstclear(t_stack **lst);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_lstsize(t_stack *lst);

#endif