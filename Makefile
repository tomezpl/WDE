# WDE makefile

# It is advised to build WDE with g++.
# g++ 4.8 should work fine.
# The CC variable will be used to define the compiler.
CC=g++ -std=c++11

# 32-bit flags for CC are defined by the x86 variable
# Only use this flag if you're on x86_64 (64-bit) and you need to compile in 32-bit.
# It is not advised to use this variable. Use a 32-bit virtual machine to build instead.
x86=-m32 -static-libstdc++

# GTK headers
# These will be added when objects (.o files) are compiled and linked
GTK_DEV=`pkg-config --cflags gtk+-3.0 webkit2gtk-3.0`

# GTK libraries
# These will only be added when objects are linked into program binaries
GTK_LIB=`pkg-config --libs gtk+-3.0 webkit2gtk-3.0`

all: createdirs wdesktop

createdirs:
	mkdir ./obj
	mkdir ./bin

wdesktop: wdesktop.o renderer.o htmlsource.o
	@echo Linking object files into WDE wdesktop binary...
	$(CC) -o./bin/wdesktop ./obj/wdesktop.o ./obj/renderer.o ./obj/htmlsource.o $(GTK_DEV) $(GTK_LIB)
	@echo Finished linking. See CC output if there are any errors.

wdesktop.o: ./src/wdesktop.cc
	@echo Compiling main WDE desktop module...
	$(CC) -c -o./obj/wdesktop.o ./src/wdesktop.cc $(GTK_DEV)
	@echo Main WDE module compiled. See CC output if there are any errors.

renderer.o: ./src/renderer.cc
	@echo Compiling WDE renderer module...
	$(CC) -c -o./obj/renderer.o ./src/renderer.cc $(GTK_DEV)
	@echo WDE renderer module compiled. See CC output if there are any errors.

htmlsource.o: ./src/htmlsource.cc
	@echo Compiling WDE HTML data source module...
	$(CC) -c -o./obj/htmlsource.o ./src/htmlsource.cc $(GTK_DEV)
	@echo WDE HTML data source module compiled. See CC output if there are any errors.

clean:
	@echo Cleaning WDE binaries...
	rm --recursive -f ./bin/
	rm --recursive -f ./obj/
	@echo Finished cleaning WDE binaries.
