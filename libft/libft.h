/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:32:47 by dheidenr          #+#    #+#             */
/*   Updated: 2019/04/23 17:53:06 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void				*ft_memalloc(size_t size);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr (const char *s, int c);
char				*ft_strrchr (const char *s, int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr (const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy (void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_str_is_lowercase(char *s);
int					ft_str_is_alpha(char *s);
int					ft_str_is_numeric(char *s);
int					ft_str_is_printable(char *s);
int					ft_str_is_uppercase(char *s);
char				*ft_strndup(const char *src, size_t n);
char				*ft_str_to_lowercase(char *s);
char				*ft_str_to_uppercase(char *s);
typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;
t_dlist	*ft_dlstnew(void const *content, size_t content_size);
void	ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t));
void	memsetdel(void *entity, size_t size);
void	ft_dlstadd(t_dlist **adlst, t_dlist *new);
void	dlist_int_put(t_dlist *dlist);
size_t	dlistlen(t_dlist *stack);
t_dlist	*dlstdub(t_dlist *stack);

t_dlist	*len_int_to_dlst(int *array);

char	*strjoin_free(char *s1, char *s2, int clear_number);
void	ft_dlistsput(t_dlist *stack1, t_dlist *stack2);
void	ft_dlstdelone(t_dlist **adlst, void (*del)(void*, size_t));
int		ft_putstr_return(const char *str, int result);

void	ft_putstr_exit(const char *str);
void	*void_free(void *void_free, void *value);
void	*dlst_free(t_dlist *dlist_free, void *value);
void	*val_free_void(char **values, t_dlist **space_stack);
char	*malloc_str(char *str);

int		equiv_max_template(char *src, char *template);
void	brute_force_one_symbol(char *elements, char *template);
void	dlist_int_put_in_cycle(t_dlist *dlist);

int		check_equallity(t_dlist *input, t_dlist *sorted);

#endif
