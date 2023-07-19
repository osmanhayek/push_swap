/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:19:23 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/19 23:04:06 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *s)
{
	t_list	*max_node;

	max_node = find_higest(s->head_a);
	if (s->head_a == max_node)
		ra(s);
	else if (s->head_a->next == max_node)
		rra(s);
	if (s->head_a->data > s->head_a->next->data)
		sa(s);
}

void	four_sort(t_stack *s)
{
	int	index;

	index = find_min_index(s->head_a);
	while (index != 0)
	{
		if (index < s->a_size / 2)
			ra(s);
		else
			rra(s);
		index = find_min_index(s->head_a);
	}
	pb(s);
	tiny_sort(s);
	pa(s);
}

void	five_sort(t_stack *s)
{
	int	index;

	index = find_min_index(s->head_a);
	while (index != 0)
	{
		if (index <= s->a_size / 2)
			ra(s);
		else
			rra(s);
		index = find_min_index(s->head_a);
	}
	pb(s);
	four_sort(s);
	pa(s);
}

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
