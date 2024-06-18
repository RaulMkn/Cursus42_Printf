# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 19:11:54 by rmakende          #+#    #+#              #
#    Updated: 2024/06/12 12:41:22 by rmakende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of your library
NAME = libftprintf.a
# The C compiler to use
CC = gcc
# The archiver to use
AR = ar
# The flags to use with the archiver
ARFLAGS = -rcs
# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror

COMPILE = ${CC} ${CFLAGS}


# The command to remove files
RM = rm -f
# A list of all .c files in the current directory
SRCS = ft_printf.c\
       ft_putexa_fd.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putpointer_fd.c\
	   ft_putnbr_fd.c\
	   ft_putexa_fd.c\
	   ft_putunsigned_fd.c\
	   
# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# The default target - builds the library
all: $(NAME)
# A rule to build the library from the .o files
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)


%.o:%.c	
	$(COMPILE) -c $< -o $@

	
# A rule to remove all .o files
clean:
	$(RM) $(OBJS)
# A rule to remove all .o files and the library
fclean: clean
	$(RM) $(NAME)
# A rule to rebuild everything from scratch
re: fclean all
# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean