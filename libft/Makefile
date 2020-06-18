# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:15:55 by ssfar             #+#    #+#              #
#    Updated: 2020/06/11 18:43:18 by ssfar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) #-ofast


INC_DIR = includes
SRC_DIR = sources
OBJ_DIR = objects

SRC_NAME = ft_atoi.c intlen_no_symbol.c ft_islower.c ft_lstdelone.c \
  ft_putstr.c ft_strcasecmp.c ft_strdup.c ft_strmap.c ft_strnstr.c \
  ft_tolower.c ft_bzero.c ft_isalnum.c ft_isprint.c ft_lstiter.c ft_memmove.c \
  ft_putstr_fd.c ft_strcasestr.c ft_strequ.c ft_strmapi.c ft_strrchr.c \
  ft_toupper.c ft_casecmp.c ft_isalpha.c ft_isspace.c ft_lstmap.c ft_memset.c \
  str_is_alpha.c ft_strcat.c ft_striter.c strn_is_charset.c strrev.c \
  utoa_base.c count_char_occur.c ft_isascii.c ft_isupper.c ft_lstnew.c \
  ft_putchar.c str_is_charset.c ft_strchr.c ft_striteri.c ft_strncat.c \
  ft_strsplit.c count_word.c ft_isblank.c ft_isxdigit.c strcmp_charset.c \
  ft_memalloc.c ft_putchar_fd.c str_is_lowercase.c strchr_len.c \
  ft_strjoin.c ft_strncmp.c ft_strstr.c free_strtab.c ischarset.c \
  ft_itoa.c ft_memccpy.c ft_putendl.c str_is_numeric.c ft_strclr.c \
  ft_strlcat.c ft_strncpy.c ft_strsub.c get_va_int.c ft_iscntrl.c \
  itoa_no_symbol.c ft_memchr.c ft_putendl_fd.c str_is_printable.c \
  ft_strcmp.c ft_strlcpy.c ft_strndup.c ft_strtrim.c get_va_uint.c \
  ft_isdigit.c ft_lstadd.c ft_memcmp.c ft_putnbr.c str_is_uppercase.c \
  ft_strcpy.c ft_strlen.c ft_strnequ.c strupcase.c intlen.c ft_isgraph.c \
  ft_lstdel.c ft_memcpy.c ft_putnbr_fd.c strcapitalize.c ft_strdel.c \
  strlowcase.c ft_strnew.c swap.c repeat_chardup.c str_is_numeric_no_symbol.c \
  strjoin_free.c utoa.c u_swap.c uintlen.c upower.c round_float.c \
  get_float_mantissa.c aproximative_ftoa_no_symbol.c strtab.c \
  free_strtab_offset.c ft_memdel.c gnl_no_buff.c atou.c bubble_sort.c \
  strtab_iteri.c atoi_overflow.c atou_overflow.c big_endian.c atol_overflow.c\
  atoul_overflow.c ft_free_tab.c\
  get_next_line.c \
  ft_printf/ft_printf.c \
  ft_printf/parsing.c \
  ft_printf/flags.c \
  ft_printf/type_duf.c \
  ft_printf/type_percent_cs.c \
  ft_printf/type_boxpxx.c \
  ft_printf/colors.c \
  ft_printf/rgb.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))

EOC			= \033[0;0m
RED			= \033[0;31m
GREEN		= \033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@printf "$(GREEN)$(NAME) Makefile : $(OBJ_DIR) and $(NAME) created\n$(EOC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)$(NAME) Makefile : $(OBJ_DIR) deleted\n$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) Makefile : $(NAME) deleted\n$(EOC)"

re: fclean all
