#Main Makefile
CC = gcc
CFLAGS = -g -Wall -MMD

#Binary
ifeq ($(OS),Windows_NT)
    BIN = main.exe
else
	BIN = main
endif

#Directories
IDIR = ./include
SDIR = ./src
ODIR = ./obj

#Paths
INCLUDE_PATHS = -I$(IDIR) `pkg-config --cflags sdl2`

#Libraries
LIBRARIES+= `pkg-config --libs sdl2` -lwinmm

#Compilation line
COMPILE = $(CC) $(CFLAGS) $(INCLUDE_PATHS)

#FILEs
#---------------Include---------------#
INCS = $(wildcard $(IDIR)/*.h) $(wildcard $(IDIR)/*/*.h)

#---------------Source----------------#
SRCS = $(wildcard $(SDIR)/*.c) $(wildcard $(SDIR)/*/*.c)

#---------------Object----------------#
OBJS = $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)
#-------------Dependency--------------#
DEPS = $(SRCS:$(SDIR)/%.c=$(ODIR)/%.d)

all: $(OBJS)
	$(COMPILE) $(OBJS) main.c -o $(BIN) $(LIBRARIES)

# Include all .d files
-include $(DEPS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(COMPILE) -MMD -c $< -o $@ $(LIBRARIES)

.PHONY : clean
clean :
	-rm $(BIN) $(OBJS) $(DEPS)
