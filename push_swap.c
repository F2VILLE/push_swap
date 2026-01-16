/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:19:26 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 09:01:56 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

void fill_stack(t_stack *s, char *av[])
{
	int i;
	int *val;

	i = 0;
	s->count = 0;
	s->top = NULL;
	while (i < s->size)
	{
		val = malloc(sizeof(int));
		if (!val)
			return;
		*val = atoi(av[i]);
		ft_lstadd_back(&s->top, ft_lstnew(val));
		i++;
		s->count++;
	}
}

void print_stack(t_stack *stack)
{
	t_list *curr;

	ft_putstr("==== STACK ====");
	curr = stack->top;
	while (curr)
	{
		ft_putnbr(*(int *)curr->content);
		ft_putchar('\n');
		curr = curr->next;
	}
	ft_putstr("=== ENDSTACK ===");
}

void init_stack(t_stack *s)
{
	s->size = 0;
	s->count = 0;
	s->top = NULL;
}

void free_stack(t_stack *s)
{
	t_list *curr;
	t_list *next;

	if (!s)
		return;
	curr = s->top;
	while (curr)
	{
		next = curr->next;

		if (curr->content)
			free(curr->content);
		if (curr)
			free(curr);
		curr = next;
	}
}

void	swap(t_stack *s)
{
	t_list	*a;
	t_list	*b;

	if (!s || !s->top || !s->top->next)
		return ;
	a = s->top;
	b = a->next;
	a->next = b->next;
	b->next = a;
	s->top = b;
}

void	rotate_up(t_stack *s)
{
	t_list	*first;
	t_list	*last;

	first = s->top;
	last = ft_lstlast(first);
	s->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_down(t_stack *s)
{
	t_list	*curr;
	t_list	*before_last;

	if (!s || !s->top || !s->top->next)
		return ;
	curr = s->top;
	before_last = NULL;
	while (curr->next)
	{
		before_last = curr;
		curr = curr->next;
	}
	before_last->next = NULL;
	curr->next = s->top;
	s->top = curr;
}

void	push(t_stack *dst, t_stack *src)
{
	t_list	*tmp;

	tmp = src->top->next;
	src->top->next = dst->top;
	dst->top = src->top;
	src->top = tmp;
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
	print_stack(&a);
	printf("SA\n");
	swap(&a);
	print_stack(&a);
	printf("ra\n");
	rotate_up(&a);
	print_stack(&a);
	printf("rra\n");
	rotate_down(&a);
	print_stack(&a);
	printf("pb");
	push(&b, &a);
	print_stack(&a);
	print_stack(&b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
