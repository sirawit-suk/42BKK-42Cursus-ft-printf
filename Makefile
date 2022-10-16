### EXECUTABLE ###
# This is where you want to put the name of your program or library that you will be compiling

NAME		= libftprintf.a

### DIR ###
# all the dir to neatly keep your .c and .h

DIRSRC		= ./
BONUS_SRC	= fractol_set/
HEAD		= ./ #include/
LIBFT_SRC	= ./
SHARE_SRC	= share/
OBJ_SRC		= #objs/

### TESTER GIT URL ###
# add some git url to your makefile to make your evaluator life easier

TESTER1		= git@github.com:Tripouille/printfTester.git
TESTER2		= git@github.com:paulo-santana/ft_printf_tester.git
TESTER3		=
TESTER4		=

### SOURCE FILE ###
# the name of your .c go here. SRC is for mandatory, BONUS is for the bonus.
# SHARE is for .c file that your mandatory and bonus use. LIBFT is where your specific libft .c file go.

SRC	= ft_printf.c ft_ptoa.c ft_utoa.c ft_xtoa.c ft_putstr_fd.c ft_wrapper.c

BONUS	=

SHARE	=

LIBFT	= ft_bzero.c ft_calloc.c ft_itoa.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c

### PATH ###
# DO NOT CHANGE
SRCS		= ${addprefix ${DIRSRC}, ${SRC}}
BONUS_SRCS	= ${addprefix ${BONUS_SRC}, ${BONUS}}
LIBFT_SRCS	= ${addprefix ${LIBFT_SRC}, ${LIBFT}}
SHARE_SRCS	= ${addprefix ${SHARE_SRC}, ${SHARE}}

### OBJECT FILE ###
# DO NOT CHANGE
#OBJS		= ${SRCS:.c=.o}
#BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
#LIBFT_OBJS	= ${LIBFT_SRCS:.c=.o}
#SHARE_OBJS	= ${SHARE_SRCS:.c=.o}

OBJS        = ${addprefix $(OBJ_SRC),$(SRCS:.c=.o)}
BONUS_OBJS    = ${addprefix $(OBJ_SRC),$(BONUS_SRCS:.c=.o)}
EXRTA_OBJS    = ${addprefix $(OBJ_SRC),$(EXTRA_SRCS:.c=.o)}
LIBFT_OBJS    = ${addprefix $(OBJ_SRC),$(LIBFT_SRCS:.c=.o)}
SHARE_OBJS    = ${addprefix $(OBJ_SRC),$(SHARE_SRCS:.c=.o)}

### COMPILATION ###
# the compilation flag that will we will use for the project

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g

AR      = ar rc


### COLORS ###
# up to your creativity
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### TMP ###
# if needed
MSG = "Upload to git"

### RULES ###
#.c.o:
#	@${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
#	@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

all: ${NAME} #print_option

$(OBJ_SRC)%.o: $(DIRSRC)%.c $(HEAD)$(NAME).h
	@mkdir -p objs
	@${CC} ${CFLAGS} -I${HEAD} -c -o $@ $<
	@echo "$(BLUE)$(CC) $(WHITE)$(notdir $@)$(NOC)"


${NAME}:	${OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}

	@${AR} ${NAME} ${OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@echo "$(GREEN)$@$(NOC)"

bonus:		${BONUS_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@echo "$(GREEN)${BONUS_NAME}$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@${RM} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean	all

tester:
	@echo "$(YELLOW)Testers are not perfect but its good enough$(NOC)"
	git clone ${TESTER1} TESTER1
	git clone ${TESTER2} TESTER2
	git clone ${TESTER3} TESTER3
	git clone ${TESTER3} TESTER4

norm:
	norminette ft*.c

gitpush:
	git add .
	git status
	git commit -m "${MSG}"
	git push

help:
	@clear
	@echo "$(GREEN)Avaibles options:$(NOC)"
	@echo "$(RED)==================$(NOC)"
	@echo "$(RED)| $(YELLOW)make ${NAME} $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make bonus     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make norm      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make tester    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make clean     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make fclean    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make re        $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make help      $(RED)|$(NOC)"
	@echo "$(RED)==================$(NOC)"

.PHONY:		all	clean	fclean	re bonus norm gitpush tester help m

m:
	gcc main.c -L . -lftprintf && ./a.out
