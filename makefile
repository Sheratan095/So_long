NAME		= so_long

COREKIT_PATH = ./corekit

SRC = main.c \
	map_validation/map_validation.c \
	map_validation/map_parsing.c \
	map_validation/map_content.c \
	utils.c \
	window_management/hooking.c \
	window_management/window_handling.c \
	window_management/rendering.c \
	window_management/finish_game.c \
	movement.c \
	enemy_movement.c \
	cleaning.c

FLAGS		= -Wall -Werror -Wextra -g

OBJS		= $(SRC:%.c=%.o)

#-s used to silent terminal output
#2>/dev/null 1>/dev/null Redirect stout adnd stderr to null file and don't display them
#  -> it can be writed >/dev/null 2>&1

$(NAME): $(OBJS)
	@${MAKE} -sC corekit
	@${MAKE} -sC mlx 2>/dev/null 1>/dev/null
	@echo "$(GREEN)[MLX]:\t\t MLX CREATED$(RESET)"
	@cc $(OBJS) $(FLAGS) -lm -L$(COREKIT_PATH) -lcorekit -Lmlx -lmlx -lXext -lX11 -o $(NAME) -s
	@echo "$(GREEN)[SO_LONG]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

%.o: %.c
	@cc -c $< -o $@ $(FLAGS) -I$(COREKIT_PATH)/includes -Imlx

#-i is used to ingore errors
clean:
	@rm -fr *.o
	@rm -fr **/*.o
	@${MAKE} -C corekit clean -s
	@echo "$(RED)[COREKIT]:\t COREKIT CLEAN$(RESET)"
	@if [ -d "./mlx/" ]; then \
		${MAKE} -sC mlx clean >/dev/null 2>&1; \
		echo "$(RED)[MLX]:\t\t MLX CLEAN$(RESET)"; \
	fi

fclean: clean
	@rm -f *.a
	@rm -f *.out
	@rm -f *.gch
	@rm -f $(NAME)
	@${MAKE} -C corekit fclean -s
	@echo "$(RED)[COREKIT]:\t COREKIT FCLEAN$(RESET)"

re: fclean all

#If mlx folder doesn't exist, download it
download:
	@if [ ! -d "./mlx/" ]; then \
		wget -q https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz; \
		tar -xf minilibx-linux.tgz; \
		mv minilibx-linux mlx; \
		rm -f minilibx-linux.tgz; \
		echo "$(GREEN)[MLX]:\t\t MLX DOWNLADED$(RESET)"; \
	else \
		echo "$(RED)[MLX]:\t\t MLX ALREADY EXISTS$(RESET)"; \
	fi

remove_mlx:
	@rm -fr mlx

test: all
	 ./$(NAME) maps/map.ber

val: all
	 valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./$(NAME) "maps/map.ber"

.PHONY: download

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m