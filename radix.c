/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:19:23 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/20 13:41:57 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_bits(int num)
{
	int	counter;

	counter = 0;
	while (num)
	{
		counter++;
		num = num / 2;
	}
	return (counter);
}

void	radix_sub_two(t_stack *s, int bit, int b_size, int max_bit)
{
	while (b_size-- && (bit <= max_bit))
	{
		if (((s->head_b->data >> bit) & 1) == 1)
			pa(s);
		else
			rb(s);
	}
}

void	radix_sub_one(t_stack *s, int bit)
{
	if (!ft_is_sorted(s))
	{
		if (((s->head_a->data >> bit) & 1) == 0)
			pb(s);
		else
			ra(s);
	}
}

void	radix_sort(t_stack *s)
{
	int	i;
	int	j;
	int	max_bit;
	int	size;
	int	b_size;

	i = 0;
	max_bit = find_max_bits(s->a_size);
	while (i <= max_bit)
	{
		j = 0;
		size = s->a_size;
		while (j < size)
		{
			radix_sub_one(s, i);
			j++;
		}
		b_size = s->b_size;
		i++;
		radix_sub_two(s, i, b_size, max_bit);
	}
	while (s->b_size)
		pa(s);
}
