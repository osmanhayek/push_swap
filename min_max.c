/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:30 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/20 13:43:34 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_list	*s)
{
	int		min_index;
	int		min_value;
	int		i;
	t_list	*temp;

	min_index = -1;
	min_value = 2147483647;
	temp = s;
	i = 0;
	while (1)
	{
		if (min_value > temp->data)
		{
			min_value = temp->data;
			min_index = i;
		}
		temp = temp->next;
		i++;
		if (temp == s)
			break ;
	}
	return (min_index);
}
