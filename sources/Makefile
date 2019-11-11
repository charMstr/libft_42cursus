# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charmstr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 21:40:12 by charmstr          #+#    #+#              #
#    Updated: 2019/11/11 22:49:49 by charmstr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a
.PHONY = clean fclean re all bonus
FT_H = ./libft.h
OBJ_PATH = ./objects/
INCLUDE_PATH = ./
I_FLAGS = -I $(INC_PATH)

FILES = atoi\
	bzero\
	calloc\
	isalnum\
	isalpha\
	isascii\
	isdigit\
	isprint\
	itoa\
	memccpy\
	memchr\
	memcmp\
	memcpy\
	memmove\
	memset\
	putchar_fd\
	putendl_fd\
	putnbr_fd\
	putstr_fd\
	split\
	strchr\
	strdup\
	strjoin\
	strlcat\
	strlcpy\
	strlen\
	strmapi\
	strncmp\
	strnstr\
	strrchr\
	strtrim\
	substr\
	tolower\
	toupper\

BONUS_FILES = lstadd_back\
	lstadd_front\
	lstclear\
	lstdelone\
	lstiter\
	lstlast\
	lstmap\
	lstnew\
	lstsize\

# you can here decide to put srcs/ft_%.c, same for objects, objs/ft_%.o
SRC = $(patsubst %, $(OBJ_PATH)ft_%.c, $(FILES))
OBJ = $(SRC:.c=.o)

SRC_BONUS = $(addprefix $(OBJ_PATH)ft_,$(addsuffix .c, $(BONUS_FILES)))
OBJ_BONUS =$(SRC_BONUS:.c=.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@echo "created the $@ repository"

$(NAME): $(OBJ) $(FT_H)
	@echo "building Library $(NAME)..."
	@ar -rc $@ $^
	@echo "indexing Library $@ with ranlib..."
	@ranlib $@

$(OBJ): $(OBJ_PATH)%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_BONUS): $(OBJ_PATH)%.o : %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus: $(OBJ_PATH) $(OBJ) $(OBJ_BONUS) $(FT_H)
	@echo "building Library $(NAME) with BONUSES..."
	@ar -rc $(NAME) $^
	@echo "indexing Library $(NAME) with ranlib..."
	@ranlib $(NAME)

clean:
	@echo "removing $(OBJ_PATH) containing all the .o files..."
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
