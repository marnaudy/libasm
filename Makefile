NAME        =   libasm.a

HEADER		=	libasm.h

SRCS        =   src/ft_strlen.asm \
				src/ft_strcpy.asm \
				src/ft_strcmp.asm \
				src/ft_write.asm \
				src/ft_read.asm

OBJS        =   ${SRCS:.asm=.o}

TEST_NAME   =   test

TEST_HEADER =	test_src/test.h

TEST_DIR	=	test_src

TEST_SRCS   =   test_src/test_utils.c \
				test_src/test_strlen.c \
				test_src/test_strcpy.c \
				test_src/test_strcmp.c \
				test_src/test.c

TEST_OBJS   =   ${TEST_SRCS:.c=.o}

ASM         =   nasm

ASM_FLAGS   =   -f elf64

CC          =   gcc

CFLAGS      =   -Wall -Wextra -Werror -Wno-restrict

RM          =   rm -f

AR          =   ar

AR_FLAGS    =   rcs

all:        ${NAME}

${NAME}:    ${OBJS}
			${AR} ${AR_FLAGS} ${NAME} ${OBJS}

%.o:		%.asm
			${ASM} ${ASM_FLAGS} $< -o ${<:.asm=.o}

%.o:		%.c ${HEADER} ${TEST_HEADER}
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

test:       ${NAME} ${TEST_OBJS}
			${CC} ${CFLAGS} ${TEST_OBJS} ${NAME} -o ${TEST_NAME}

clean:
			${RM} ${OBJS} ${TEST_OBJS}

fclean:     clean
			${RM} ${NAME} ${TEST_NAME}

re:         fclean all

.PHONY:     all clean fclean re 
