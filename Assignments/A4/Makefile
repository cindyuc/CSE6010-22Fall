#
# Makefile for Assignment 4: single-linked-list; CSE 6010
#

# SHELL = /bin/bash
CC = clang
CFLAGS = -O0 -g -Wall -Werror -std=gnu99

# # Path to LLVM binaries
# LLVM_PATH = /opt/homebrew/bin/
# ifneq (,$(wildcard /usr/lib/llvm-7/bin/))
#   LLVM_PATH = /usr/lib/llvm-7/bin/
# endif

ODIR=obj

DEPS = sort.h flights_io.h
OBJ = airportmain.c sort.c flights_io.c

# Compile object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# Compile main binaries
airport: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean
clean:
	rm -rf *.o 
	rm -rf *.dSYM
