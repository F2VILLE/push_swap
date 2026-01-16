/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 04:27:30 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 11:52:11 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		size;
	int		count;
	t_list	*top;
}	t_stack;

typedef enum e_opcode
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_opcode;

void	swap(t_stack *s);
void	rotate_up(t_stack *s);
void	rotate_down(t_stack *s);
void	push(t_stack *dst, t_stack *src);
void	fill_stack(t_stack *s, char *av[]);
void	print_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);
void	init_stack(t_stack *s);
void	free_stack(t_stack *s);
void	ft_puterr(char *str);
void	ft_putstr(char *str);
int		validate_inp(int ac, char *args[]);
void	op(t_stack *a, t_stack *b, t_opcode opcode);

#endif