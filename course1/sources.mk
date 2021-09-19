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

ifeq ($(PLATFORM),HOST)
# Add your Source files to this variable
SOURCES = course1.c \
	data.c \
	main.c \
	memory.c \
	stats.c \

# Add your include paths to this variable
INCLUDES = -Iinclude/common/

else
# Add your Source files to this variable
SOURCES = course1.c \
	data.c \
	main.c \
	memory.c \
	stats.c \
	interrupts_msp432p401r_gcc.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c \

# Add your include paths to this variable
INCLUDES = -Iinclude/common/ \
	   -Iinclude/CMSIS/ \
	   -Iinclude/msp432/

endif