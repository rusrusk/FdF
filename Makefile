# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 15:34:15 by rkultaev          #+#    #+#              #
#    Updated: 2022/07/06 17:38:44 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = fdf.h

LIBFTA = libft42_fdf/libft.a

MINILIBX_MAC = minilibx_macos/libmlx.a

SRCS = read_file.c count_words.c main.c \
		color_settings.c draw.c init_image.c error.c keyboard_hook.c \
		string_window.c handle_event.c operations.c


OBJ = $(SRCS:%.c=%.o)


CC = gcc

CFLAGS = -Wall -Werror -Wextra -g


$(NAME) : $(OBJ) $(HEADER)
		make bonus -C libft42_fdf/
		make -C minilibx_macos
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) $(MINILIBX_MAC) -framework OpenGl -framework AppKit -o $(NAME) 
		


all: $(NAME)

clean :
	rm -f $(OBJ)
	make clean -C libft42_fdf/
	
fclean : clean
	rm -f $(NAME)
	make fclean -C libft42_fdf/

re : fclean all

.PHONY : all clean fclean re