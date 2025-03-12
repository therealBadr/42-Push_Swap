/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:05:18 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 22:10:07 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sa(t_list **stack_a, int flag)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || size_lst(*stack_a) < 2)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int flag)
{
	t_list	*temp;

	if (!stack_b || !*stack_b || size_lst(*stack_b) < 2)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **s_a, t_list **s_b, int flag)
{
	if (s_a && s_b)
	{
		sa(s_a, flag);
		sb(s_b, flag);
	}
}
