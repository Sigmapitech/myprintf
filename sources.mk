##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## sources.mk
##
VPATH += .
SRC += vdprintf.c
SRC += printf.c
SRC += utils.c

VPATH += base
SRC += my_strnlen.c
SRC += my_stridx.c

VPATH += handlers
SRC += conversion_base.c
SRC += conversion_extra.c
SRC += conversion_float.c
SRC += conversion_numerical.c

VPATH += tests
TSRC += test_setup.c

VPATH += tests/handlers
TSRC += test_handler_string.c
TSRC += test_handler_string_edge_cases.c
TSRC += test_conversion_func.c
TSRC += test_parse_hl.c
TSRC += test_parse_hl_width.c
TSRS += test_print_literal.c
