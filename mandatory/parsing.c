/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:29:42 by bel-abde          #+#    #+#             */-
/*   Updated: 2025/01/26 19:55:51 by bel-abde         ###   ########.fr       */
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

// - We split our argc. That would give us each number in each index.
// - We check in each number (check_res) : if it has "-" || "+"
// 							  if it is a number between 0 && 9
// (Remember to free everything in case there was something wrong in
//   the conditions above.)
// 
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

// Here we check the existence of "+" && "-"
// Also if the chars are a number between 0 and 9

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

/*
int	if_sorted(t_list *head)
{
	t_list	*i;

	i = head;
	if (!head)
		return (0);
	while (i->next)
	{
		if (i->data > i->next->data)
			return (0);
		i = i->next;
	}
	return (1);
}

int	check_d(t_list *h)
{
	t_list	*i;
	t_list	*j;

	i = h;
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

int	check_res(char *str)
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

void	clean_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	parsing(char *str, t_list **head)
{
	int		i;
	char	**res;

	i = 0;
	res = ft_split(str, ' ');
	if (!res)
		return (0);
	while (res[i])
	{
		if (check_res(res[i]) == 0)
			return (clean_split(res), 0);
		if (res[i][0] == '-' || res[i][0] == '+')
		{
			if (res[i][1] == '\0')
				return (clean_split(res), clr_all(head), 0);
		}
		add_back(head, new_node(ft_atoi(res[i], head, res)));
		i++;
	}
	clean_split(res);
	return (1);
}


*/
