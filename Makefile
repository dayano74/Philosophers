NAME = bin/philo
NAME_BONUS = bin/philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -Iinc

SRCS = actions.c  init.c  main.c  parse.c  str_utils.c  thread.c  utils.c
BONUS_SRCS = main_bonus.c 

SRC_DIR = src/
MAND_DIR = philo/
BONUS_DIR = philo_bonus/
OBJ_DIR = obj/
BONUS_OBJ_DIR = obj_bonus/
SANI_OBJ_DIR = obj_sani/

OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR), $(notdir $(BONUS_SRCS:.c=.o)))
SANI_OBJS = $(addprefix $(SANI_OBJ_DIR), $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p bin
	$(CC) $(CFLAGS) -I$(MAND_DIR)inc -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(MAND_DIR)$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MAND_DIR)inc -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@mkdir -p bin
	$(CC) $(CFLAGS) -I$(BONUS_DIR)inc -o $(NAME_BONUS) $(BONUS_OBJS)

$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)$(SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -I$(BONUS_DIR)inc -c $< -o $@

sani: CFLAGS += -fsanitize=address -g
sani: $(SANI_OBJS)
	$(CC) $(CFLAGS) -I$(MAND_DIR)inc -o $(NAME) $(SANI_OBJS)
	@echo "Run with: ASAN_OPTIONS=detect_leaks=1 ./$(NAME) <args>"

$(SANI_OBJ_DIR)%.o: $(MAND_DIR)$(SRC_DIR)%.c
	@mkdir -p $(SANI_OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MAND_DIR)inc -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(SANI_OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -rf bin

normal: fclean all

re: fclean all

.PHONY: all clean fclean re sani normal bonus
