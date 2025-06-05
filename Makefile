NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -Iinc

SRCS = actions.c  init.c  main.c  parse.c  str_utils.c  thread.c  utils.c

SRC_DIR = src/
OBJ_DIR = obj/
SANI_OBJ_DIR = obj_sani/

OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
SANI_OBJS = $(addprefix $(SANI_OBJ_DIR), $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

sani: CFLAGS += -fsanitize=address -g
sani: $(SANI_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SANI_OBJS)
	@echo "Run with: ASAN_OPTIONS=detect_leaks=1 ./$(NAME) <args>"

$(SANI_OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(SANI_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(SANI_OBJ_DIR)

fclean: clean
	rm -f $(NAME)

normal: fclean all

re: fclean all

.PHONY: all clean fclean re sani normal
