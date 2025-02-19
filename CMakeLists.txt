cmake_minimum_required(VERSION 3.14)
project(lem_in C)

set(CMAKE_C_STANDARD 90)


add_executable(lem-in main.c lem_in.h graph.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_islower.c
        libft/ft_isprint.c
        libft/ft_isupper.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_str_is_alpha.c
        libft/ft_str_is_lowercase.c
        libft/ft_str_is_numeric.c
        libft/ft_str_is_printable.c
        libft/ft_str_is_uppercase.c
        libft/ft_str_to_lowercase.c
        libft/ft_str_to_uppercase.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strndup.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        get_next_line.c
        get_next_line.h
        ft_charcount.c
        libft/ft_isspace.c
        libft/future_libft.c
        libft/future_libft_addon_one.c
        libft/future_libft_addone_two.c
        libft/future_libft_addon_three.c
        exdlstnew.c exdlstdel.c exdlstadd.c
        exdlst.h exdlstlen.c exdlstdub.c
        exdlst.c
        bfs.c
        suurballe.c
        utilits.c print.c get_next_line.c
        ft_charcount.c input.c helpfulness.c
        libft/ft_isspace.c output.c path.c
        beams.c clearing_structures.c aqueue.c
        aqueue.h is_element.c cleaning_structures.c graphdub.c edge.c edgenode.c add.c room.c link.c paths.c length.c go.c ants.c isolate.c true.c edges.c dublicate.c remove.c)

include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/libft")