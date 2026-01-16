/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:19:26 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 10:51:15 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_puterr(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar('\n');
}

void ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar('\n');
}

int validate_inp(int ac, char *args[])
{
	int i;
	int j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int ac, char *av[])
{
	t_stack a;
	t_stack b;
	int ssize;

	if (ac < 2)
		return (0);
	av++;
	ssize = ac - 1;
	if (!validate_inp(ssize, av))
	{
		ft_puterr("Error");
		return (1);
	}
	a = (t_stack){0};
	b = (t_stack){0};
	init_stack(&a);
	init_stack(&b);
	a.size = ssize;
	b.size = ssize;
	fill_stack(&a, av);
	print_stacks(&a, &b);
	op(&a, &b, SA);
	op(&a, &b, PB);
	op(&a, &b, PB);
	op(&a, &b, PB);
	op(&a, &b, RR);
	op(&a, &b, RRR);
	op(&a, &b, SA);
	op(&a, &b, PA);
	op(&a, &b, PA);
	op(&a, &b, PA);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
