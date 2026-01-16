/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_macro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:47:17 by fdeville          #+#    #+#             */
/*   Updated: 2026/01/16 10:11:02 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op(t_stack *a, t_stack *b, t_opcode opcode)
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
	#ifdef DEBUG_MODE
	const char *op_name;
	switch (opcode)
	{
		case SA: op_name = "SA"; break;
		case SB: op_name = "SB"; break;
		case SS: op_name = "SS"; break;
		case PA: op_name = "PA"; break;
		case PB: op_name = "PB"; break;
		case RA: op_name = "RA"; break;
		case RB: op_name = "RB"; break;
		case RR: op_name = "RR"; break;
		case RRA: op_name = "RRA"; break;
		case RRB: op_name = "RRB"; break;
		case RRR: op_name = "RRR"; break;
		default: op_name = "UNKNOWN"; break;
	}
	printf("opcode: %s\n", op_name);
	print_stacks(a, b);

	#endif
}
