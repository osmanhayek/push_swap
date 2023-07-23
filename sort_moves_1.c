/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:16:18 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/20 13:43:45 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	int	temp;

	if (s->a_size <= 1)
		return ;
	temp = s->head_a->data;
	s->head_a->data = s->head_a->next->data;
	s->head_a->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *sa)
{
	int	temp;

	if (sa->b_size <= 1)
		return ;
	temp = sa->head_b->data;
	sa->head_b->data = sa->head_b->next->data;
	sa->head_b->next->data = temp;
	write(1, "sb\b", 3);
}

void	ss(t_stack *sa)
{
	int	temp;

	if (sa->b_size <= 1 || sa->a_size <= 1)
		return ;
	temp = sa->head_b->data;
	sa->head_b->data = sa->head_b->next->data;
	sa->head_b->next->data = temp;
	temp = sa->head_a->data;
	sa->head_a->data = sa->head_a->next->data;
	sa->head_a->next->data = temp;
	write(1, "ss\b", 3);
}

void	pa(t_stack *sa)
{
	t_list	*new;

	if (sa->b_size)
	{
		if (!sa->a_size)
		{
			sa->head_a = (t_list *)malloc(sizeof(t_list));
			sa->head_a->data = sa->head_b->data;
			sa->head_a->next = sa->head_a;
			sa->head_a->pre = sa->head_a;
		}
		else
		{
			new = (t_list *)malloc(sizeof(t_list));
			new->data = sa->head_b->data;
			new->next = sa->head_a;
			new->pre = sa->head_a->pre;
			sa->head_a->pre->next = new;
			sa->head_a->pre = new;
			sa->head_a = new;
		}
		sa->a_size++;
		delete_head_b(sa);
	}
}

void	pb(t_stack *sa)
{
	t_list	*new;

	if (sa->a_size)
	{
		if (!sa->b_size)
		{
			sa->head_b = (t_list *)malloc(sizeof(t_list));
			sa->head_b->data = sa->head_a->data;
			sa->head_b->next = sa->head_b;
			sa->head_b->pre = sa->head_b;
		}
		else
		{
			new = (t_list *)malloc(sizeof(t_list));
			new->data = sa->head_a->data;
			new->next = sa->head_b;
			new->pre = sa->head_b->pre;
			sa->head_b->pre->next = new;
			sa->head_b->pre = new;
			sa->head_b = new;
		}
		sa->b_size++;
		delete_head_a(sa);
	}
}
