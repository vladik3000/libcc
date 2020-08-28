# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:08:51 by dbutterw          #+#    #+#              #
#    Updated: 2020/07/07 18:05:33 by dbutterw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   \
		avl/avl_balance.c \
		avl/avl_del.c \
		avl/avl_del_one.c \
		avl/avl_get.c \
		avl/avl_get_height.c \
		avl/avl_get_pair.c \
		avl/avl_get_val.c \
		avl/avl_insert.c \
		avl/avl_map_infix.c \
		avl/avl_map_postfix.c \
		avl/avl_map_prefix.c \
		avl/avl_new.c \
		avl/avl_new_node.c \
		char/fdputchar.c \
		char/isalnum.c \
		char/isalpha.c \
		char/isascii.c \
		char/isdigit.c \
		char/islower.c \
		char/isprint.c \
		char/isspace.c \
		char/isupper.c \
		char/iswspace.c \
		char/putchar.c \
		char/tolower.c \
		char/toupper.c \
		file/get_next_line.c \
		hash_map/hash_map_del.c \
		hash_map/hash_map_del_one.c \
		hash_map/hash_map_get.c \
		hash_map/hash_map_get_pair.c \
		hash_map/hash_map_get_val.c \
		hash_map/hash_map_insert.c \
		hash_map/hash_map_iter.c \
		hash_map/hash_map_iter_pair.c \
		hash_map/hash_map_new.c \
		list/lst_add.c \
		list/lst_add_sort.c \
		list/lst_circle.c \
		list/lst_del.c \
		list/lst_del_circle.c \
		list/lst_del_one.c \
		list/lst_iter.c \
		list/lst_map.c \
		list/lst_new.c \
		list/lst_find.c \
		math/max.c \
		math/min.c \
		memory/bzero.c \
		memory/memalloc.c \
		memory/memccpy.c \
		memory/memchr.c \
		memory/memcmp.c \
		memory/memcpy.c \
		memory/memdel.c \
		memory/memmove.c \
		memory/memset.c \
		memory/xmalloc.c \
		num/atoi.c \
		num/atoll.c \
		num/fdputnbr.c \
		num/numlen.c \
		num/numlen_base.c \
		num/putnbr.c \
		regex/match.c \
		regex/nmatch.c \
		string/fdputendl.c \
		string/fdputs.c \
		string/itoa.c \
		string/itoabase.c \
		string/nstrjoin.c \
		string/putendl.c \
		string/puts.c \
		string/strcat.c \
		string/strchr.c \
		string/strclr.c \
		string/strcmp.c \
		string/strcpy.c \
		string/strdel.c \
		string/strdup.c \
		string/strequ.c \
		string/strhash.c \
		string/striter.c \
		string/striteri.c \
		string/strjoin.c \
		string/strlcat.c \
		string/strlen.c \
		string/strmap.c \
		string/strmapi.c \
		string/strncat.c \
		string/strncmp.c \
		string/strncpy.c \
		string/strnequ.c \
		string/strnew.c \
		string/strnstr.c \
		string/strrchr.c \
		string/strsplit.c \
		string/strsplitcharset.c \
		string/strstr.c \
		string/strsub.c \
		string/strtrim.c \
		vector/vec_del.c \
		vector/vec_del_one.c \
		vector/vec_get_at.c \
		vector/vec_get_last.c \
		vector/vec_new.c \
		vector/vec_push.c \
		vector/vec_push_at.c \
		vector/vec_rm_at.c \
		vector/vec_rm_last.c \
		graph/graph_insert.c \
		graph/graph_cmp.c \
		graph/graph_get_suffixes.c \
		graph/graph_get_names.c \
		graph/graph_del.c \
		graph/graph_init.c \
		graph/graph_new.c

DIRS = \
		avl			\
		char		\
		file		\
		graph		\
		hash_map	\
		list		\
		math		\
		memory		\
		num			\
		regex		\
		string		\
		vector

NAME = libft.a

INC = -I . $(addprefix -I ,$(DIRS))

OBJ_DIR = ./obj
OBJ_DIRS = 	$(addprefix $(OBJ_DIR)/,$(DIRS))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

DEP_DIR = ./dep
DEP_DIRS = 	$(addprefix $(DEP_DIR)/,$(DIRS))
DEP = $(addprefix $(DEP_DIR)/,$(SRC:.c=.d))

ifeq (1,$(DEBUG))
	CFLAGS = -g
else
	CFLAGS = -Wall -Wextra -Werror
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(DEP) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIRS)

$(DEP): | $(DEP_DIR)
$(DEP_DIR):
	mkdir -p $(DEP_DIRS)

M_FLAGS = -MMD -MF $(patsubst %.c,$(DEP_DIR)/%.d,$<)

$(OBJ_DIR)/%.o: %.c
	gcc $(INC) $(CFLAGS) -c $< -o $@  $(M_FLAGS)

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

include $(wildcard $(DEP))