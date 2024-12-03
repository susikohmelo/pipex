.PHONY: all clean fclean re bonus

NAME = libft.a

CC = cc
FLAG = -Wall -Wextra -Werror
AR = ar rcs
RM = -rm -f

C_FILES = \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strrchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c

C_FILES_BONUS = $(C_FILES) \
ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c \
ft_lstdelone_bonus.c \
ft_lstiter_bonus.c \
ft_lstlast_bonus.c \
ft_lstmap_bonus.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c

O_FILES = $(C_FILES:.c=.o)
O_FILES_BONUS = $(C_FILES_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $(C_FILES)

$(NAME): $(O_FILES)
	$(AR) $(NAME) $(O_FILES)

clean:
	$(RM) $(O_FILES_BONUS) .bonus

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

bonus : .bonus

.bonus : $(O_FILES_BONUS)
	$(CC) $(FLAG) -c $(C_FILES_BONUS)
	$(AR) $(NAME) $(O_FILES_BONUS)
	touch .bonus
