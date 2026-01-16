/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:44:13 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 10:09:29 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *s, char *av[])
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
			return ;
		*val = atoi(av[i]);
		ft_lstadd_back(&s->top, ft_lstnew(val));
		i++;
		s->count++;
	}
}

void	print_stack(t_stack *stack)
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

void	print_stacks(t_stack *a, t_stack *b)
{
	t_list *curr_a;
	t_list *curr_b;

	ft_putstr("==== STACK A B ====");
	curr_a = a->top;
	curr_b = b->top;
	while (curr_a || curr_b)
	{
		ft_putstr_fd("        ", 1);
		if (curr_a)
			ft_putnbr(*(int *)curr_a->content);
		else
			ft_putchar('.');
		ft_putstr_fd(" | ", 1);
		if (curr_b)
			ft_putnbr(*(int *)curr_b->content);
		else
			ft_putchar('.');
		ft_putchar('\n');
		if (curr_a)
			curr_a = curr_a->next;
		if (curr_b)
			curr_b = curr_b->next;
	}
	ft_putstr("=== ENDSTACK A B ===");

}

void	init_stack(t_stack *s)
{
	s->size = 0;
	s->count = 0;
	s->top = NULL;
}

void	free_stack(t_stack *s)
{
	t_list	*curr;
	t_list	*next;

	if (!s)
		return ;
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
