/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:33:40 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/18 20:35:16 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *s)
{
	if (!s->a_size || !s->b_size)
		return ;
	s->head_a = s->head_a->pre;
	s->head_b = s->head_b->pre;
	write(1, "rrr\n", 4);
}
