/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_macro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:47:17 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 11:53:40 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_opcode opcode)
{
	const char	*op_name;

	if (opcode == SA)
		op_name = "SA";
	else if (opcode == SB)
		op_name = "SB";
	else if (opcode == SS)
		op_name = "SS";
	else if (opcode == PA)
		op_name = "PA";
	else if (opcode == PB)
		op_name = "PB";
	else if (opcode == RA)
		op_name = "RA";
	else if (opcode == RB)
		op_name = "RB";
	else if (opcode == RR)
		op_name = "RR";
	else if (opcode == RRA)
		op_name = "RRA";
	else if (opcode == RRB)
		op_name = "RRB";
	else if (opcode == RRR)
		op_name = "RRR";
	else
		op_name = "UNKNOWN";
	printf("opcode: %s\n", op_name);
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
