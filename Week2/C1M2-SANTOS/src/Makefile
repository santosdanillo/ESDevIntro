#******************************************************************************
# Copyright (C) 2021 by Danillo - Skynet Terminators
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material nor is Danillo.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Danillo Santos's
# Embedded Systems Intro Week2 Assingment makefile for the cortex-M4 build
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.asm - Builds <FILE>.asm assembly dumped file
#      <FILE>.i - Builds <FILE>.i pre-processed file
#      <FILE>.o - Builds <FILE>.o object file
#      compile-all - Compile all files. Do not link, do not generate executable.
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      PLATFORM - Chooses between HOST and MSP432(default)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides, Architecture Specific Flags
PLATFORM = MSP432
CPU = cortex-m4
LINKER_FILE = ../msp432p401r.lds

# Compiler Flags and Defines
CFLAGS = -Wall -Werror -g -O0 -std=c99
DEPFLAGS = -MT $@ -MMD -MP -MF
LDFLAGS = -Wl,-Map=$(TARGET).map

ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE = size
	CFLAGS += -DHOST \
		  $(INCLUDES)
else
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	LDFLAGS += -T $(LINKER_FILE)
	CFLAGS += -mcpu=$(CPU) \
		  -mthumb \
		  -march=armv7e-m \
		  -mfloat-abi=hard \
		  -mfpu=fpv4-sp-d16 \
		  --specs=nosys.specs \
		  -DMSP432 \
		  $(INCLUDES)

endif

ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)
OBJS = $(SOURCES:.c=.o)
PPPS = $(SOURCES:.c=.i)

# Application
TARGET = c1m2

%.asm: %.c
	$(CC) -S $< $(CFLAGS) -o $@

%.d: %.c
	$(CC) -c $(DEPFLAGS) $@ $(CFLAGS) $<

%.i: %.c
	$(CC) -E $< $(CFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: compile-all
compile-all: $(OBJS)

$(TARGET).out: $(DEPS) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(DEPS) $(OBJS) $(ASMS) $(PPPS) $(TARGET).out $(TARGET).map