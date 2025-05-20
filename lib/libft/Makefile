# コメントアウトは要らない
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -O0 -g
AR = ar rcs
RM = rm -f

SRC_DIR = srcs/
INC_DIR = incs/
OBJ_DIR = objs/

LIBC_DIR = $(SRC_DIR)libc/
PRINTF_DIR = $(SRC_DIR)printf/
GNL_DIR = $(SRC_DIR)gnl/
LIST_DIR = $(SRC_DIR)list/

INCLUDES = -I./$(INC_DIR)

LIBC_SRCS = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strtol.c \
		ft_strtoll.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_memmove.c \
		ft_memcmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_isspace.c ft_toupper.c ft_tolower.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

PRINTF_SRCS = ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c \
		ft_print_ptr.c ft_print_str.c

GNL_SRCS = get_next_line.c get_next_line_utils.c

LIST_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

LIBC_FILES = $(addprefix $(LIBC_DIR), $(LIBC_SRCS))
PRINTF_FILES = $(addprefix $(PRINTF_DIR), $(PRINTF_SRCS))
GNL_FILES = $(addprefix $(GNL_DIR), $(GNL_SRCS))
LIST_FILES = $(addprefix $(LIST_DIR), $(LIST_SRCS))

LIBC_OBJS = $(addprefix $(OBJ_DIR), $(LIBC_SRCS:.c=.o))
PRINTF_OBJS = $(addprefix $(OBJ_DIR), $(PRINTF_SRCS:.c=.o))
GNL_OBJS = $(addprefix $(OBJ_DIR), $(GNL_SRCS:.c=.o))
LIST_OBJS = $(addprefix $(OBJ_DIR), $(LIST_SRCS:.c=.o))

ALL_SRCS = $(LIBC_FILES) $(PRINTF_FILES) $(GNL_FILES) $(LIST_FILES)
ALL_OBJS = $(LIBC_OBJS) $(PRINTF_OBJS) $(GNL_OBJS) $(LIST_OBJS)


all: $(NAME)

$(NAME): $(LIBC_OBJS)
	$(AR) $@ $^
	@echo "$(NAME) created with libc functions only"

printf: $(LIBC_OBJS) $(PRINTF_OBJS)
	$(AR) $(NAME) $^
	@echo "$(NAME) updated with printf functions"

get_next_line: $(LIBC_OBJS) $(GNL_OBJS)
	$(AR) $(NAME) $^
	@echo "$(NAME) updated with get_next_line function"

list: $(LIBC_OBJS) $(LIST_OBJS)
	$(AR) $(NAME) $^
	@echo "$(NAME) updated with list functions"

full: $(ALL_OBJS)
	$(AR) $(NAME) $^
	@echo "$(NAME) created with all functions"

$(OBJ_DIR)%.o: $(LIBC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(LIST_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@echo "Object files removed"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re printf get_next_line list full
