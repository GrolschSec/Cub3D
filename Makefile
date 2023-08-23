# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 17:58:33 by rlouvrie          #+#    #+#              #
#    Updated: 2023/08/23 13:23:42 by rlouvrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

INCLUDES =	-Iinclude -Isrc/libft -Isrc/mlx

CFLAGS	=	-Wall -Werror -Wextra

LDFLAGS =   -L$(SRCDIR)/$(FT) -lft -L$(SRCDIR)/$(MLX) -lmlx -lXext -lX11

LIBFT_PATH = $(SRCDIR)/$(FT)/libft.a

MLX_PATH = $(SRCDIR)/$(MLX)/libmlx.a

SRCDIR	=	src

OBJDIR	=	obj

FT		=	libft

MLX		=	mlx

SRC		=	main.c			\
			filecheck_1.c	\
			filecheck_2.c	\
			filecheck_3.c	\
			parsing.c		\
			free.c			\
			map_check_1.c	\
			map_check_2.c	\
			map_check_3.c	\
			init_texture.c	\
			window.c		\
			error.c		

OBJS    =   $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_PATH) $(MLX_PATH) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(CFLAGS) $(INCLUDES) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_PATH):
	make -C $(SRCDIR)/$(MLX)

$(LIBFT_PATH):
	make -C $(SRCDIR)/$(FT)

clean:
	make -C $(SRCDIR)/$(FT) clean
	make -C $(SRCDIR)/$(MLX) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(SRCDIR)/$(FT) fclean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g -O0
debug: fclean all

.PHONY: all re clean fclean debug
