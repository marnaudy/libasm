NAME        =   libasm.a

HEADER		=	libasm.h

SRCS        =   ft_strlen.asm \
				ft_strcpy.asm \
				ft_write.asm \
				ft_read.asm

OBJS        =   ${SRCS:.asm=.o}

TEST_NAME   =   test

TEST_SRCS   =   test.c

TEST_OBJS   =   ${TEST_SRCS:.c=.o}

ASM         =   nasm

ASM_FLAGS   =   -f elf64

CC          =   gcc

CFLAGS      =   -Wall -Wextra -Werror

RM          =   rm -f

AR          =   ar

AR_FLAGS    =   rcs

all:        ${NAME}

${NAME}:    ${OBJS}
			${AR} ${AR_FLAGS} ${NAME} ${OBJS}

%.o:		%.asm
			${ASM} ${ASM_FLAGS} $< -o ${<:.asm=.o}

%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

test:       ${NAME} ${TEST_OBJS}
			${CC} ${CFLAGS} ${TEST_OBJS} ${NAME} -o ${TEST_NAME}

clean:
			${RM} ${OBJS} ${TEST_OBJS}

fclean:     clean
			${RM} ${NAME} ${TEST_NAME}

re:         fclean all

.PHONY:     all clean fclean re 
