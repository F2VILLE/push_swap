/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:43:54 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 09:44:06 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

