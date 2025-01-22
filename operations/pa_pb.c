/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:09:03 by bel-abde          #+#    #+#             */
/*   Updated: 2025/01/22 15:41:43 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	pa(t_list **s_a, t_list **s_b, int flag)
{
	t_list	*temp;

	if (!s_a || !*s_a || !s_b || !*s_b)
		return ;
	temp = *s_b;
	*s_b = (*s_b)->next;
	temp->next = *s_a;
	*s_a = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **s_a, t_list **s_b, int flag)
{
	t_list	*temp;

	if (!s_a || !*s_a || !s_b || !*s_b)
		return ;
	temp = *s_a;
	*s_a = (*s_a)->next;
	temp->next = *s_b;
	*s_b = temp;
	if (flag == 1)
		write(1, "pb\n", 3);
}
