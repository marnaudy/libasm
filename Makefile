NAME		=	libasm.a

BONUS_NAME	=	libasm_bonus.a

HEADER		=	libasm.h

HEADER_BONUS=	libasm_bonus.h

SRCS		=	src/ft_strlen.asm \
				src/ft_strcpy.asm \
				src/ft_strcmp.asm \
				src/ft_write.asm \
				src/ft_read.asm \
				src/ft_strdup.asm

BONUS_SRCS	=	src_bonus/ft_atoi_base.asm \
				src_bonus/ft_create_elem.asm \
				src_bonus/ft_list_push_front.asm \
				src_bonus/ft_list_size.asm \
				src_bonus/ft_list_sort.asm \
				src_bonus/ft_list_remove_if.asm

OBJS		=	${SRCS:.asm=.o}

BONUS_OBJS	=	${BONUS_SRCS:.asm=.o}

TEST_NAME	=	tester

TEST_HEADER	=	test_src/test.h

TEST_DIR	=	test_src

TEST_SRCS	=	test_src/test_utils.c \
				test_src/test_strlen.c \
				test_src/test_strcpy.c \
				test_src/test_strcmp.c \
				test_src/test_strdup.c \
				test_src/test_read.c \
				test_src/test_write.c \
				test_src/test_atoi_base.c \
				test_src/test_list_utils.c \
				test_src/test_create_elem.c \
				test_src/test_list_push_front.c \
				test_src/test_list_size.c \
				test_src/test_list_sort.c \
				test_src/test_list_remove_if.c \
				test_src/test.c

TEST_OBJS	=	${TEST_SRCS:.c=.o}

ASM			=	nasm

ASM_FLAGS	=	-f elf64

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Wno-restrict

RM			=	rm -f

AR			=	ar

AR_FLAGS	=	rcs

all:			${NAME}

bonus:			${BONUS_NAME}

test:			${TEST_NAME}

${NAME}:		${OBJS}
				${AR} ${AR_FLAGS} ${NAME} ${OBJS}

${TEST_NAME}:	${BONUS_NAME} ${TEST_OBJS}
				${CC} ${CFLAGS} ${TEST_OBJS} ${BONUS_NAME} -o ${TEST_NAME}

${BONUS_NAME}:	${OBJS} ${BONUS_OBJS}
				${AR} ${AR_FLAGS} ${BONUS_NAME} ${OBJS} ${BONUS_OBJS}

%.o:			%.asm
				${ASM} ${ASM_FLAGS} $< -o ${<:.asm=.o}

%.o:			%.c ${HEADER_BONUS} ${TEST_HEADER}
				${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

clean:
				${RM} ${OBJS} ${BONUS_OBJS} ${TEST_OBJS}

fclean:			clean
				${RM} ${NAME} ${BONUS_NAME} ${TEST_NAME}

re:				fclean all

.PHONY:			all bonus test clean fclean re 
