##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## Makefile
##

.POSIX:
.SUFFIXES:

CC := gcc
CFLAGS += -std=c99

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
UNIT := unit_tests

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
TOBJ := $(TSRC:%.c=$(BUILD_DIR)/%.o)

TFLAGS := -L .
TFLAGS += -lasan -lmy -lcriterion

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
	$(RM) $(OBJ) $(TOBJ)

fclean: clean
	$(RM) $(LIB)
	$(RM) -r $(BUILD_DIR)

.PHONY: clean fclean

re: fclean
	$(MAKE) all

.PHONY: re

NO_COV ?= 0

ifeq ($(NO_COV),0)
$(UNIT): CFLAGS += -g3 --coverage -fprofile-arcs
endif
$(UNIT): $(LIB) $(TOBJ)
	$(CC) -g3 $(CFLAGS) -o $@ $(TOBJ) $(TFLAGS)

tests_run: $(UNIT)
	./$^

.PHONY: tests_run

cov: fclean
	$(MAKE) tests_run
	gcovr --exclude tests
	gcovr --exclude tests --branch

.PHONY: cov
