/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:54:10 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 19:52:45 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*lst_clone(t_list *lst)
{
	t_list	*new;

	new = NULL;
	while (lst)
	{
		add_back(&new, new_node(lst->data));
		lst = lst->next;
	}
	return (new);
}

void	del_max(t_list **clone, t_list *max)
{
	t_list	*current;

	if (!clone || !*clone || !max)
		return ;
	current = *clone;
	if (current->data == max->data)
	{
		*clone = current->next;
	}
	else
	{
		while (current->next)
		{
			if (current->next->data == max->data)
			{
				current->next = current->next->next;
				break ;
			}
			current = current->next;
		}
	}
	max->next = NULL;
	free(max);
}

void	find_max(t_list **original, t_list **clone, int *index)
{
	t_list	*current_clone;
	t_list	*current_original;
	t_list	*max;

	current_clone = *clone;
	current_original = *original;
	max = current_clone;
	while (current_clone)
	{
		if (max->data < current_clone->data)
			max = current_clone;
		current_clone = current_clone->next;
	}
	while (current_original)
	{
		if (max->data == current_original->data)
		{
			current_original->i = (*index);
			(*index)--;
			break ;
		}
		current_original = current_original->next;
	}
	del_max(clone, max);
}

void	assign_index(t_list **lst)
{
	t_list	*clone;
	t_list	*ptr;
	int		n;

	n = size_lst(*lst) - 1;
	clone = lst_clone(*lst);
	ptr = *lst;
	while (ptr)
	{
		find_max(lst, &clone, &n);
		ptr = ptr->next;
	}
}
