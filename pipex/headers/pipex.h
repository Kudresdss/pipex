/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:42:20 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/14 18:14:58 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../headers/get_next_line.h"

typedef struct s_pipe
{
	int		f1;
	int		f2;
	int		end[2];
	char	**path;
	char	**args_c_1;
	char	**args_c_2;
	pid_t	child_1;
	pid_t	child_2;
}	t_pipe;

char	**ft_split(char const	*s, char c);
size_t	ft_strlen(char const	*str);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
char	*ft_strjoin(char *s1, char const	*s2, int x);
char	**ft_find_path(char **env);
int		ft_file_err(t_pipe	*st);
void	ft_free_arr(char	**arr);

#endif