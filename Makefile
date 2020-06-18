# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:15:55 by ssfar             #+#    #+#              #
#    Updated: 2020/06/18 02:47:13 by ssfar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = corewar
NAME1 = asm
NAME2 = revasm

CC = clang
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I ./libft/includes #-ofast

INC_DIR = includes
SRC_DIR = sources/virtual_machine
SRC_DIR1 = sources/assembler_revassembler
OBJ_DIR = objects

SRC_NAME =	add_sub_fun.c \
			allocation.c \
			binary_fun.c \
			file_reading.c \
			fork_fun.c \
			get_value.c \
			ld_fun.c \
			lget_value.c \
			live_jmp_aff_fun.c \
			load.c \
			main.c \
			parsing.c \
			printing.c \
			registry.c \
			store_fun.c \
			utils.c \
			vm.c \
			visu_main.c \
			visu_aff.c \
			visu_init.c \
			visu_color.c \

SRC_NAME1 =	dynamic_string.c\
			errors_asm.c\
			main_asm.c\
			parser_asm.c\
			util_asm.c\
			header_asm.c\
			delete_asm.c\
			check_header.c\
			instructs_asm.c\
			get_instructs.c\
			check_instructs.c\
			struct_asm.c\
			op.c\
			line_asm.c

SRC_NAME2 =	errors_revasm.c\
			errors_asm.c\
			main_revasm.c\
			file_revasm.c\
			parser_revasm.c\
			struct_asm.c\
			util_asm.c\
			op.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC1 = $(addprefix $(SRC_DIR1)/, $(SRC_NAME1))
SRC2 = $(addprefix $(SRC_DIR1)/, $(SRC_NAME2))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))
OBJ1 = $(addprefix $(OBJ_DIR)/, $(SRC_NAME1:.c=.o))
OBJ2 = $(addprefix $(OBJ_DIR)/, $(SRC_NAME2:.c=.o))

EOC			= \033[0;0m
RED			= \033[0;31m
GREEN		= \033[0;32m

all: $(NAME) $(NAME1) $(NAME2)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJ) -lncurses ./libft/libft.a -o $@
	@chmod 755 $(NAME)
	@printf "$(GREEN)$(NAME) Makefile : $(NAME) created\n$(EOC)"

$(NAME1): $(OBJ1)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJ1) ./libft/libft.a -o $@
	@chmod 755 $(NAME1)
	@printf "$(GREEN)$(NAME) Makefile : $(NAME1) created\n$(EOC)"

$(NAME2): $(OBJ2)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJ2) ./libft/libft.a -o $@
	@chmod 755 $(NAME2)
	@printf "$(GREEN)$(NAME) Makefile : $(NAME2) created\n$(EOC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR1)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft fclean
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)$(NAME) Makefile : $(OBJ_DIR) deleted\n$(EOC)"

fclean: clean
	@rm -f $(NAME) $(NAME1) $(NAME2)
	@printf "$(RED)$(NAME) Makefile : $(NAME), $(NAME1) and $(NAME2) deleted\n$(EOC)"

re: fclean all
