
CC=gcc

# Common structure
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
TESTS_DIR=tests

# Release sources compilation
RELEASE_SRC=$(shell find $(SRC_DIR)/ -type f -name '*.c')
RELEASE_OBJ=$(subst $(SRC_DIR),$(OBJ_DIR),$(RELEASE_SRC:.c=.o))
RELEASE_CFLAGS=-Wall -Wextra -Werror -ansi -pedantic
RELEASE_LDFLAGS=

# Tests only structure
TESTS_SRC_DIR=$(addprefix $(TESTS_DIR)/,$(SRC_DIR))
TESTS_OBJ_DIR=$(addprefix $(TESTS_DIR)/,$(OBJ_DIR))
TESTS_BIN_DIR=$(addprefix $(TESTS_DIR)/,$(BIN_DIR))

# Test sources compilation
TESTS_SRC=$(shell find $(TESTS_SRC_DIR) -type f -name '*.c')
TESTS_OBJ=$(subst $(TESTS_SRC_DIR),$(TESTS_OBJ_DIR),$(TESTS_SRC:.c=.o))
TESTS_CFLAGS=$(subst -ansi,,$(RELEASE_CFLAGS)) # Criterion is not C89 compliant
TESTS_LDFLAGS=-lcriterion
TESTS_BINS=$(subst $(TESTS_SRC_DIR),$(TESTS_BIN_DIR),$(TESTS_SRC:.c=))

default: run-tests

.PHONY: run-tests
run-tests: $(TESTS_BINS)
#	@for TEST_BIN in $(TESTS_BINS) ; do   \
#		./$$TEST_BIN --verbose; \
#	done
	@for TEST_BIN in $(TESTS_BINS) ; do   \
		./$$TEST_BIN; \
	done
#	$(foreach TEST_BIN,$^,./$(TEST_BIN) --verbose)

# Release objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(RELEASE_CFLAGS) -c $^ -o $@

# Test objects
$(TESTS_OBJ_DIR)/%.o: $(TESTS_SRC_DIR)/%.c
	$(CC) $(TESTS_CFLAGS) -c $^ -o $@

# Test binaries
.PHONY: tests-binaries
tests-binaries: $(TESTS_BINS)
$(TESTS_BIN_DIR)/%: $(TESTS_OBJ_DIR)/%.o $(RELEASE_OBJ)
	$(CC) $(TESTS_LDFLAGS) $^ -o $@

# Don't delete objects when binaries are made
.PRECIOUS: $(OBJ_DIR)/%.o $(TESTS_OBJ_DIR)/%.o

.PHONY: clean
clean:
	rm -rf $(RELEASE_OBJ) $(TESTS_OBJ)

.PHONY: clean-all
clean-all: clean
	rm -rf $(TESTS_BINS)
