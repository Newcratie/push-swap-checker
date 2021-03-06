/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:40 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 19:21:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_up(long **heap, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		heap[0][i] = heap[0][i + 1];
		i++;
	}
}

void	to_down(long **heap, int len)
{
	int	i;

	i = 0;
	while (len > -1)
	{
		heap[0][len + 1] = heap[0][len];
		len--;
	}
}

int		exec_ope(char *code_ope, t_heap *heap)
{
	int	i;

	i = 0;
	while (i < END)
	{
		if (!ft_strcmp(code_ope, g_ope[i].code_ope))
		{
			g_ope[i].func_ope(heap);
			ft_putendl(code_ope);
			return (1);
		}
		i++;
	}
	return (0);
}
