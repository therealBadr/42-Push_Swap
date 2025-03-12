/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:13:19 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 19:22:12 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	edge_case(t_list *stack, int size)
{
	t_list	*tmp;
	int		count;
	int		dif;

	count = 0;
	tmp = stack;
	while (tmp->next != NULL)
	{
		dif = tmp->i - tmp->next->i;
		if (dif == 2 || dif == 3 || dif == 4)
			count++;
		tmp = tmp->next;
	}
	dif = tmp->i - stack->i;
	if (dif == 2 || dif == 3 || dif == 4)
		count++;
	if (((count * 100) / size) >= 60)
		return (1);
	return (0);
}

void	edge_condition(t_list **stack_a, int flag)
{
	if (flag)
		rra(stack_a, 1);
	else
		ra(stack_a, 1);
}
