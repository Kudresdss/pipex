/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:42:20 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/23 21:47:42 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../headers/get_next_line.h"

//
// СЛЕДИТЬ ЗА ВКЛЮЧЕНИЯМИ .H!!!
//

typedef struct s_pipe
{
	int		f1;
	int		f2;
	int		f_mult;
	int		here_d;
	int		i;
	int		end[2];
	char	**path;
	char	**args_c_1;
	char	**args_c_2;
	pid_t	child;
	pid_t	parent;
}	t_pipe;

char	**ft_split(char const	*s, char c);
size_t	ft_strlen(char const	*str);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
char	*ft_strjoin(char *s1, char const	*s2, int x);
void	pipex(t_pipe	*st, char	**av, char	**env);
void	pipex_mult(t_pipe	*st, int ac, char	**av, char	**env);
char	**ft_find_path(char **env);
void	ft_here_doc(t_pipe	*st, int ac, char	**av);
int		ft_child_1_process(t_pipe	*st, char	*cmd1, char	**env);
int		ft_child_1m_process(t_pipe	*st, char	*cmd1, char **env);
int		ft_child_x1_process(t_pipe	*st, char	*cmd1, char	**env);
int		ft_child_x2_process(t_pipe	*st, char	*cmd1, char	**env);
int		ft_parent_process(t_pipe	*st, char	*cmd2, char	**env);
int		ft_file_err(t_pipe	*st);
void	ft_free_arr(char	**arr);

#endif