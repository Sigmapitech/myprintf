##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## sources.mk
##
VPATH += .
SRC += vdprintf.c
SRC += parse_specifier.c
SRC += printf.c
SRC += utils.c

VPATH += base
SRC += my_intlen.c
SRC += my_putnbr.c
SRC += my_putnbr_base.c
SRC += my_stridx.c
SRC += my_strncmp.c
SRC += my_strnlen.c

VPATH += handlers
SRC += conversion_base.c
SRC += conversion_extra.c
SRC += conversion_float.c
SRC += conversion_numerical.c

VPATH += tests
TSRC += test_my_intlen.c
TSRC += test_my_putnbr.c
TSRC += test_my_putnbr_base.c
TSRC += test_my_putnbr_base_16.c
TSRC += test_my_stridx.c
TSRC += test_my_strnlen.c
TSRC += test_printf.c
TSRC += test_setup.c
