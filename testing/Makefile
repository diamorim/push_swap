CC = cc
CFLAGS = -Wall -Wextra -Werror

PROJECT_DIR = ..

SRC = $(wildcard $(PROJECT_DIR)/*_prog/*.c)

#removes main if it exists
SRC := $(filter-out $(PROJECT_DIR)/main.c, $(SRC))

INCLUDE = helper_func.c

TEST_DIR = tests
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

TEST_BIN = test_runner

LIBFT = $(PROJECT_DIR)/libft/libft.a

CRITERION = -lcriterion

all: test

build:
	$(CC) \
	$(CFLAGS) \
	-I$(PROJECT_DIR) \
	$(SRC) \
	$(LIBFT) \
	$(INCLUDE) \
	$(TEST_SRC) \
	$(CRITERION) \
	-o $(TEST_BIN)

test: build
	./$(TEST_BIN)
clean:
	rm -f $(TEST_BIN)

re: clean test

.PHONY: all build test clean re