/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:44:02 by lbounor           #+#    #+#             */
/*   Updated: 2022/04/18 20:05:53 by Leo              ###   ########lyon.fr   */
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

//	-------- FONCTION OPERATIONS --------
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

//	-------- FONCTION SORT --------
int		test_line(char *str);
int		verif_list(char **list);
t_stack	*make_list(char *list);
t_stack	*make_arg_list(char **list);
int		verif_stack_sort(t_stack *stack);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int		ft_check_doublons(char **params);

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
t_stack	*ft_lstlast(t_stack *lst);
int		ft_strcmp(const char *s1, const char *s2);

#endif