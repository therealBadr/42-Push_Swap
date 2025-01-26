/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:57:29 by bel-abde          #+#    #+#             */
/*   Updated: 2025/01/25 13:57:58 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				i;
	int				data;
	struct s_list	*next;
}	t_list;

// Operations
void	ra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, int flag);
void	rrr(t_list **s_a, t_list **s_b, int flag);
void	rra(t_list **stack_a, int flag);
void	rrb(t_list **stack_b, int flag);
void	rrr(t_list **s_a, t_list **s_b, int flag);
void	sa(t_list **stack_a, int flag);
void	sb(t_list **stack_b, int flag);
void	ss(t_list **s_a, t_list **s_b, int flag);
void	add_front(t_list **lst, t_list *new);
void	pa(t_list **s_a, t_list **s_b, int flag);
void	pb(t_list **s_a, t_list **s_b, int flag);

#endif