# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 13:49:23 by ymirna            #+#    #+#              #
#    Updated: 2022/02/23 22:01:04 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

PATH_M		=	mandatory/

PATH_B		=	bonus/

PATH_GNL	=	get_next_line/

PATH_H		=	headers/

PATH_F		=	functions/

SRC_M		=	pipex.c ft_find_path.c

SRC_B		= 	main.c pipex_bonus.c ft_find_path_bonus.c ft_here_doc_bonus.c ft_bonus_processes.c

SRC_GNL		=	get_next_line.c get_next_line_utils.c

HEADER		=	pipex.h pipex_bonus.h get_next_line.h

SRC_F		=	ft_split.c ft_strjoin.c ft_err.c

SRC_M_P		=	$(addprefix $(PATH_M), $(SRC_M))

SRC_B_P		=	$(addprefix $(PATH_B), $(SRC_B))

SRC_GNL_P	=	$(addprefix $(PATH_GNL), $(SRC_GNL))

HEADER_P	=	$(addprefix $(PATH_H), $(HEADER))

FUNCT_P		=	$(addprefix $(PATH_F), $(SRC_F))

OBJS_M		=	$(SRC_M_P:%.c=%.o)

OBJS_B		=	$(SRC_B_P:%.c=%.o)

OBJS_GNL	=	$(SRC_GNL_P:%.c=%.o)

OBJS_F		=	$(FUNCT_P:%.c=%.o)

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

.PHONY:		all bonus re clean fclean

%.o : %.c	$(HEADER_P)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS_M) $(OBJS_F) $(OBJS_GNL) Makefile
			$(CC) $(FLAGS) $(OBJS_M) $(OBJS_GNL) $(OBJS_F) -o $(NAME)

bonus:		
			@make OBJS_M="$(OBJS_B)" all

clean:		
			rm -f $(OBJS_M)
			rm -f $(OBJS_B)
			rm -f $(OBJS_GNL)
			rm -f $(OBJS_F)

fclean:		clean
			rm -f $(NAME)

re:			fclean all