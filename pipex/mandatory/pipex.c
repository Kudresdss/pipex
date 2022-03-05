/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:34:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/04 19:34:47 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static int	ft_child_1_process(t_pipe	*st, char	*cmd1, char	**env)
{
	int		i;
	char	*cmd;

	i = 0;
	dup2(st->f1, STDIN_FILENO);
	dup2(st->end[1], STDOUT_FILENO);
	close(st->end[0]);
	close(st->f1);
	st->args_c_1 = ft_split(cmd1, ' ');
	while (st->path[i])
	{
		cmd = ft_strjoin(st->path[i], st->args_c_1[0], 0);
		if (access(cmd, 1) == 0)
			execve(cmd, st->args_c_1, env);
		free(cmd);
		i++;
	}
	close(st->end[1]);
	ft_free_arr(st->args_c_1);
	ft_free_arr(st->path);
	write(2, "Command not found\n", 18);
	exit(4);
}

static int	ft_child_2_process(t_pipe	*st, char	*cmd2, char	**env)
{
	int		i;
	char	*cmd;

	i = 0;
	dup2(st->end[0], STDIN_FILENO);
	dup2(st->f2, STDOUT_FILENO);
	close(st->end[1]);
	close(st->f2);
	st->args_c_2 = ft_split(cmd2, ' ');
	while (st->path[i])
	{
		cmd = ft_strjoin(st->path[i], st->args_c_2[0], 0);
		if (access(cmd, 1) == 0)
			execve(cmd, st->args_c_2, env);
		free(cmd);
		i++;
	}
	close(st->end[0]);
	ft_free_arr(st->args_c_2);
	ft_free_arr(st->path);
	write(2, "Command not found\n", 18);
	exit(5);
}

static void	pipex(t_pipe	*st, char	**av, char	**env)
{
	int		status;

	if (pipe(st->end) == -1)
		return (perror("Pipe"));
	st->child_1 = fork();
	if (st->child_1 < 0)
		return (perror("Fork-1"));
	else if (!st->child_1)
		ft_child_1_process(st, av[2], env);
	st->child_2 = fork();
	if (st->child_2 < 0)
		return (perror("Fork-2"));
	else if (!st->child_2)
		ft_child_2_process(st, av[3], env);
	close(st->end[0]);
	close(st->end[1]);
	waitpid(st->child_1, &status, 0);
	waitpid(st->child_2, &status, 0);
	ft_free_arr(st->path);
	exit(0);
}

int	main(int ac, char	**av, char	**env)
{
	t_pipe	st;
	int		i;

	i = 0;
	if (ac < 5)
	{
		write(2, "Pipex: invalid number of arguments\n", 35);
		return (1);
	}
	st.f1 = open(av[1], O_RDONLY);
	st.f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (st.f1 < 0 || st.f2 < 0)
		return (ft_file_err(&st));
	st.path = ft_find_path(env);
	pipex(&st, av, env);
	return (0);
}
