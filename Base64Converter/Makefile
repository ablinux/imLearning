# Name of the target to build
TARGET := base64

# Foler variables
BUILD = build
OBJ = obj
BIN = bin
SRC = src

# Variable to hold generated object file
OBJS=$(OBJ)/main.o $(OBJ)/base64.o

# Compiler variables
CC := gcc
CFLAGS := -Wall

# Include mak files

# Include dir
INCLUDE_DIR = ./include

# Build the application 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
	size $(BIN)/$(TARGET)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE_DIR) -o $@

$(BUILD):
	mkdir $@

# Run the code
run:
	$(BIN)/$(TARGET)

# Clean up everything
clean:
	rm $(OBJ)/* $(BIN)/$(TARGET)