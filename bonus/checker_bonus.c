/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:08:27 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/11 17:08:46 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_moves(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(operation, "ss\n") == 0)
        	ss(stack_a, stack_b, 0);
	else if (ft_strcmp(operation, "pa\n") == 0)
        	pa(stack_a, stack_b, 0);
	else if (ft_strcmp(operation, "pb\n") == 0)
        	pb(stack_a, stack_b, 0);
	else if (ft_strcmp(operation, "ra\n") == 0)
        	ra(stack_a, 0);
	else if (ft_strcmp(operation, "rb\n") == 0)
        	rb(stack_b, 0);
	else if (ft_strcmp(operation, "rr\n") == 0)
        	rr(stack_a, stack_b, 0);
	else if (ft_strcmp(operation, "rra\n") == 0)
        	rra(stack_a, 0);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		(write(2, "Error\n", 6), exit(1));
}

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		make_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	ft_checker(&stack_a, &stack_b);
	clear_all(&stack_a);
	clear_all(&stack_b);
	return (0);
}
