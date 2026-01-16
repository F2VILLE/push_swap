/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_macro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:47:17 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 13:20:02 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_opcode opcode)
{
	char	*op_name = "  ";

	if (opcode == SA)
		op_name = "sa";
	else if (opcode == SB)
		op_name = "sb";
	else if (opcode == SS)
		op_name = "ss";
	else if (opcode == PA)
		op_name = "pa";
	else if (opcode == PB)
		op_name = "pb";
	else if (opcode == RA)
		op_name = "ra";
	else if (opcode == RB)
		op_name = "rb";
	else if (opcode == RR)
		op_name = "rr";
	else if (opcode == RRA)
		op_name = "rra";
	else if (opcode == RRB)
		op_name = "rrb";
	else if (opcode == RRR)
		op_name = "rrr";
	ft_putstr(op_name);
}

void op(t_stack *a, t_stack *b, t_opcode opcode)
{

	if (opcode == SA || opcode == SS)
		swap(a);
	if (opcode == SB || opcode == SS)
		swap(b);
	if (opcode == PA)
		push(a, b);
	if (opcode == PB)
		push(b, a);
	if (opcode == RA || opcode == RR)
		rotate_up(a);
	if (opcode == RB || opcode == RR)
		rotate_up(b);
	if (opcode == RRA || opcode == RRR)
		rotate_down(a);
	if (opcode == RRB || opcode == RRR)
		rotate_down(b);
	print_op(opcode);
#ifdef DEBUG_MODE
	print_stacks(a, b);

#endif
}
