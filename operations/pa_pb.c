/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:09:03 by bel-abde          #+#    #+#             */
/*   Updated: 2025/02/07 14:39:51 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	pa(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (flag == 1)
		write(1, "pb\n", 3);
}
