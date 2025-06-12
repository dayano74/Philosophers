NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -Iinc

SRCS = actions.c  init.c  main.c  parse.c  str_utils.c  thread.c  utils.c

SRC_DIR = src/
OBJ_DIR = obj/

OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@if [ -d "$(OBJ_DIR)" ] && [ -z "$$(ls -A $(OBJ_DIR))" ]; then rm -rf $(OBJ_DIR); fi

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
