# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 12:57:07 by mbjaghou          #+#    #+#              #
#    Updated: 2022/01/18 23:47:47 by mbjaghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRC =	ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strncmp.c \
		pipe.c \
		pipex.c \
		search_path.c \
		utils.c \

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
