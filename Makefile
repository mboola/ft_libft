#-----NAME OF STATIC LIBRARY
NAME	=	libft.a

#-----MAIN DIRECTORIES
SRC		=	src
INCLUDE	=	include
OBJDIR	=	objects

#-----COMPILATION FLAGS
CC				=	cc
HEADERS			=	-I./${INCLUDE}
CFLAGS			=	-Wall -Wextra -Werror ${HEADERS}
OPTIMIZATION	=	-O3
DEBUG			=	#-g

#-----FILES
CHECKERS_DIR	=	${SRC}/ft_checkers
CHECKERS_FILE	=	${CHECKERS_DIR}/ft_isalnum.c ${CHECKERS_DIR}/ft_isalpha.c ${CHECKERS_DIR}/ft_isascii.c \
					${CHECKERS_DIR}/ft_isdigit.c ${CHECKERS_DIR}/ft_isprint.c ${CHECKERS_DIR}/ft_isprint.c \
					${CHECKERS_DIR}/ft_tolower.c ${CHECKERS_DIR}/ft_toupper.c    

CONVERTERS_DIR	=	${SRC}/ft_converters
CONVERTERS_FILE	=	${CONVERTERS_DIR}/ft_atoi.c ${CONVERTERS_DIR}/ft_itoa.c

DOLST_DIR		=	${SRC}/ft_dolst
DOLST_FILE		=	${DOLST_DIR}/ft_dolstadd_back.c ${DOLST_DIR}/ft_dolstadd_front.c \
					${DOLST_DIR}/ft_dolstclear.c ${DOLST_DIR}/ft_dolstdelone.c \
					${DOLST_DIR}/ft_dolstextract_back.c ${DOLST_DIR}/ft_dolstextract_front.c \
					${DOLST_DIR}/ft_dolstlast.c ${DOLST_DIR}/ft_dolstnew.c

LST_DIR			=	${SRC}/ft_lst
LST_FILE		=	${LST_DIR}/ft_lstadd_back.c ${LST_DIR}/ft_lstadd_front.c ${LST_DIR}/ft_lstclear.c \
					${LST_DIR}/ft_lstdelone.c ${LST_DIR}/ft_lstiter.c ${LST_DIR}/ft_lstlast.c \
					${LST_DIR}/ft_lstmap.c ${LST_DIR}/ft_lstnew.c ${LST_DIR}/ft_lstsize.c

MEM_DIR			=	${SRC}/ft_mem
MEM_FILE		=	${MEM_DIR}/ft_bzero.c ${MEM_DIR}/ft_calloc.c ${MEM_DIR}/ft_memchr.c \
					${MEM_DIR}/ft_memcmp.c ${MEM_DIR}/ft_memcpy.c ${MEM_DIR}/ft_memmove.c \
					${MEM_DIR}/ft_memset.c

PUT_FD_DIR		=	${SRC}/ft_put_fd
PUT_FD_FILE		=	${PUT_FD_DIR}/ft_putchar_fd.c ${PUT_FD_DIR}/ft_putendl_fd.c \
					${PUT_FD_DIR}/ft_putnbr_fd.c ${PUT_FD_DIR}/ft_putstr_fd.c

STR_DIR			=	${SRC}/ft_str
STR_FILE		=	${STR_DIR}/ft_split.c ${STR_DIR}/ft_strchr.c ${STR_DIR}/ft_strdup.c \
					${STR_DIR}/ft_striteri.c ${STR_DIR}/ft_strjoin.c ${STR_DIR}/ft_strlcat.c \
					${STR_DIR}/ft_strlcpy.c ${STR_DIR}/ft_strlen.c ${STR_DIR}/ft_strmapi.c \
					${STR_DIR}/ft_strncmp.c ${STR_DIR}/ft_strnstr.c ${STR_DIR}/ft_strrchr.c \
					${STR_DIR}/ft_strtrim.c ${STR_DIR}/ft_substr.c     

FILES	=	${CHECKERS_FILE} ${CONVERTERS_FILE} ${DOLST_FILE} ${LST_FILE} ${MEM_FILE} \
			${PUT_FD_FILE} ${STR_FILE}

LIBFT_HEADER	=	libft.h

OBJS = ${FILES:.c=.o}

%.o: %.c ${LIBFT_HEADER} Makefile
	${CC} ${CFLAGS} ${OPTIMIZATION} -c $< -o $@ ${DEBUG}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
