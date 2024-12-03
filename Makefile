.PHONY: all clean fclean re

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_BLUE=\033[0;34m
C_CYAN=\033[0;36m
C_END=\033[0m

NAME = pipex

LIBFTFOLDER = source/libft
LIBFTMAKE = make -C
LIBFTBONUS = bonus
LIBFTCLEAN = clean
LIBFTFCLEAN = fclean

SPATH = source/

CC = cc
FLAG = -Wall -Wextra -Werror -I
AR = ar rcs
RM = -rm -f

C_FILES = \
pipex.c \
utils_pipex.c \
ft_csplit.c

C_FILES := $(addprefix $(SPATH), $(C_FILES))

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(C_FILES)
	$(LIBFTMAKE) $(LIBFTFOLDER)
	$(CC) $(FLAG) $(SPATH) $(C_FILES) -L $(LIBFTFOLDER) -l ft -o $(NAME)
	@echo "$(C_CYAN)Using: $(CC) $(FLAG) $(SPATH)$(C_END)"
	@echo "$(C_GREEN)⌘ $(NAME) compiled! ⌘$(C_END)"

clean:
	$(LIBFTMAKE) $(LIBFTFOLDER) $(LIBFTCLEAN)
	$(RM) $(O_FILES)
	$(RM) $(O_BONUS_FILES)
	@echo "$(C_CYAN)⌘ $(NAME) cleaned up! ⌘$(C_END)"

fclean: clean
	$(LIBFTMAKE) $(LIBFTFOLDER) $(LIBFTFCLEAN)
	$(RM) $(NAME)
	@echo "$(C_GREEN)⌘ $(NAME) removed! ⌘$(C_END)"

re: fclean all
