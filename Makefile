CC = g++
SRC_DIR = ./src
OUT_DIR = ./build
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	OUT_FILE = program
	FILE = gitutils

endif
ifeq ($(UNAME), windows32)
	OUT_FILE = program.exe
	FILE = gitutils.exe
endif

CPPFLAGS=-std=c++17 -static $(SRC_DIR)/program.cpp -o $(OUT_DIR)/$(OUT_FILE)

compile:
	$(CC) $(CPPFLAGS)

install:
	git clone https://github.com/abdulh4ni/GitUtils.git ~/.gitutils
	mkdir ~/.gitutils/bin
	mv build/$(OUT_FILE) ~/.gitutils/bin/$(FILE)

	@echo "You need to add ~/.gitutils/bin to PATH if you haven't already."
	@echo "The config file for gitutils is at ~/.gitutils/src/include/global.h, edit it and recompile the program using `make compile` and then `make install` to apply changes."

