/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:12:44 by bel-abde          #+#    #+#             */
/*   Updated: 2025/02/08 19:52:43 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sorting_cases(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = size_lst(*stack_a);
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (parsing(argv[i], &stack_a) == 0)
			(write(2, "Error\n", 6), clear_all(&stack_a), exit(1));
		i++;
	}
	if (!stack_a || check_duplicate(stack_a) == 0)
		(write(2, "Error\n", 6), clear_all(&stack_a), exit(1));
	if (is_sorted(stack_a) == 1)
		(clear_all(&stack_a), exit(1));
	sorting_cases(&stack_a, &stack_b);
	clear_all(&stack_a);
	return (0);
}
