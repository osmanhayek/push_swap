/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:06:56 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/19 23:19:26 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deallocate(t_stack *s)
{
	t_list	*temp;
	t_list	*next_node;

	temp = s->head_a;
	while (1)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
		if (temp == s->head_a)
			break ;
	}
	s->a_size = 0;
	s->head_a = NULL;
	free(s->sorted);
}

int	main(int ac, char **av)
{
	t_stack		sa;

	if (ac == 1)
		exit(0);
	if (!ft_check_error(ac, av))
		ft_putstr_fd("Error\n", 2);
	ft_stack_init(&sa, ac, av);
	if (sa.a_size == 3)
		tiny_sort(&sa);
	else if (sa.a_size == 4)
		four_sort(&sa);
	else if (sa.a_size == 5)
		five_sort(&sa);
	else
		radix_sort(&sa);
	ft_deallocate(&sa);
	system("leaks a.out");
}
