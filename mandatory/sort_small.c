/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:54:55 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 21:33:15 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	multi_move(t_list **stack, char *move, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (ft_strncmp(move, "ra", 2) == 0)
		{
			ra(stack, 1);
		}
		else
		{
			rra(stack, 1);
		}
		i++;
	}
}

int	get_min(t_list *stack)
{
	int	index;
	int	i;
	int	min;

	index = 0;
	i = 0;
	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
		{
			index = i;
			min = stack->data;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_list **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->data;
	mid = (*stack)->next->data;
	bot = (*stack)->next->next->data;
	if (top < mid && mid > bot && top < bot)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(stack, 1);
	else if (top > mid && mid < bot && top > bot)
		ra(stack, 1);
	else if (top < mid && mid > bot && top > bot)
		rra(stack, 1);
	else if (top > mid && mid < bot && top > bot)
		ra(stack, 1);
	else
	{
		sa(stack, 1);
		rra(stack, 1);
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = get_min(*stack_a);
	if (min_index == 1)
		sa(stack_a, 1);
	else if (min_index == 2)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (min_index == 3)
		rra(stack_a, 1);
	if (!is_sorted(*stack_a))
	{
		pb(stack_a, stack_b, 1);
		sort_three(stack_a);
		pa(stack_a, stack_b, 1);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = get_min(*stack_a);
	if (min_index == 1)
		sa(stack_a, 1);
	else if (min_index == 2)
		multi_move(stack_a, "ra", 2);
	else if (min_index == 3)
		multi_move(stack_a, "rra", 2);
	else if (min_index == 4)
		multi_move(stack_a, "rra", 1);
	if (!is_sorted(*stack_a))
	{
		pb(stack_a, stack_b, 1);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}
