/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:19:26 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/19 02:00:08 by fdeville         ###   ########.fr       */
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

int ft_strcmp(char *s1, char *s2)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
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
			if (!ft_isdigit(args[i][j]) && !(j == 0 && args[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (!ft_strcmp(args[i], args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void push_swap(t_stack *a, t_stack *b)
{
	t_node *curr;
	int i;
	int j;
	int k;
	int idx;

	k = 0;
	while (k < a->size)
	{
		curr = a->top;
		i = *((int *)curr->content);
		j = 0;
		idx = j;
		while (curr)
		{
			if ((*(int *)curr->content) > i)
			{
				i = *((int *)curr->content);
				idx = j;
			}
			curr = curr->next;
			j++;
		}

		while (idx)
		{
			op(a, b, RA);
			idx--;
		}
		op(a, b, PB);
		k++;
	}
	k = 0;
	while (k < a->size)
	{
		op(a, b, RRB);
		op(a, b, PA);
		k++;
	}
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
	// print_stacks(&a, &b);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
