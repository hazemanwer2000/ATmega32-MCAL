
#############################################################
# 
# Description: Makefile, for 'ATmega32' target uController.
# Author: Eng. Hazem Anwer
# Github: https://github.com/hazemanwer2000
# 
#############################################################



# Make workspace (usually '.make')
MAKE_WS := .make

# INCLUDE: Python library
include $(MAKE_WS)/py.mk

# Whitespace-separated list of source files
SRCS := $(call GET_FILES,.,.c)

# Whitespace-separated list of directories, containing header files, prefixed with '-I'
HDR_DIRS := $(addprefix -I,$(call GET_DIRS,.,.h))

# Mapping of 'SRCS' to object and dependency files
OBJS := $(OBJS:.c=.o)
DEPS := $(SRCS:.c=.d)



# 'SPECS' Compiler Option, with target-specific path
SPECS := -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32"

# Compiler command (or, path)
CC := avr-gcc

# Object-copy (or, translator, e.g: '.elf' binary to '.hex' ASCII) command (or, path)
OBJCPY := avr-objcopy

# Compiler, pre-processor, and object-copy flags
CFLAGS := -w -mmcu=atmega32 -O0 -std=gnu99 $(SPECS)
PPFLAGS := $(HDR_DIRS)
CPY_FLAGS := -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures



TARGET := main.elf

.PHONY: clean null

null:

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(PPFLAGS) $^ -o $@
	$(OBJCPY) $(CPY_FLAGS) $@ $(@:.elf=.hex)

clean:
	del $(TARGET) $(TARGET:.elf=.hex) $(DEPS) $(OBJS)
	
%.d: %.c
	$(CC) $(PPFLAGS) -MM -MT $^ $^ > $@
	$(PY_APPEND_LINE) -f $@ -l "$(CC) -c $(PPFLAGS) $(CFLAGS) $^ -o $(@:.d=.o)"

#include $(DEPS)
