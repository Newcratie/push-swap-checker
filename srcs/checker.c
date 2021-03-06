/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:12 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/22 12:51:22 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

char		**programme_read(void)
{
	char		*ope;
	char		**prog;
	char		**tmp;
	int			i;
	int			gnl;

	prog = NULL;
	i = 0;
	while (1 == (gnl = get_next_line(0, &ope)))
	{
		tmp = prog;
		if (!(prog = tabcat(tmp, ope, ++i)))
			return (NULL);
		free(tmp);
	}
	if (prog == NULL)
		return (NULL);
	prog[i] = NULL;
	return (prog);
}

static int	browse_function(char *ope, int step, t_heap *heap)
{
	int	i;

	i = 0;
	while (i < END)
	{
		if (!ft_strcmp(g_ope[i].code_ope, ope))
		{
			g_ope[i].func_ope(heap);
			i = END;
		}
		else if (i == END - 1)
		{
			ft_printf("Browse function: Error >%s<\n", ope);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	execute_prog(char **prog, t_heap *heap)
{
	int	i;

	i = 0;
	i = 0;
	while (prog[i])
	{
		if (!browse_function(prog[i], i, heap))
			return (0);
		i++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	char	**prog;
	t_heap	*heap;

	heap = NULL;
	if (!(heap = parser(ac, av)) || ac == 0)
	{
		ft_printf("usage: ./checker [arg]\n");
		return (0);
	}
	if (heap->a.len == 1)
		return (0);
	init_math(heap);
	if ((prog = programme_read()))
		execute_prog(prog, heap);
	if (is_sorted(heap))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_checker(prog);
	ft_quit(heap);
	return (0);
}
