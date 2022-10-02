CC = g++
SRC_DIR = ./src
OUT_DIR = ./build
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	OUT_FILE = program
endif
ifeq ($(UNAME), windows32)
	OUT_FILE = program.exe
endif

CPPFLAGS=-std=c++17 -static $(SRC_DIR)/program.cpp -o $(OUT_DIR)/$(OUT_FILE)

compile:
	$(CC) $(CPPFLAGS)