/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:16:18 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/19 22:58:17 by ohayek           ###   ########.fr       */
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
	t_list	*last;
	t_list	*new;

	if (!sa->b_size)
		return ;
	if (!sa->a_size)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = sa->head_b->data;
		new->next = new;
		new->pre = new;
		sa->head_a = new;
		sa->head_a++;
		delete_head_b(sa);
		return ;
	}
	new = (t_list *)malloc(sizeof(t_list));
	new->data = sa->head_b->data;
	last = sa->head_a->pre;
	new->next = sa->head_a;
	new->pre = last;
	last->next = new;
	sa->head_a->pre = new;
	sa->head_a = new;
	sa->a_size++;
	delete_head_b(sa);
}

void	pb(t_stack *sa)
{
	t_list	*last;
	t_list	*new;

	if (!sa->a_size)
		return ;
	if (!sa->b_size)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = sa->head_a->data;
		new->next = new;
		new->pre = new;
		sa->head_b = new;
		sa->b_size++;
		delete_head_a(sa);
		return ;
	}
	new = (t_list *)malloc(sizeof(t_list));
	new->data = sa->head_a->data;
	last = sa->head_b->pre;
	new->next = sa->head_b;
	new->pre = last;
	last->next = new;
	sa->head_b->pre = new;
	sa->head_b = new;
	sa->b_size++;
	delete_head_a(sa);
}
