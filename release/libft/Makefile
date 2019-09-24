# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:11:37 by dheidenr          #+#    #+#              #
#    Updated: 2019/04/23 17:46:32 by dheidenr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_putchar_fd.c \
		ft_strdel.c   \
		ft_strncmp.c \
		ft_isdigit.c     \
		ft_memmove.c    \
		ft_atoi.c \
		ft_putendl.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_islower.c   \
		ft_memset.c   \
		ft_strncpy.c\
		ft_bzero.c  \
		ft_putendl_fd.c \
		ft_striter.c  \
		ft_strsplit.c  \
		ft_isprint.c   \
		ft_strcat.c    \
		ft_strnew.c \
		ft_putnbr.c  \
		ft_striteri.c  \
		ft_strsub.c  \
		ft_isupper.c   \
	    ft_strchr.c    \
	    ft_strrchr.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_strjoin.c  \
		ft_strtrim.c \
		ft_memccpy.c   \
		ft_strcmp.c\
		ft_strstr.c\
		ft_memalloc.c \
		ft_putstr.c \
		ft_strlen.c  \
		ft_isalnum.c   \
		ft_memchr.c    \
		ft_strcpy.c    \
		ft_tolower.c\
		ft_memdel.c \
		ft_putstr_fd.c \
		ft_strmap.c   \
		ft_isalpha.c   \
		ft_isspace.c   \
		ft_memcmp.c    \
		ft_strdup.c   \
		ft_toupper.c\
		ft_putchar.c \
		ft_strclr.c  \
		ft_strmapi.c  \
		ft_isascii.c    \
		ft_memcpy.c   \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strncat.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstadd.c \
		ft_lstmap.c \
		ft_str_is_lowercase.c \
		ft_str_is_numeric.c \
		ft_str_is_printable.c \
		ft_str_is_uppercase.c \
		ft_str_is_alpha.c \
		ft_strndup.c \
		ft_str_to_lowercase.c \
		ft_str_to_uppercase.c \
		future_libft.c \
		future_libft_addon_one.c \
		future_libft_addone_two.c \
		future_libft_addon_three.c \


OBJ = $(SRC:.c=.o)

TRASH = *.gch

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	@echo "Compiling .o files is started."
	@echo "......."
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
	@echo "Compiling .o files is complete."
	@echo "Library $(NAME) compilation started."
	@ar rc $(NAME) $(OBJ)
	@echo "Library $(NAME) compilation complete."
	@echo "Library $(NAME) indexing started."
	@ranlib $(NAME)
	@echo "Library $(NAME) indexing complete."
clean:
	@rm	-f $(OBJ)
	@rm -f $(TRASH)

fclean: clean
	@rm	-f $(NAME)

re: clean fclean all
