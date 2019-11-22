# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/11/22 18:16:02 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I include
ifeq (${DEBUG},true)
	CFLAGS := -g -fprofile-instr-generate -fcoverage-mapping $(CFLAGS)
endif

SRC = touchstone.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = touchstone.a

define ASCII
 __                           __               __
/\\ \\__                       /\\ \\             /\\ \\__
\\ \\ ,_\\   ___   __  __    ___\\ \\ \\___     ____\\ \\ ,_\\   ___     ___      __
 \\ \\ \\/  / __`\\/\\ \\/\\ \\  /'___\\ \\  _ `\\  /',__\\\\ \\ \\/  / __`\\ /' _ `\\  /'__`\\
  \\ \\ \\_/\\ \\L\\ \\ \\ \\_\\ \\/\\ \\__/\\ \\ \\ \\ \\/\\__, `\\\\ \\ \\_/\\ \\L\\ \\/\\ \\/\\ \\/\\  __/
   \\ \\__\\ \\____/\\ \\____/\\ \\____\\\\ \\_\\ \\_\\/\\____/ \\ \\__\\ \\____/\\ \\_\\ \\_\\ \\____\\
    \\/__/\\/___/  \\/___/  \\/____/ \\/_/\\/_/\\/___/   \\/__/\\/___/  \\/_/\\/_/\\/____/
endef

CRED = \x1b[31m
CGREEN = \x1b[32m
CYELLOW = \x1b[33m
CBLUE = \x1b[34m
CCYAN = \x1b[36m
CDEFAULT = \x1b[39m
CDEF = $(CDEFAULT)

CMINUS = $(CRED)[-]$(CDEF)
CPLUS = $(CGREEN)[+]$(CDEF)
CNORM = $(CYELLOW)[~]$(CDEF)

TIME = $(CCYAN)[$$(date +"%H:%M:%S")]$(CDEF)

vpath %.c src

.PHONY: clean fclean test

all: ascii $(NAME)

export ASCII
ascii:
	@echo "\n$(CYELLOW)$$ASCII$(CDEF)\n"

$(NAME): $(OBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Adding objects to $@...$(CDEF)"
	@$(AR) $@ $^

$(ODIR)/%.o: %.c
	@echo "$(TIME) $(CPLUS) $(CBLUE)Compiling $< to $@...$(CDEF)"
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning object files...$(CDEF)"
	@$(RM) -r $(ODIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning $(NAME)...$(CDEF)"
	@$(RM) $(NAME)

re: fclean all
