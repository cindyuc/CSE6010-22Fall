#
# Makefile for Assignment 2: single-linked-list; CSE 6010
#

SHELL = /bin/bash
#CC = $(LLVM_PATH)clang
CC = clang
CFLAGS = -O0 -g -Wall -Werror -std=gnu99

# Path to LLVM binaries
LLVM_PATH = /opt/homebrew/bin/
ifneq (,$(wildcard /usr/lib/llvm-7/bin/))
  LLVM_PATH = /usr/lib/llvm-7/bin/
endif

ODIR=obj

DEPS = node.h
OBJ = main.c node.c

# Compile object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# Compile main binaries
singleLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean
clean:
	rm -rf *.o 
