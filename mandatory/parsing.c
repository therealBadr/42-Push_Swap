/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:29:42 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/08 22:33:15 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*i;

	i = stack_a;
	if (!stack_a)
		return (0);
	while (i->next)
	{
		if (i->data > i->next->data)
			return (0);
		i = i->next;
	}
	return (1);
}

void	clear_result(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	check_duplicate(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;

	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	parsing(char *str, t_list **stack_a)
{
	int		i;
	char	**result;

	i = 0;
	result = ft_split(str, ' ');
	if (!result)
		return (0);
	while (result[i])
	{
		if (check_num(result[i]) == 0)
			return (clear_result(result), 0);
		if (result[i][0] == '-' || result[i][0] == '+')
		{
			if (result[i][1] == '\0')
				return (clear_result(result), 0);
		}
		add_back(stack_a, new_node(ft_atoi(result[i], stack_a, result)));
		i++;
	}
	clear_result(result);
	return (1);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
