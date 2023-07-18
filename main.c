/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:06:56 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/18 20:40:53 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		sa;

	if (ac == 1)
		exit(0);
	if (!ft_check_error(ac, av))
		ft_putstr_fd("Error\n", 2);
	ft_stack_init(&sa, ac, av);
	ft_deallocate(&sa);
}
