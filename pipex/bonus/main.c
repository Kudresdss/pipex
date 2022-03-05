/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:44:53 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/23 21:48:08 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/get_next_line.h"

int	main(int ac, char	**av, char	**env)
{
	t_pipe	st;
	int		i;

	i = 0;
	st.here_d = 1;
	if (ac < 5)
	{
		write(2, "Pipex: invalid number of arguments\n", 35);
		return (1);
	}
	if (!ft_strncmp("here_doc", av[1], 0))
		ft_here_doc(&st, ac, av);
	else
	{
		st.f1 = open(av[1], O_RDONLY);
		st.f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (st.f1 < 0 || st.f2 < 0)
		return (ft_file_err(&st));
	st.path = ft_find_path(env);
	if (ac == 5 || (ac == 6 && st.here_d == 2))
		pipex(&st, av, env);
	else
		pipex_mult(&st, ac, av, env);
	return (0);
}
