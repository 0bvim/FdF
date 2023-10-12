# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-freistudent.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 12:05:38 by vde-frei          #+#    #+#              #
#    Updated: 2023/10/12 11:34:11 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#				CONFIGURATION				       #
#******************************************************************************#

NAME = libft.a

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

CFLAGS = -Wall -Wextra -Werror -g3 -O3


#******************************************************************************#
#				  INCLUDES				       #
#******************************************************************************#



#******************************************************************************#
#				SOURCE FILES				       #
#******************************************************************************#
CFILES = ft_atoi.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_strlen.c \
    ft_tolower.c \
    ft_toupper.c \
    ft_memset.c \
    ft_bzero.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_strlcpy.c \
    ft_strlcat.c \
    ft_strncmp.c \
    ft_strchr.c \
    ft_strrchr.c \
    ft_strdup.c \
    ft_memchr.c \
    ft_strnstr.c \
    ft_memcmp.c \
    ft_calloc.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putendl.c \
    ft_putnbr_fd.c \
    ft_itoa.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_lstnew.c \
    ft_lstadd_front.c \
    ft_lstsize.c \
    ft_lstlast.c \
    ft_lstadd_back.c \
    ft_lstdelone.c \
    ft_lstclear.c \
    ft_lstiter.c \
    ft_lstmap.c \
    get_next_line.c \
    get_next_line_utils.c \
	ft_str_append.c \
	ft_isspace.c \
	ft_max.c \
	ft_min.c

OBJS = $(CFILES:%.c=%.o)


#******************************************************************************#
#				 MAKEFILE PROGRESS			       #
#******************************************************************************#


#******************************************************************************#
#				 MAKEFILE SETUP				       #
#******************************************************************************#


#******************************************************************************#
#				  LIBFT CONFIG				       #
#******************************************************************************#

	   
all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "\n$(MAGENTA)Libft compiled\n$(RESET)"

%.o:%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@cc $(CFLAGS) -I ./ -c $< -o $@
	@printf "$(GREEN)Compiling libft %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean :
	@rm -f $(OBJS)
	@printf "$(RED)Deleted objects$(RESET)\n"

fclean : clean
	@rm -f $(NAME)
	@printf "$(RED)Libft is deleted$(RESET)\n"


re : fclean all

.PHONY: clean fclean re all
