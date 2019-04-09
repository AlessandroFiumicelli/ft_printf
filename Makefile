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

SRCS = srcs/ft_printf.c\
       srcs/ft_parser.c\
       srcs/ft_utilitys.c\
       srcs/ft_handler.c\
	   srcs/ft_print_binary.c\
	   srcs/ft_print_char.c\
	   srcs/ft_print_date.c\
	   srcs/ft_print_float.c\
	   srcs/ft_print_noconv.c\
	   srcs/ft_print_scientific.c\
	   srcs/ft_print_signed_decimal.c\
	   srcs/ft_print_string.c\
	   srcs/ft_print_unsigned_decimal.c\
	   srcs/ft_print_unsigned_hexa.c\
	   srcs/ft_print_unsigned_octal.c\
	   srcs/ft_print_wchar.c\
	   srcs/ft_print_wstring.c\

OBJ = $(addprefix obj/,$(notdir $(SRCS:.c=.o)))
DEP = $(addprefix .d/,$(notdir $(SRCS:.c=.d)))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
COMPILE.c = $(CC) $(CFLAGS) -c
OUTPUT_OPTION = -MMD -MP -MF $(patsubst %.o,.d/%.d,$(notdir $@)) -o $@

obj/%.o: srcs/%.c
	@ mkdir -p obj/
	@ mkdir -p .d/
	$(COMPILE.c) $(OUTPUT_OPTION) $< -I./includes

NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ /bin/echo -n "Creating library => "
	@ if ar rc $(NAME) $(OBJ) ; \
		then /bin/echo ✅ ; \
		else /bin/echo ❌ ; fi
	@ ranlib $(NAME)
	@ /bin/echo "Finished"

clean:
	@ /bin/echo -n "Deleting Object file => "
	@ if /bin/rm -rf .d && /bin/rm -rf obj/; \
		then /bin/echo ✅ ; \
		else /bin/echo ❌ ; fi
	@ /bin/echo "Finished"

fclean: clean
	@ /bin/echo -n "Deleting library => "
	@ if /bin/rm -rf $(NAME); \
		then /bin/echo ✅ ; \
		else /bin/echo ❌ ; fi
	@ /bin/echo "Finished"

re: fclean all

-include $(DEP)

