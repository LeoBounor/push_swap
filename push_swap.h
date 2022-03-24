/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:44:02 by lbounor           #+#    #+#             */
/*   Updated: 2022/03/24 12:00:11 by lbounor          ###   ########lyon.fr   */
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

void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *str);
t_stack	*ft_lstnew(int content);
void	ft_lstclear(t_stack **lst);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);

#endif