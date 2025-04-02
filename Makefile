# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thodavid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 10:54:39 by thodavid          #+#    #+#              #
#    Updated: 2025/04/02 13:08:34 by thodavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS / VARIABLES

NAME		= server
NAME2		= client

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

################################################################################
## SOURCES

SRCS_SERVER		= server.c
SRCS_CLIENT		= client.c

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)


################################################################################
## REGLES

all: $(NAME) $(NAME2)


########## LINKING #############
$(NAME): $(OBJS_SERVER)
	@${MAKE} -C ./ft_printf
	$(CC) $(CFLAG) $(OBJS_SERVER) ./ft_printf/libftprintf.a -o $(NAME)

$(NAME2): $(OBJS_CLIENT)
	@${MAKE} -C ./ft_printf
	$(CC) $(CFLAG) $(OBJS_CLIENT) ./ft_printf/libftprintf.a -o $(NAME2)

########## COMPILING ############
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

################################################################################
## CLEANING

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@${MAKE} -C ./ft_printf clean

fclean: clean
	rm -f $(NAME) $(NAME2)
	@${MAKE} -C ./ft_printf clean

re: fclean all

.PHONY: all clean fclean re
