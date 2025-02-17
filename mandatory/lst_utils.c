/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:56:15 by bel-abde          #+#    #+#             */
/*   Updated: 2025/02/08 20:17:30 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*new_node(int data)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->data = data;
	res->next = NULL;
	return (res);
}

void	add_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!lst || !new)
		return ;
	i = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (i->next)
		i = i->next;
	i->next = new;
}

int	size_lst(t_list *lst)
{
	int		count;
	t_list	*i;

	if (!lst)
		return (0);
	i = lst;
	count = 0;
	while (i)
	{
		i = i->next;
		count++;
	}
	return (count);
}

void	clear_all(t_list **lst)
{
	t_list	*i;
	t_list	*swap;

	if (!lst)
		return ;
	i = *lst;
	while (i)
	{
		swap = i;
		i = i->next;
		free(swap);
	}
	*lst = NULL;
}

t_list	*last_lst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
