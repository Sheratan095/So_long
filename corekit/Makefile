NAME = libcorekit.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
# TO DO rimettere le flag
ARCHIVE = ar rc $(NAME)
REMOVE = rm -f

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m


SRC = ./src/char/ft_tolower.c \
	./src/char/ft_toupper.c \
	./src/conversions/ft_atoi.c \
	./src/conversions/ft_itoa.c \
	./src/list/ft_lstadd_back.c \
	./src/list/ft_lstadd_front.c \
	./src/list/ft_lstclear.c \
	./src/list/ft_lstdelone.c \
	./src/list/ft_lstiter.c \
	./src/list/ft_lstlast.c \
	./src/list/ft_lstmap.c \
	./src/list/ft_lstnew.c \
	./src/list/ft_lstsize.c \
	./src/memory/ft_bzero.c \
	./src/memory/ft_calloc.c \
	./src/memory/ft_memchr.c \
	./src/memory/ft_memcmp.c \
	./src/memory/ft_memcpy.c \
	./src/memory/ft_memmove.c \
	./src/memory/ft_memset.c \
	./src/string/ft_split.c \
	./src/string/ft_strchr.c \
	./src/string/ft_strdup.c \
	./src/string/ft_striteri.c \
	./src/string/ft_strjoin.c \
	./src/string/ft_strjoin_free_s1.c \
	./src/string/ft_strlcat.c \
	./src/string/ft_strlcpy.c \
	./src/string/ft_strlen.c \
	./src/string/ft_strmapi.c \
	./src/string/ft_strncmp.c \
	./src/string/ft_strnstr.c \
	./src/string/ft_strrchr.c \
	./src/string/ft_strtolower.c \
	./src/string/ft_strtoupper.c \
	./src/string/ft_strtrim_free_s1.c \
	./src/string/ft_substr.c \
	./src/string/ft_is_string_numeric.c \
	./src/output/ft_putchar_fd.c \
	./src/output/ft_putendl_fd.c \
	./src/output/ft_putnbr_fd.c \
	./src/output/ft_putstr_fd.c \
	./src/types/ft_isalnum.c \
	./src/types/ft_isalpha.c \
	./src/types/ft_isascii.c \
	./src/types/ft_isdigit.c \
	./src/types/ft_isprint.c \
	./src/2d_matrix/ft_count_matrix_row.c \
	./src/2d_matrix/ft_duplicate_char_matrix.c \
	./src/2d_matrix/ft_print_char_matrix.c \
	./src/2d_matrix/ft_free_matrix.c \

SRC_STACK = ./src/int_stack/ft_initialize_stack.c \
			./src/int_stack/ft_create_node.c \
			./src/int_stack/ft_display_stack.c \
			./src/int_stack/ft_is_stack_empty.c \
			./src/int_stack/ft_free_stack.c \
			./src/int_stack/ft_push.c \
			./src/int_stack/ft_push_tail.c \
			./src/int_stack/ft_pop.c \
			./src/int_stack/ft_pop_tail.c \
			./src/int_stack/ft_stack_contains.c \
			./src/int_stack/ft_search_duplicate.c \


SRC_PRINTF = ./src/ft_printf/ft_is_in.c \
			./src/ft_printf/ft_printf.c \
			./src/ft_printf/ft_putbase.c \
			./src/ft_printf/ft_putchar.c \
			./src/ft_printf/ft_putnbr.c \
			./src/ft_printf/ft_putptr.c \
			./src/ft_printf/ft_putstr.c \
			./src/ft_printf/ft_unsignedputnbr.c

SRC_GET_NEXT_LINE = ./src/get_next_line/get_next_line_bonus.c \
				./src/get_next_line/get_next_line_utils_bonus.c

OBJ = ${SRC:.c=.o} ${SRC_PRINTF:.c=.o} ${SRC_GET_NEXT_LINE:.c=.o} ${SRC_STACK:.c=.o}

%.o: %.c
	@$(COMPILE) -c $< -Iincludes -o $@
#	@echo "$(BLUE)[COREKIT]:\t$< COMPILED! $(RESET)"

all: $(NAME)

$(NAME): $(OBJ)
	@$(ARCHIVE) $(OBJ)
	@echo "$(GREEN)[COREKIT]: \t LIBRARY CREATED$(RESET)"

clean:
	@$(REMOVE) $(OBJ)
	@echo "$(RED)[COREKIT]: \t OBJECTS DELETED$(RESET)"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "$(RED)[COREKIT]: \t LIBRARY DELETED$(RESET)"

re: fclean all

.PHONY: all clean fclean re