/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:55:53 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 22:10:02 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ra(t_list **stack_a, int flag)
{
	t_list	*temp;
	t_list	*i;

	if (!stack_a || !*stack_a || size_lst(*stack_a) < 2)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	i = *stack_a;
	while (i->next)
		i = i->next;
	i->next = temp;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int flag)
{
	t_list	*temp;
	t_list	*i;

	if (!stack_b || !*stack_b || size_lst(*stack_b) < 2)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	i = *stack_b;
	while (i->next)
		i = i->next;
	i->next = temp;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **s_a, t_list **s_b, int flag)
{
	if (s_a && s_b)
	{
		ra(s_a, flag);
		rb(s_b, flag);
	}
}
