# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 17:14:51 by alfiumic          #+#    #+#              #
#    Updated: 2019/04/09 17:56:59 by alfiumic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

SRCDIR = ./srcs/

SRCS = ft_printf.c\
       ft_handler.c\
       ft_parser.c\
       ft_print_binary.c\
       ft_print_char.c\
       ft_print_date.c\
       ft_printf_core.c\
       ft_print_float.c\
       ft_printf_signedtostr.c\
       ft_printf_unsignedtostr_base.c\
       ft_print_noconv.c\
       ft_print_scientific.c\
       ft_print_signed_decimal.c\
       ft_print_string.c\
       ft_print_unsigned_decimal.c\
       ft_print_unsigned_hexa.c\
       ft_print_unsigned_octal.c\
       ft_print_wchar.c\
       ft_print_wstring.c\
       ft_utilitys.c\

LIBOBJS = ./libft/obj/ft_bzero.o \
	  ./libft/obj/ft_isascii.o \
	  ./libft/obj/ft_isdigit.o \
	  ./libft/obj/ft_itoa.o \
	  ./libft/obj/ft_max.o \
	  ./libft/obj/ft_memalloc.o \
	  ./libft/obj/ft_memset.o \
	  ./libft/obj/ft_memcpy.o \
	  ./libft/obj/ft_min.o \
	  ./libft/obj/ft_putchar.o \
	  ./libft/obj/ft_putstr.o \
	  ./libft/obj/ft_putwchar.o \
	  ./libft/obj/ft_strchr.o \
	  ./libft/obj/ft_strnew.o \
	  ./libft/obj/ft_abs.o \
	  ./libft/obj/ft_atoi.o \
	  ./libft/obj/ft_strcat.o \
	  ./libft/obj/ft_strcpy.o \
	  ./libft/obj/ft_strlen.o \
	  ./libft/obj/ft_memmove.o \

HEADERS = ./includes/ft_printf.h \
	  ./includes/ft_printf_internal.h \
	  ./includes/ft_printf_handler.h


NAME = libftprintf.a
OBJECTS = $(SRCS:.c=.o)
INCLUDES = -I ./libft/include/ -I ./includes
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c



.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) ./libft/libft.a 
	@ echo -n "Creating library: $(NAME) "
	@ ar rc $(NAME) $(OBJECT) $(LIBOBJS)
	@ ranlib $(NAME)
	@ echo "Finished"

%.o: $(SRCDIR)%.c $(HEADERS)
	@ echo "compiling $<"
	@ $(CC) $(CFLAGS) $< $(INCLUDES)

./libft/libft.a:
	@ make -C ./libft/

clean:
	@ make -C ./libft/ clean
	@ rm -f $(OBJECTS)
	@ echo "Clean: done"

fclean: clean
	@ make -C ./libft/ fclean
	@ rm -f $(NAME)
	@ echo "Fclean: done"

re: fclean all
	@ echo "Rebuild: done"
