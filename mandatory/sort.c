/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:14:42 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 00:12:26 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_my_range(int size)
{
	if (size <= 30)
		return (1);
	else if (size <= 250)
		return (size * 0.15);
	else
		return (size * 0.08);
}

int	get_max_pos(t_list *stack)

{
	int	max_value;
	int	i;
	int	pos;

	max_value = stack->data;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->data > max_value)
		{
			pos = i;
			max_value = stack->data;
		}
		i++;
		stack = stack->next;
	}
	return (pos);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	while (*stack_a)
	{
		if (((*stack_a)->i <= max) && ((*stack_a)->i >= min))
		{
			pb(stack_a, stack_b, 1);
			min++;
			max++;
		}
		else if (((*stack_a)->i) > max)
		{
			ra(stack_a, 1);
		}
		else if (((*stack_a)->i) < min)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			min++;
			max++;
		}
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;
	int	size;

	while (*stack_b)
	{
		max_pos = get_max_pos(*stack_b);
		size = size_lst(*stack_b);
		if (max_pos == 0)
			pa(stack_a, stack_b, 1);
		else if (max_pos > size / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;

	min = 0;
	max = get_my_range(size_lst(*stack_a));
	assign_index(stack_a);
	push_to_b(stack_a, stack_b, min, max);
	push_to_a(stack_a, stack_b);
}
