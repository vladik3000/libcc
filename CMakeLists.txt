cmake_minimum_required(VERSION 3.8)
project(cc)
# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(cc STATIC
		avl/avl_balance.c
		avl/avl_del.c
		avl/avl_del_one.c
		avl/avl_get.c
		avl/avl_get_height.c
		avl/avl_get_pair.c
		avl/avl_get_val.c
		avl/avl_insert.c
		avl/avl_map_infix.c
		avl/avl_map_postfix.c
		avl/avl_map_prefix.c
		avl/avl_new.c
		avl/avl_new_node.c
		char/fdputchar.c
		char/isalnum.c
		char/isalpha.c
		char/isascii.c
		char/isdigit.c
		char/islower.c
		char/isprint.c
		char/isspace.c
		char/isupper.c
		char/iswspace.c
		char/putchar.c
		char/tolower.c
		char/toupper.c
		file/get_next_line.c
		graph/graph_cmp.c
		graph/graph_del.c
		graph/graph_get_names.c
		graph/graph_get_suffixes.c
		graph/graph_init.c
		graph/graph_insert.c
		graph/graph_new.c
		hash_map/hash_map_del.c
		hash_map/hash_map_del_one.c
		hash_map/hash_map_get_pair.c
		hash_map/hash_map_get_val.c
		hash_map/hash_map_insert.c
		hash_map/hash_map_iter.c
		hash_map/hash_map_new.c
		list/lst_add.c
		list/lst_add_sort.c
		list/lst_circle.c
		list/lst_del.c
		list/lst_del_circle.c
		list/lst_del_one.c
		list/lst_find.c
		list/lst_iter.c
		list/lst_map.c
		list/lst_new.c
		math/max.c
		math/min.c
		memory/bzero.c
		memory/memalloc.c
		memory/memccpy.c
		memory/memchr.c
		memory/memcmp.c
		memory/memcpy.c
		memory/memdel.c
		memory/memmove.c
		memory/memset.c
		memory/xmalloc.c
		num/atoi.c
		num/atoll.c
		num/fdputnbr.c
		num/numlen.c
		num/numlen_base.c
		num/putnbr.c
		regex/match.c
		regex/nmatch.c
		string/fdputendl.c
		string/fdputs.c
		string/itoa.c
		string/itoabase.c
		string/strnjoin.c
		string/putendl.c
		string/puts.c
		string/strcat.c
		string/strchr.c
		string/strclr.c
		string/strcmp.c
		string/strcpy.c
		string/strdel.c
		string/strdup.c
		string/strequ.c
		string/strhash.c
		string/striter.c
		string/striteri.c
		string/strjoin.c
		string/strlcat.c
		string/strlen.c
		string/strmap.c
		string/strmapi.c
		string/strncat.c
		string/strncmp.c
		string/strncpy.c
		string/strnequ.c
		string/strnew.c
		string/strnstr.c
		string/strrchr.c
		string/strsplit.c
		string/strsplitcharset.c
		string/strstr.c
		string/strsub.c
		string/strtrim.c
		vector/vec_del.c
		vector/vec_del_one.c
		vector/vec_get_at.c
		vector/vec_get_last.c
		vector/vec_new.c
		vector/vec_push.c
		vector/vec_push_at.c
		vector/vec_rm_at.c
		vector/vec_rm_last.c
        hash_map/hash_map_get_size.c
		list/lst_get_size.c
		list/lst_del_one_if.c
		char/getch.c
		char/utf8_sizeof_symbol.c
		sort/quick_sort.c
		string/strarr_del.c
		string/strarr_getsize.c
		string/strarr_print.c
		optparse/optparse.c vector/vec_pop.c string/utf8_display_strlen.c optparse/print_usage.c string/strisnum.c string/strispath.c)

target_include_directories(cc PUBLIC avl char file graph hash_map list math memory num string vector sort optparse regex .)