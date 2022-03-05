/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:37:21 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/04 19:35:48 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/get_next_line.h"

int	ft_child_1_process(t_pipe	*st, char	*cmd1, char	**env)
{
	int		i;
	char	*cmd;

	i = 0;
	if (st->here_d == -1)
		st->f1 = open("multy_cmd.txt", O_RDONLY);
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
	exit(4);
}

int	ft_child_1m_process(t_pipe	*st, char	*cmd1, char **env)
{
	int		i;
	char	*cmd;

	i = 0;
	st->f_mult = open("multy_cmd.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(st->f1, STDIN_FILENO);
	dup2(st->f_mult, STDOUT_FILENO);
	close(st->f1);
	close(st->f_mult);
	st->args_c_1 = ft_split(cmd1, ' ');
	while (st->path[i])
	{
		cmd = ft_strjoin(st->path[i], st->args_c_1[0], 0);
		if (access(cmd, 1) == 0)
			execve(cmd, st->args_c_1, env);
		free(cmd);
		i++;
	}
	ft_free_arr(st->args_c_1);
	ft_free_arr(st->path);
	exit(6);
}

int	ft_child_x1_process(t_pipe	*st, char	*cmd1, char	**env)
{
	int		i;
	char	*cmd;

	i = 0;
	st->f_mult = open("multy_cmd.txt", O_RDONLY);
	dup2(st->f_mult, STDIN_FILENO);
	dup2(st->end[1], STDOUT_FILENO);
	close(st->f_mult);
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
	close(st->f_mult);
	ft_free_arr(st->args_c_1);
	ft_free_arr(st->path);
	exit(7);
}

int	ft_child_x2_process(t_pipe	*st, char	*cmd1, char	**env)
{
	int		i;
	char	*cmd;

	i = 0;
	st->f_mult = open("multy_cmd.txt", O_RDWR | O_TRUNC);
	dup2(st->end[0], STDIN_FILENO);
	dup2(st->f_mult, STDOUT_FILENO);
	close(st->end[0]);
	close(st->end[1]);
	close(st->f_mult);
	st->args_c_1 = ft_split(cmd1, ' ');
	while (st->path[i])
	{
		cmd = ft_strjoin(st->path[i], st->args_c_1[0], 0);
		if (access(cmd, 1) == 0)
			execve(cmd, st->args_c_1, env);
		free(cmd);
		i++;
	}
	ft_free_arr(st->args_c_1);
	ft_free_arr(st->path);
	exit(8);
}

int	ft_parent_process(t_pipe	*st, char	*cmd2, char	**env)
{
	int		i;
	char	*cmd;

	i = 0;
	dup2(st->end[0], STDIN_FILENO);
	dup2(st->f2, STDOUT_FILENO);
	close(st->end[0]);
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
	ft_free_arr(st->args_c_2);
	ft_free_arr(st->path);
	exit(5);
}
