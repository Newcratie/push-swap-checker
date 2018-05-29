/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:19:20 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/29 15:53:20 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stack *stack)
{
	t_lst	*beg;

	beg = stack->a->next;;
	stack->a->next = stack->a->next->next;
	beg->next = stack->a;
	stack->a = beg;
}

void	swap_b(t_stack *stack)
{
	t_lst	*beg;

	beg = stack->b->next;;
	stack->b->next = stack->b->next->next;
	beg->next = stack->b;
	stack->b = beg;
}

void	swap_both(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
