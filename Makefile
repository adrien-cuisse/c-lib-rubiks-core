
CC=gcc

# Common structure
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
LIB_DIR=lib
TESTS_DIR=tests

# Target and versioning
LIB_NAME=rubiks-core
LIB_MAJOR_VERSION=0
LIB_MINOR_VERSION=1
LIB_PATCH_VERSION=0
LIB_LINKER_NAME=lib$(LIB_NAME).so
LIB_SONAME=$(LIB_LINKER_NAME).$(LIB_MAJOR_VERSION)
LIB_REALNAME=$(LIB_SONAME).$(LIB_MINOR_VERSION).$(LIB_PATCH_VERSION)

# Release sources compilation
RELEASE_SRC=$(shell find $(SRC_DIR)/ -type f -name '*.c')
RELEASE_OBJ=$(subst $(SRC_DIR),$(OBJ_DIR),$(RELEASE_SRC:.c=.o))
RELEASE_CFLAGS=-fpic -O3 -Wall -Wextra -Werror -ansi -pedantic -fvisibility=hidden
RELEASE_LDFLAGS=-fpic -shared -Wl,-soname,$(LIB_SONAME)

# Tests only structure
TESTS_SRC_DIR=$(addprefix $(TESTS_DIR)/,$(SRC_DIR))
TESTS_OBJ_DIR=$(addprefix $(TESTS_DIR)/,$(OBJ_DIR))
TESTS_BIN_DIR=$(addprefix $(TESTS_DIR)/,$(BIN_DIR))

# Test utils (assertions, helpers), which won't generate binaries
TESTS_UTILS_SRC=$(addprefix $(TESTS_SRC_DIR)/,utils.c)
TESTS_UTILS_OBJ=$(subst $(TESTS_SRC_DIR),$(TESTS_OBJ_DIR),$(TESTS_UTILS_SRC:.c=.o))

# Test sources compilation
TESTS_SRC=$(shell find $(TESTS_SRC_DIR) -type f -name '*.c')
TESTS_SRC:=$(filter-out $(TESTS_UTILS_SRC),$(TESTS_SRC))
TESTS_OBJ=$(subst $(TESTS_SRC_DIR),$(TESTS_OBJ_DIR),$(TESTS_SRC:.c=.o))
TESTS_CFLAGS=$(subst -ansi,,$(RELEASE_CFLAGS)) # Criterion is not C89 compliant
TESTS_LDFLAGS=-lcriterion -L$(LIB_DIR)/ -l$(LIB_NAME)
TESTS_BINS=$(subst $(TESTS_SRC_DIR),$(TESTS_BIN_DIR),$(TESTS_SRC:.c=))


default: run-tests

rebuild: clean-all run-tests lib

lib: library-core

# Tests are run with local build
.PHONY: run-tests
run-tests: lib $(TESTS_BINS)
	@for TEST_BIN in $(TESTS_BINS) ; do   \
		LD_LIBRARY_PATH=$(LIB_DIR)/ ./$$TEST_BIN; \
	done

# Release objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(RELEASE_CFLAGS) -c $^ -o $@

# Test objects
$(TESTS_OBJ_DIR)/%.o: $(TESTS_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(TESTS_CFLAGS) -c $^ -o $@

# Test binaries
.PHONY: tests-binaries
tests-binaries: $(TESTS_BINS)
$(TESTS_BIN_DIR)/%: $(TESTS_OBJ_DIR)/%.o $(TESTS_UTILS_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(TESTS_LDFLAGS) $^ -o $@

# Don't delete objects when binaries are made
.PRECIOUS: $(OBJ_DIR)/%.o $(TESTS_OBJ_DIR)/%.o

# Local build
library-core: $(LIB_DIR)/$(LIB_REALNAME)
$(LIB_DIR)/$(LIB_REALNAME): $(RELEASE_OBJ)
	@mkdir -p $(LIB_DIR)/
	$(CC) $(RELEASE_LDFLAGS) -o $@ $^
	strip --discard-all $(LIB_DIR)/$(LIB_REALNAME)
	ln -s $@ $(LIB_DIR)/$(LIB_SONAME)
	ln -s $(LIB_DIR)/$(LIB_SONAME) $(LIB_DIR)/$(LIB_LINKER_NAME)

.PHONY: clean
clean:
	rm -rf $(RELEASE_OBJ) $(TESTS_OBJ) $(TESTS_UTILS_OBJ)

.PHONY: clean-all
clean-all: clean
	rm -rf $(TESTS_BINS) $(LIB_DIR)/*
