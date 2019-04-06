
# -*- MakeFile -*-

SRCS = srcs/ft_printf.c\
       srcs/ft_parser.c\
       srcs/ft_utilitys.c\
       srcs/ft_handler.c\

OBJ = $(addprefix obj/,$(notdir $(SRCS:.c=.o)))
DEP = $(addprefix .d/,$(notdir $(SRCS:.c=.d)))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
COMPILE.c = $(CC) $(CFLAGS) -c
OUTPUT_OPTION = -MMD -MP -MF $(patsubst %.o,.d/%.d,$(notdir $@)) -o $@

obj/%.o: srcs/%.c
	@ mkdir -p obj/
	@ mdir -p .d/
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

