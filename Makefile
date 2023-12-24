#-----NAME OF STATIC LIBRARY
NAME	=	libft.a

#-----MAIN DIRECTORIES
SRC		=	src
INCLUDE	=	include
OBJ_DIR	=	objects

#-----COMPILATION FLAGS
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
HEADERS			=	-I./${INCLUDE}
OPTIMIZATION	=	#-O3
DEBUG			=	#-g

#-----FILES
LIBFT_HEADER	=	${INCLUDE}/libft.h

CHECKERS_DIR	=	${SRC}/ft_checkers
CHECKERS_FILE	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_isprint.c ft_tolower.c ft_toupper.c    

CONVERTERS_DIR	=	${SRC}/ft_converters
CONVERTERS_FILE	=	ft_atoi.c ft_itoa.c

DOLST_DIR		=	${SRC}/ft_dolst
DOLST_FILE		=	ft_dolstadd_back.c ft_dolstadd_front.c ft_dolstclear.c ft_dolstdelone.c \
					ft_dolstextract_back.c ft_dolstextract_front.c ft_dolstlast.c ft_dolstnew.c

LST_DIR			=	${SRC}/ft_lst
LST_FILE		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
					ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

MEM_DIR			=	${SRC}/ft_mem
MEM_FILE		=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c

PRINTF_DIR		=	${SRC}/ft_printf
PRINTF_FILE		=	ft_printf.c

PUT_FD_DIR		=	${SRC}/ft_put_fd
PUT_FD_FILE		=	ft_putchar_err.c ft_putendl_err.c ft_putnbr_err.c ft_putnbr_long_err.c \
					ft_putptr_err.c ft_putstr_err.c ft_putunsnbr_err.c

STR_DIR			=	${SRC}/ft_str
STR_FILE		=	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
					ft_strtrim.c ft_substr.c     

SRC_FILES		=	${addprefix $(CHECKERS_DIR)/,$(CHECKERS_FILE)} \
					$(addprefix $(CONVERTERS_DIR)/,$(CONVERTERS_FILE)) \
					$(addprefix $(DOLST_DIR)/,$(DOLST_FILE)) \
					$(addprefix $(LST_DIR)/,$(LST_FILE)) \
					$(addprefix $(MEM_DIR)/,$(MEM_FILE)) \
					$(addprefix $(PRINTF_DIR)/,$(PRINTF_FILE)) \
					$(addprefix $(PUT_FD_DIR)/,$(PUT_FD_FILE)) \
					$(addprefix $(STR_DIR)/,$(STR_FILE))

#-----RULE TO GET THE .O COMPILED
OBJ_FILES = ${patsubst %.c,${OBJ_DIR}/%.o,${notdir ${SRC_FILES}}}

${OBJ_DIR}/%.o: ${SRC}/*/%.c ${LIBFT_HEADER} Makefile
	${CC} ${CFLAGS} ${HEADERS} ${OPTIMIZATION} -c $< -o $@ ${DEBUG}

#-----MAKE RULE
all: ${OBJ_DIR} ${NAME}

${NAME}: ${OBJ_FILES}
	@echo "Creating static library file."
	@ar -rcs $@ $^

#-----RULE TO CREATE THE DIRECTORY OF THE OBJECT FILES
${OBJ_DIR}:
	@echo "Creating objects file directory."
	@mkdir -p $@

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	@if [ -d ${OBJ_DIR} ]; \
	then \
        rmdir ${OBJ_DIR}; \
    fi
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
