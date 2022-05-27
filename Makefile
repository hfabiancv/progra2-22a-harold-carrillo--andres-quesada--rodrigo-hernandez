# C/C++ Makefile v2.4.0 2021-Nov-16 Jeisson Hidalgo ECCI-UCR CC-BY 4.0

# Compiler and tool flags
CC=gcc
CFLAGS=-Wall -Wextra -std=c11
LINTF=-build/header_guard,-build/include_subdir
LINTC=$(LINTF),-readability/casting
LINTX=$(LINTF),-build/c++11,-runtime/references

# Directories
BIN_DIR=bin
OBJ_DIR=build
DOC_DIR=doc
SRC_DIR=src
TST_DIR=tests

# If src/ dir does not exist, use current directory .
ifeq "$(wildcard $(SRC_DIR) )" ""
	SRC_DIR=.
endif

# Files
DIRS=$(shell find -L $(SRC_DIR) -type d)
APPNAME=$(shell basename $(shell pwd))
HEADERC=$(wildcard $(DIRS:%=%/*.h))
HEADERX=$(wildcard $(DIRS:%=%/*.hpp))
SOURCEC=$(wildcard $(DIRS:%=%/*.c))
SOURCEX=$(wildcard $(DIRS:%=%/*.cpp))
INPUTFC=$(strip $(HEADERC) $(SOURCEC))
INPUTFX=$(strip $(HEADERX) $(SOURCEX))
INPUTCX=$(strip $(INPUTFC) $(INPUTFX))
OBJECTC=$(SOURCEC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTX=$(SOURCEX:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJECTS=$(strip $(OBJECTC) $(OBJECTX))
TESTINF=$(wildcard $(TST_DIR)/input*.txt)
TESTOUT=$(TESTINF:$(TST_DIR)/input%.txt=$(OBJ_DIR)/output%.txt)
INCLUDE=$(DIRS:%=-I%)
DEPENDS=$(OBJECTS:%.o=%.d)
IGNORES=$(BIN_DIR) $(OBJ_DIR) $(DOC_DIR)
EXEFILE=$(BIN_DIR)/cryptarithmetic
EXEARGS=$(strip $(EXEFILE) $(ARGS))
LD=$(if $(SOURCEC),$(CC),$(XC))

# Targets
default: debug
debug: CFLAGS += -g
debug: all
release: CFLAGS += -O3 -DNDEBUG
release: $(EXEFILE)
asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer
asan: debug
msan: CFLAGS += -fsanitize=memory
msan: CC = clang
msan: XC = clang++
msan: debug
tsan: CFLAGS += -fsanitize=thread
tsan: debug
ubsan: CFLAGS += -fsanitize=undefined
ubsan: debug

.PHONY: all
all: bin/cryptarithmetic bin/test

# Cryptarithmetic app
bin/cryptarithmetic: build/cryptarithmetic.o bin/cryptarithms.so bin/matrix.so | bin/.
	$(CC) -g $(CFLAGS) $^ -o $@

build/cryptarithmetic.o: src/cryptarithmetic.c | build/.
	$(CC) -c -g $(CFLAGS) $< -o $@

bin/test: build/test.o bin/cryptarithms.so bin/matrix.so| bin/.
	$(CC) -g $(CFLAGS) $^ -o $@

build/test.o: src/test.c | build/.
	$(CC) -c -g $(CFLAGS) $< -o $@

# Cryptarithms Library
bin/cryptarithms.so: build/cryptarithms.o | bin/.
	$(CC) -shared $^ -o $@

# Matrix Library
bin/matrix.so: build/matrix.o | bin/.
	$(CC) -shared $^ -o $@

build/%.o: src/%.c src/%.h | build/.
	$(CC) -c -fPIC -g $(CFLAGS) $< -o $@


# Create a subdirectory if not exists
.PRECIOUS: %/.
%/.:
	mkdir -p $(dir $@)

# Test cases
.PHONY: test
test: $(EXEFILE) $(TESTOUT)

$(OBJ_DIR)/output%.txt: SHELL:=/bin/bash
$(OBJ_DIR)/output%.txt: $(TST_DIR)/input%.txt $(TST_DIR)/output%.txt
	icdiff --no-headers $(word 2,$^) <($(EXEARGS) < $<)

# Documentation
doc: $(INPUTCX)
	doxygen

# Utility rules
.PHONY: lint run memcheck helgrind gitignore clean instdeps

lint:
ifneq ($(INPUTFC),)
	cpplint --filter=$(LINTC) $(INPUTFC)
endif
ifneq ($(INPUTFX),)
	cpplint --filter=$(LINTX) $(INPUTFX)
endif

clean:
	rm -rf $(IGNORES)

run: $(EXEFILE)
	$(EXEARGS)

memcheck: $(EXEFILE)
	valgrind --tool=memcheck $(EXEARGS)

helgrind: $(EXEFILE)
	valgrind --quiet --tool=helgrind $(EXEARGS)

gitignore:
	echo $(IGNORES) | tr " " "\n" > .gitignore

# Install dependencies (Debian)
instdeps:
	sudo apt install build-essential clang valgrind icdiff doxygen graphviz \
	python3-pip python3-gpg && sudo pip3 install cpplint

help:
	@echo "Usage make [-jN] [VAR=value] [target]"
	@echo "  -jN       Compile N files simultaneously [N=1]"
	@echo "  VAR=value Overrides a variable, e.g CC=mpicc DEFS=-DGUI"
	@echo "  all       Run targets: doc lint [memcheck helgrind] test"
	@echo "  asan      Build for detecting memory leaks and invalid accesses"
	@echo "  clean     Remove generated directories and files"
	@echo "  debug     Build an executable for debugging [default]"
	@echo "  doc       Generate documentation from sources with Doxygen"
	@echo "  gitignore Generate a .gitignore file"
	@echo "  helgrind  Run executable for detecting thread errors with Valgrind"
	@echo "  instdeps  Install needed packages on Debian-based distributions"
	@echo "  lint      Check code style conformance using Cpplint"
	@echo "  memcheck  Run executable for detecting memory errors with Valgrind"
	@echo "  msan      Build for detecting uninitialized memory usage"
	@echo "  release   Build an optimized executable"
	@echo "  run       Run executable using ARGS value as arguments"
	@echo "  test      Run executable against test cases in folder tests/"
	@echo "  tsan      Build for detecting thread errors, e.g race conditions"
	@echo "  ubsan     Build for detecting undefined behavior"
