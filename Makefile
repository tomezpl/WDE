# WDE makefile

# It is advised to build WDE with g++.
# g++ 4.8 should work fine.
# The CC variable will be used to define the compiler.
CC=g++

# 32-bit flags for CC are defined by the x86 variable
# Likewise, 64-bit will be x86_64 (or x64 as an alias)
x86=-m32 -static-libstdc++

# Prefix for the WDE binary files
# This is to separate them from shared libraries in ./bin/
BIN_PREFIX=wde*

# SFML libraries
# These will be added when wde is linked
SFML_LIB= -lsfml-graphics -lsfml-system -lsfml-window

# Awesomium libraries
# These will be added when wde is linked
AWE_LIB = -lawesomium-1-7

all: wde

wde: main.o renderer.o
	@echo Linking object files into WDE binary...
	$(CC) -o./bin/wde ./obj/main.o ./obj/renderer.o $(SFML_LIB) $(AWE_LIB) $(x86)
	@echo Finished linking. See CC output if there are any errors.
    
main.o: ./src/main.cc
	@echo Compiling main WDE module...
	$(CC) -c -o./obj/main.o ./src/main.cc $(x86)
	@echo Main WDE module compiled. See CC output if there are any errors.

renderer.o: ./src/renderer.cc
	@echo Compiling WDE renderer module...
	$(CC) -c -o./obj/renderer.o ./src/renderer.cc $(x86)
	@echo WDE renderer module compiled. See CC output if there are any errors.

clean:
	@echo Cleaning WDE binaries...
	rm ./bin/$(BIN_PREFIX)*
	rm ./obj/*
	@echo Finished cleaning WDE binaries.