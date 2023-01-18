
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
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)



# Compiler command (or, path)
CC := avr-gcc

# Object-copy (or, translator, e.g: '.elf' binary to '.hex' ASCII) command (or, path)
OBJCPY := avr-objcopy



# Compiler Optimization Options
OPTIMIZE := -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums

# Compiler Option, related to target uController (ATmega32)
SPECS := -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32"



# Pre-processor, compiler, linker and object-copy flags
CFLAGS := -w -std=gnu99 $(SPECS) $(OPTIMIZE)
PPFLAGS := $(HDR_DIRS)
LDFLAGS := -Wl,--gc-sections
CPY_FLAGS := -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures



# Name of target executable file
TARGET := main.elf

.PHONY: clean

$(TARGET): $(OBJS)
	$(CC) $(PPFLAGS) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(OBJCPY) $(CPY_FLAGS) $@ $(@:.elf=.hex)

clean:
	$(PY_DEL) $(TARGET) $(TARGET:.elf=.hex) $(DEPS) $(OBJS)

%.d: %.c
	$(CC) $(PPFLAGS) -MM -MT $(@:.d=.o) $^ > $@
	$(PY_APPEND_CMD) $@ $(CC) -c $(PPFLAGS) $(CFLAGS) $^ -o $(@:.d=.o)

-include $(DEPS)
