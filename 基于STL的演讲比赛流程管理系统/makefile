# Makefile for compiling the C++ code

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11

# Source files
SRCS = main.cpp speechManager.cpp competitor.cpp

# Executable name
EXEC = main

# Build directory
BUILD_DIR = build

# Object files
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Rule for creating object files
$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for linking object files into executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule for cleaning build files
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)

# Rule for creating build directory
$(shell mkdir -p $(BUILD_DIR))

# Phony targets
.PHONY: all clean

# Default target
all: $(EXEC)
