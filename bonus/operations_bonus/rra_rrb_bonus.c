/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:54:14 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 22:09:58 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rra(t_list **stack_a, int flag)
{
	t_list	*i;
	t_list	*temp;

	if (!stack_a || !*stack_a || size_lst(*stack_a) < 2)
		return ;
	i = last_lst(*stack_a);
	temp = *stack_a;
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	i->next = *stack_a;
	*stack_a = i;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int flag)
{
	t_list	*i;
	t_list	*temp;

	if (!stack_b || !*stack_b || size_lst(*stack_b) < 2)
		return ;
	i = last_lst(*stack_b);
	temp = *stack_b;
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	i->next = *stack_b;
	*stack_b = i;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **s_a, t_list **s_b, int flag)
{
	if (s_a && s_b)
	{
		rra(s_a, flag);
		rrb(s_b, flag);
	}
}
