#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i      - Builds <FILE>.i preprocessed output file
#      <PROJECT>.asm - Builds <PROJECT>.asm assembly output file
#      <FILE>.asm    - Builds <FILE>.asm assembly output file
#      <FILE>.o      - Builds <FILE>.o object file
#      compile-all   - Compiles all object files, but DOES NOT link
#      build         - Builds and links all source files
#      clean         - Removes all generated files
#
# Platform Overrides:
#      PLATFORM - Target platform (HOST, MSP432)
#
#------------------------------------------------------------------------------

TARGET = c1fa

# Platform Overrides
PLATFORM = HOST

include sources.mk

# Architectures Specific Flags
ifeq ($(PLATFORM),HOST)
else ifeq ($(PLATFORM),MSP432)
	LINKER_FILE = ./msp432p401r.lds
	CPU         = cortex-m4
	ARCH        = thumb
	SPECS       = nosys.specs
else
$(error "Unsupported platform")
endif

# Tool Selection
ifeq ($(PLATFORM),HOST)
	SIZE    = size
	OBJDUMP = objdump
else ifeq ($(PLATFORM),MSP432)
	SIZE    = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
else
$(error "Unsupported platform")
endif

# Compiler Flags and Defines
CFLAGS   = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) -MMD -DVERBOSE -DCOURSE1
LDFLAGS  = -Wl,-Map=$(TARGET).map
CPPFLAGS = $(INCLUDES)

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS += -T $(LINKER_FILE)
	CFLAGS  += -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
else
$(error "Unsupported platform")
endif

# Preprocessed Outputs
PPS  = $(SOURCES:.c=.i)
# Assembly Outputs
ASMS = $(SOURCES:.c=.asm)
# Object Files
OBJS = $(SOURCES:.c=.o)
# Dependancy FIles
DEPS = $(SOURCES:.c=.d)

# Preprocessor Output Target
%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -E $^ -o $@

# Project Executable Assembly Output Target
$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -D $< > $(TARGET).asm

# Assembly Output Target
%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -S $^ -o $@

# Object File Target
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $^ -o $@

# Compile All, Don't Link
.PHONY: compile-all
compile-all: $(OBJS)

# Build Full Executable
.PHONY: build
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) $@

# Remove Generated Files
.PHONY: clean
clean:
	# Platform dependent clean
	rm -f $(PPS) $(ASMS) $(OBJS) $(DEPS) $(TARGET).out $(TARGET).map $(TARGET).asm
