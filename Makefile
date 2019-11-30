# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/11/30 23:41:34 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -I libft/include

SRC = ts_print.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

TSRC = test.c
TOBJ = $(addprefix $(ODIR)/,$(TSRC:.c=.o))

NAME = libtouchstone.a

LIB = libft/libft.a

RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
CYAN = \x1b[36m
DEFAULT = \x1b[39m
DEF = $(DEFAULT)

MINUS = $(RED)[-]$(DEF)
PLUS = $(GREEN)[+]$(DEF)
NORM = $(YELLOW)[~]$(DEF)

TIME = $(CYAN)[$$(date +"%H:%M:%S")]$(DEF)

vpath %.c src tests

.PHONY: clean fclean libclean

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@printf "$(TIME) $(PLUS) $(CYAN)$^ $(GREEN)-> $(BLUE)$@$(DEF)\n"
	@libtool -static -o $@ $^

$(LIB):
	@printf "$(TIME) $(NORM) $(YELLOW)make -> $(dir $(LIB))$(DEF)\n"
	@$(MAKE) -C $(dir $(LIB))

test: $(NAME) | $(TOBJ)
	@printf "$(TIME) $(PLUS) $(CYAN)$| $(GREEN)-> $(BLUE)$@$(DEF)\n"
	@$(CC) $(CFLAGS) -L . -ltouchstone -o $@ $|
	@printf "$(TIME) $(NORM) $(YELLOW)./$@$(DEF)\n"
	@./$@

$(ODIR)/%.o: %.c
	@printf "$(TIME) $(PLUS) $(CYAN)$< $(GREEN)-> $(BLUE)$@$(DEF)\n"
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(TIME) $(MINUS) $(RED)$(ODIR)$(DEF)\n"
	@$(RM) -r $(ODIR)

fclean: clean
	@printf "$(TIME) $(MINUS) $(RED)$(NAME)$(DEF)\n"
	@$(RM) $(NAME) test

libclean:
	@printf "$(TIME) $(NORM) $(YELLOW)make fclean -> $(dir $(LIB))$(DEF)\n"
	@$(MAKE) fclean -C $(dir $(LIB))

re: fclean libclean all
