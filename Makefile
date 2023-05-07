# Makefile

# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror

# Define the source directory
SRC_DIR = src

# Define the object directory
OBJ_DIR = obj

# Define the source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Define the target executable
TARGET = main

# Define the default target
all: $(TARGET)

# Define the target executable rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Define the object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Define the clean rule
clean:
	rm -f $(OBJ_FILES) $(TARGET)

