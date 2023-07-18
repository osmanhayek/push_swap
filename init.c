/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:39:51 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/18 19:31:01 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tab_init(int ac, char **av, int *tab)
{
	char	**numbers;
	int		i;
	int		j;
	int		c;

	i = 1;
	c = 0;
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		j = 0;
		while (numbers[j])
			tab[c++] = ft_atoi(numbers[j++]);
		free_split(numbers);
		i++;
	}
}

void	ft_stack_init(t_stack *s, int ac, char **av)
{
	int		i;
	int		j;
	char	**numbers;

	s->a_size = 0;
	s->b_size = 0;
	s->head_a = NULL;
	s->head_b = NULL;
	i = 1;
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		j = 0;
		while (numbers[j])
			ft_push_back(s, numbers[j++]);
		free_split(numbers);
		i++;
	}
}
