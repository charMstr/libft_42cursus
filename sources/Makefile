# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charmstr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 21:40:12 by charmstr          #+#    #+#              #
#    Updated: 2019/11/12 00:29:21 by charmstr         ###   ########.fr        #
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

REMOVE_FG = \033[38;5;196m 
CREAT_FG = \033[38;5;46m
BLACK_FG = \033[38;5;0m
BLACK_BG = \033[48;5;0m
CLEAR_COLOR = \033[m

NAME_BG = \033[48;5;39m 
BONUS_BG = \033[48;5;213m
OBJECTS_BG = \033[48;5;11m
RANLIB_BG = \033[48;5;172m

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
	@mkdir -p $(OBJ_PATH)
	@echo "\t\t$(CREAT_FG)created the $(OBJECTS_BG)$(BLACK_FG)$@ $(BLACK_BG)$(CREAT_FG) repository$(CLEAR_COLOR)"

$(NAME): $(OBJ) $(FT_H)
	@echo "\t\t$(CREAT_FG)building Library $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG)...$(CLEAR_COLOR)"

	ar -rc $@ $^

	@echo "\t\t$(CREAT_FG)indexing Library  $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG) with $(RANLIB_BG)$(BLACK_FG) ranlib $(BLACK_BG)$(CREAT_FG)...$(CLEAR_COLOR)"
	@ranlib $@

$(OBJ): $(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_BONUS): $(OBJ_PATH)%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


bonus: $(OBJ_PATH) $(OBJ_BONUS) $(OBJ) $(FT_H)
	@echo "\t\t$(CREAT_FG)building Library $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG) with $(BONUS_BG)$(BLACK_FG) BONUSES $(BLACK_BG)$(CREAT_FG)...$(CLEAR_COLOR)"

	ar -rc $(NAME) $(OBJ) $(OBJ_BONUS) $(FT_H)

	@echo "\t\t$(CREAT_FG)indexing Library $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG) with $(RANLIB_BG)$(BLACK_FG) ranlib $(BLACK_BG)$(CREAT_FG)...$(CLEAR_COLOR)"
	@ranlib $(NAME)

clean:
	@echo "\t\t$(REMOVE_FG)deleting $(OBJECTS_BG)$(BLACK_FG)$(OBJ_PATH) $(BLACK_BG)$(REMOVE_FG) containing all the .o files...$(CLEAR_COLOR)" 
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\t\t$(REMOVE_FG)deleting $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(REMOVE_FG)...$(CLEAR_COLOR)" 
	@rm -rf $(NAME)

re: fclean all
