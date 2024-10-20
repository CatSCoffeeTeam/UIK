BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

all:

$(INC_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@