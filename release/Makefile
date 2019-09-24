# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:11:55 by dheidenr          #+#    #+#              #
#    Updated: 2019/05/27 11:57:47 by dheidenr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	main.c \
		graph.c graphdub.c \
		exdlstnew.c exdlstdel.c exdlstadd.c exdlstlen.c exdlstdub.c exdlst.c \
		aqueue.c \
		bfs.c suurballe.c \
		path.c beams.c edge.c edgenode.c \
        room.c link.c paths.c ants.c \
        length.c add.c go.c dublicate.c remove.c \
        isolate.c true.c edges.c \
		input.c output.c \
		is_element.c \
		utilits.c helpfulness.c print.c \
		clearing_structures.c cleaning_structures.c \
		get_next_line.c \
        ft_charcount.c

INCLUDES = lem_in.h exdlst.h aqueue.h get_next_line.h

FLAGS = -Wall -Werror -Wextra

TRASH = $(SRC:.c=.o)

all: $(TRASH) $(NAME)

$(NAME): $(TRASH)
		@make -C libft/
		@gcc $(SRC) $(FLAGS) -o $(NAME) -L libft -lft

clean:
		@make -C libft/ clean
		@echo "Delete files of compilation"
		@rm -f *.o

fclean: clean
		@make -C libft/ fclean
		@echo "Delete $(NAME)"
		@rm -f $(NAME)

%.o: %.c $(INCLUDES)
	gcc $(FLAGS) -c $< -o $@

re: fclean all
