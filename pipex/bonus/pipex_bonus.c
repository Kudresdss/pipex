/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:34:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/23 21:47:02 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/get_next_line.h"

static void	ft_close_pipes(t_pipe	*st)
{
	close(st->end[0]);
	close(st->end[1]);
	return ;
}

int	pipex_mult_if(t_pipe	*st, int ac, char	**env)
{
	if ((ac - st->here_d) % 2 == 1)
	{
		st->child = fork();
		if (st->child < 0)
			return (1);
		if (!st->child)
			ft_child_x2_process(st, "cat", env);
		close(st->end[0]);
		close(st->end[1]);
	}
	return (0);
}

static int	pipex_mult_cycle(t_pipe	*st, int ac, char	**av, char	**env)
{
	st->i = st->here_d + 2;
	while (st->i < ac - 2)
	{
		if ((st->i - st->here_d) % 2 == 0)
		{
			if (pipe(st->end) == -1)
				return (1);
		}
		st->child = fork();
		if (st->child < 0)
			return (2);
		if (!st->child && (st->i - st->here_d) % 2 == 1)
			ft_child_x2_process(st, av[st->i], env);
		else if (!st->child && (st->i - st->here_d) % 2 == 0)
			ft_child_x1_process(st, av[st->i], env);
		if ((st->i - st->here_d) % 2 == 0)
			wait(NULL);
		else if ((st->i - st->here_d) % 2 == 1)
			ft_close_pipes(st);
		st->i++;
	}
	if (pipex_mult_if(st, ac, env))
		return (2);
	return (0);
}

void	pipex(t_pipe	*st, char	**av, char	**env)
{
	int		status;

	if (pipe(st->end) == -1)
		return (perror("Pipe"));
	st->child = fork();
	if (st->child < 0)
		return (perror("Fork-1"));
	else if (!st->child)
		ft_child_1_process(st, av[st->here_d + 1], env);
	st->parent = fork();
	if (st->parent < 0)
		return (perror("Fork-2"));
	else if (!st->parent)
		ft_parent_process(st, av[st->here_d + 2], env);
	close(st->end[0]);
	close(st->end[1]);
	waitpid(st->child, &status, 0);
	waitpid(st->parent, &status, 0);
	ft_free_arr(st->path);
	if (!access("to_append.txt", 0))
		unlink("to_append.txt");
	if (st->here_d == -1)
		unlink("multy_cmd.txt");
	exit(0);
}

void	pipex_mult(t_pipe	*st, int ac, char	**av, char	**env)
{
	char	*av_swap[2];

	st->child = fork();
	if (st->child < 0)
		return (perror("Fork_child_1m"));
	else if (!st->child)
		ft_child_1m_process(st, av[st->here_d + 1], env);
	wait(NULL);
	if (pipex_mult_cycle(st, ac, av, env))
		exit(1);
	wait(NULL);
	av_swap[0] = "cat";
	av_swap[1] = av[ac - 2];
	st->here_d = -1;
	pipex(st, av_swap, env);
	exit(0);
}
