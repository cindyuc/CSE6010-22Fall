#
# Makefile for Assignment 5: Diffusion; CSE 6010
#

# SHELL = /bin/bash
CC = gcc
CFLAGS = -O0 -fopenmp -g -Wall -Werror -std=gnu99
# LDFLAGS = -fopenmp

ODIR=obj

DEPS = 
OBJ = diffusion.c 

RM = rm -f

# Ask the number of cores to be used in the parallelization:
CORES := $(shell bash -c 'read -p "Enter the number of threads for parallelization: " pwd; echo $$pwd') 


# Compile object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# Compile main binaries
diffusion: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	export OMP_NUM_THREADS=$(CORES)


.PHONY: clean
clean:
	@$(RM) $(OBJECTS) *.o 
	@echo "Cleanup complete!"