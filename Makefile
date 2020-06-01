
NAME = lem-in
SRCS_PATH = srcs/
LIBFT = libft/
LIB = -L $(LIBFT) -lft
INCLUDES_PATH = includes/
INCLUDES = -I includes/ -I libft/
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

FILES = lem_in.c \
		utility_functions/create_lists.c \
		utility_functions/utilities.c \
		utility_functions/check_if_number.c \
		map_and_display/get_map_info.c \
		map_and_display/solve_map.c \
		map_and_display/print_results.c \
		path_functions/create_paths.c \
		room_functions/create_rooms.c
SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

lib :
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIB)
	@/bin/echo "$(NAME) Compiled!"

clean:
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@make -C $(LIBFT) fclean 
	@/bin/rm -f $(NAME)

re: fclean all
