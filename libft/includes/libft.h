/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:44:32 by ssfar             #+#    #+#             */
/*   Updated: 2020/06/11 18:45:08 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define RGB			"\033[38;2;"
# define B_BLACK		"\033[40m"
# define B_RED			"\033[41m"
# define B_GREEN		"\033[42m"
# define B_YELLOW		"\033[43m"
# define B_BLUE			"\033[44m"
# define B_MAGENTA		"\033[45m"
# define B_CYAN			"\033[46m"
# define B_WHITE		"\033[47m"
# define B_RGB			"\033[48;2;"
# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define FAINT			"\033[2m"
# define ITALIC			"\033[3m"
# define UNDERLINED		"\033[4m"
# define BLINK			"\033[5m"
# define REVERSE		"\033[7m"
# define HIDDEN			"\033[8m"
# define EOC			"\033[39m"
# define EOB			"\033[49m"

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

ssize_t			ft_atoi(const char *str);
void			*ft_bzero(void *s, size_t n);
int_fast16_t	ft_casecmp(int_fast8_t a, int_fast8_t b);
size_t			count_char_occur(char *str, int_fast8_t c);
size_t			count_word(const char *s, int_fast8_t separator);
char			**free_strtab(char **tab);
char			*aproximative_ftoa_no_symbol(long double fnb,
	uint_fast8_t precision, uint_fast8_t sharp);
char			*get_float_mantissa(long double fnb, uint_fast8_t precision);
ssize_t			get_va_int(va_list arg, uint_fast8_t bits, uint_fast8_t z);
size_t			get_va_uint(va_list arg, uint_fast8_t bits, uint_fast8_t z);
uint_fast8_t	intlen(ssize_t nb);
uint_fast8_t	intlen_no_symbol(ssize_t nb);
uint_fast8_t	ft_isalnum(int_fast8_t c);
uint_fast8_t	ft_isalpha(int_fast8_t c);
t_bool			ft_isascii(int c);
uint_fast8_t	ft_isblank(int_fast8_t c);
uint_fast8_t	ischarset(int_fast8_t c, char *charset);
uint_fast8_t	ft_iscntrl(int_fast8_t c);
uint_fast8_t	ft_isdigit(int_fast8_t c);
uint_fast8_t	ft_isgraph(int_fast8_t c);
uint_fast8_t	ft_islower(int_fast8_t c);
uint_fast8_t	ft_isprint(int_fast8_t c);
uint_fast8_t	ft_isspace(int_fast8_t c);
uint_fast8_t	ft_isupper(int_fast8_t c);
uint_fast8_t	ft_isxdigit(int_fast8_t c);
char			*ft_itoa(ssize_t nb);
char			*itoa_no_symbol(ssize_t nb);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src,
	int_fast8_t c, size_t n);
void			*ft_memchr(const void *s, int_fast8_t c, size_t n);
int_fast16_t	ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int_fast8_t c, size_t len);
void			ft_putchar(int_fast8_t c);
void			ft_putchar_fd(int_fast8_t c, int_fast16_t fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int_fast16_t fd);
void			ft_putnbr(ssize_t n);
void			ft_putnbr_fd(ssize_t n, int_fast16_t fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int_fast16_t fd);
char			*repeat_chardup(char c, size_t repeat);
void			round_float(size_t *integer, char *mantissa);
uint_fast8_t	str_is_alpha(char *str);
uint_fast8_t	str_is_charset(char *str, char *charset);
uint_fast8_t	str_is_lowercase(char *str);
uint_fast8_t	str_is_numeric(char *str);
uint_fast8_t	str_is_printable(char *str);
uint_fast8_t	str_is_uppercase(char *str);
void			strcapitalize(char *str);
int_fast16_t	ft_strcasecmp(const char *s1, const char *s2);
char			*ft_strcasestr(const char *haystack, const char *needle);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int_fast8_t c);
size_t			strchr_len(const char *s, int_fast8_t c);
void			ft_strclr(char *s);
int_fast16_t	ft_strcmp(const char *s1, const char *s2);
uint_fast16_t	strcmp_charset(const char *s1, const char *s2, char *charset);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
uint_fast8_t	ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*strjoin_free(char *s1, char *s2, uint_fast8_t to_free);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
size_t			ft_strlen(const char *s);
void			strlowcase(char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
uint_fast8_t	strn_is_charset(char *str, char *charset, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int_fast16_t	ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *s1, size_t n);
uint_fast8_t	ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *haystack,
	const char *needle, size_t len);
char			*ft_strrchr(const char *s, int_fast8_t c);
void			strrev(char *str);
char			**ft_strsplit(char const *s, int_fast8_t c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, size_t start, size_t len);
char			*ft_strtrim(char const *s);
void			strupcase(char *str);
void			swap(ssize_t *a, ssize_t *b);
void			u_swap(size_t *a, size_t *b);
int_fast8_t		ft_tolower(int_fast8_t c);
int_fast8_t		ft_toupper(int_fast8_t c);
uint_fast8_t	uintlen(size_t unb);
size_t			upower(size_t unb, uint_fast8_t pow);
char			*utoa_base(size_t unb, char *base);
char			*utoa(size_t unb);
char			**strtab(ssize_t x, ssize_t y);
void			strtab_iteri(char **tab, void (*f)(unsigned int, char *));
char			**free_strtab_offset(char **tab, ssize_t offset);
char			str_is_numeric_no_symbol(char *str);
size_t			atou(const char *str);
void			bubble_sort(size_t *arr, size_t n);
t_bool			atoi_overflow(const char *str, int *result);
t_bool			atou_overflow(const char *str, unsigned int *result);
t_bool			atol_overflow(const char *str, long long *result);
t_bool			atoul_overflow(const char *str, unsigned long long *result);
void			ft_free_tab(char **tab);
#endif
