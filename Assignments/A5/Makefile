#
# Makefile for Assignment 5: Diffusion; CSE 6010
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

DEPS = 
OBJ = diffusion.c 

# Compile object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# Compile main binaries
diffusion: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean
clean:
	rm -rf *.o 