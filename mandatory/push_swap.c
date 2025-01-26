/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:12:44 by bel-abde          #+#    #+#             */
/*   Updated: 2025/01/26 20:01:15 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	// main_algo(&stack_a, &stack_b, size_lst(stack_a));
	printf("Success\n"); 
	// clear_all(&stack_a);
	return (0);
}
