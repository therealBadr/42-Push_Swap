/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:57:11 by bel-abde          #+#    #+#             */
/*   Updated: 2025/02/07 14:28:42 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(char *str, t_list **stack_a, char **result)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		if ((res > 2147483648 && sign == -1) || (res > 2147483647 && sign == 1))
		{
			write(2, "Error\n", 6);
			(clear_all(stack_a), clear_result(result), exit(1));
		}
		i++;
	}
	return (res * sign);
}
