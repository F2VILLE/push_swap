/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:44:13 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/19 02:09:00 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	l = ft_lstlast(*lst);
	if (!l)
		*lst = new;
	else
		l->next = new;
}

t_node	*append_node(t_node **root, int val)
{
	t_node	*new;
	t_node	*curr;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->val = val;
	new->idx = -1;
	new->next = NULL;
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (root);
}

void	fill_stack(t_stack *s, char *av[])
{
	int	i;
	int	val;

	i = 0;
	s->count = 0;
	s->top = NULL;
	while (i < s->size)
	{
		val = atoi(av[i]);
		append_node(&s->top, val);
		i++;
		s->count++;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	ft_putstr("==== STACK ====");
	curr = stack->top;
	while (curr)
	{
		ft_putnbr(curr->val);
		ft_putchar('\n');
		curr = curr->next;
	}
	ft_putstr("=== ENDSTACK ===");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node *curr_a;
	t_node *curr_b;

	ft_putstr("==== STACK A B ====");
	curr_a = a->top;
	curr_b = b->top;
	while (curr_a || curr_b)
	{
		ft_putstr_fd("        ", 1);
		if (curr_a)
			ft_putnbr(curr_a->val);
		else
			ft_putchar('.');
		ft_putstr_fd(" | ", 1);
		if (curr_b)
			ft_putnbr(curr_b->val);
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
	t_node	*curr;
	t_node	*next;

	if (!s)
		return ;
	curr = s->top;
	while (curr)
	{
		next = curr->next;

		if (curr->val)
			free(curr->val);
		if (curr)
			free(curr);
		curr = next;
	}
}
