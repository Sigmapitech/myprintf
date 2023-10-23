##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## Makefile
##

.POSIX:
.SUFFIXES:

CC ?= gcc

CFLAGS += -std=gnu11

CFLAGS += -fno-builtin
CFLAGS += -fno-tree-loop-distribute-patterns
CFLAGS += -pipe

CFLAGS += -U_FORTIFY_SOURCE -Wformat=2
CFLAGS += -O2 -march=native -mtune=native

CFLAGS += -Waggregate-return
CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Winit-self -Wredundant-decls
CFLAGS += -Winline -Wundef -Wshadow
CFLAGS += -Wstrict-overflow=2
CFLAGS += -Wunreachable-code
CFLAGS += -Wwrite-strings

CFLAGS += -iquote .

include sources.mk
vpath %.c $(VPATH)

BUILD_DIR := .build

LIB := libmy.a
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

RM ?= rm -f
AM ?= ar

all: $(LIB)
.PHONY: all

$(LIB): $(OBJ)
	$(AR) rc $@ $^

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(SRC:.c=.gcda)
	$(RM) $(SRC:.c=.gcno)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

.PHONY: clean fclean

re: fclean
	$(MAKE) all

.PHONY: re
