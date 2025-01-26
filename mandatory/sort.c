/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:14:42 by bel-abde          #+#    #+#             */
/*   Updated: 2025/01/26 23:54:46 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_my_range(int size)
{
	if (size <= 30)
		return (1);
	else if (size <= 250)
		return (size * 20 / 100);
	else
		return (size * 15 / 100);
}

int	get_max_index(t_list *stack)
{
	int	max;
	int	i;
	int	index;

	index = 0;
	i = 0;
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
		{
			index = i;
			max = stack->data;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	while (*stack_a)
	{
		if (((*stack_a)->index <= max) && ((*stack_a)->index >= min))
		{
			pb(stack_a, stack_b);
			min++;
			max++;
		}
		else if (((*stack_a)->index) > max)
			ra(stack_a);
		else if (((*stack_a)->index) < min)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			min++;
			max++;
		}
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	size;

	while (*stack_b)
	{
		max_index = get_max_index(*stack_b);
		size = size_lst(*stack_b);
		if (max_index == 0)
			pa(stack_a, stack_b);
		else if (max_index > size / 2)
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	main_algo(t_list **stack_a, t_list stack_a)
{
	int		min_range;
	int		max_range;

	min_range = 0;
	max_range = get_my_range(size_lst(stack_a));
	assign_index(stack_a);
	push_to_b(stack_a, stack_b, min_range, max_range);
	push_to_a(stack_a, stack_b);
}

// 