/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:33:02 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/18 19:30:25 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_back(t_stack *sa, char *number)
{
	t_list	*new;
	t_list	*last;

	if (!sa->head_a)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->next = new;
		new->pre = new;
		new->data = ft_atoi(number);
		sa->head_a = new;
		sa->a_size++;
		return ;
	}
	new = (t_list *)malloc(sizeof(t_list));
	new->data = ft_atoi(number);
	last = sa->head_a->pre;
	last->next = new;
	new->pre = last;
	new->next = sa->head_a;
	sa->head_a->pre = new;
	sa->a_size++;
}

void	delete_head_a(t_stack *sa)
{
	t_list	*temp;

	temp = sa->head_a;
	if (sa->head_a->next == sa->head_a)
		sa->head_a = NULL;
	else
	{
		sa->head_a->pre->next = sa->head_a->next;
		sa->head_a->next->pre = sa->head_a->pre;
		sa->head_a = sa->head_a->next;
	}
	sa->a_size--;
	free(temp);
	write(1, "pb\n", 3);
}

void	delete_head_b(t_stack *sa)
{
	t_list	*temp;

	temp = sa->head_b;
	if (sa->head_b->next == sa->head_b)
		sa->head_b = NULL;
	else
	{
		sa->head_b->pre->next = sa->head_b->next;
		sa->head_b->next->pre = sa->head_b->pre;
		sa->head_b = sa->head_b->next;
	}
	sa->b_size--;
	free(temp);
	write(1, "pa\n", 3);
}

void	display(t_stack *sa)
{
	t_list	*last;

	last = sa->head_b;
	while (1)
	{
		printf("%d ", last->data);
		fflush(stdout);
		last = last->next;
		if (last == sa->head_b)
			break ;
	}
}
