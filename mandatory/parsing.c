/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:29:42 by bel-abde          #+#    #+#             */
/*   Updated: 2025/01/26 14:48:13 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (check_)
	}
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