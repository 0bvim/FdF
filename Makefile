# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 07:00:31 by vde-frei          #+#    #+#              #
#    Updated: 2023/10/13 08:57:52 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#

NAME = fdf

LIBFT = lib/libft/libft.a

SHELL := /bin/bash
COUNT := 0

BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

MFLAGS = -ldl -lglfw -pthread -lm -g3
CFLAGS = -Wall -Wextra -Werror -g3

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#
CFILES = main.c ft_error.c ft_parse_map.c ft_movement.c ft_draw.c \
		 ft_drawline.c ft_project.c

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(CFILES:%.c=%.o))

INCLUDES = -I./ -I./lib/libft -I./MLX42/include/MLX42
LINCLUDES = -L./lib/libft -lft
MLX = MLX42/build/libmlx42.a
	   
all : $(NAME)

obj: 
	@mkdir -p $(OBJ_DIR)

.SILENT:
$(MLX): 
	@cd MLX42 && cmake -B build -DDEBUG=1
	@cd MLX42 && cmake --build build -j4

obj/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(MLX) obj $(OBJ)
	@$(MAKE) -sC ./lib/libft
	@$(CC) $(OBJ) $(INCLUDES) $(LIBFT) $(MLX) $(LINCLUDES) $(CFLAGS) $(MFLAGS) -o $(NAME)
	@printf "\n$(MAGENTA)FdF compiled\n$(RESET)"

%.o:%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@cc $(CFLAGS) -I ./ -c $< -o $@
	@printf "$(GREEN)Compiling FdF %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean :
	@make clean -sC lib/libft/
	@rm -rf MLX42/build
	@rm -rf obj
	@printf "$(RED)Deleted objects$(RESET)\n"

fclean : clean
	@make clean -sC lib/libft/
	@rm -rf $(NAME)
	@printf "$(RED)Libft is deleted$(RESET)\n"


re : fclean all

.PHONY: clean fclean re all bonus
