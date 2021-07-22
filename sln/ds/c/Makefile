SRC_DIR = ./sources
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
EXECUTABLE_DIR = $(BUILD_DIR)/exe
CC = gcc
.PHONY=clean,initdir

SOURCEFILES = $(wildcard $(SRC_DIR)/*.cpp) 
SOURCEFILES = $(wildcard $(SRC_DIR)/oopds/*.cpp) 
SOURCEFILES += $(wildcard $(SRC_DIR)/argm/*.cxx)
SOURCEFILES += $(wildcard $(SRC_DIR)/*.c)

default:
	@make argmtest

argmtest: ds
	$(GPP) tests/main.cxx *.o -o a.t
	@./a.t

ds: 
	$(GPP) -c $(SOURCEFILES)
lib: ds
	echo "This target has not been implenmented in this version."
test: ds

play: ds

clean:
	@rm -rf *.o $(BUILD_DIR)
