# Name of the target to build
TARGET := LinkList

# Foler variables
BUILD = build
OBJ = obj
BIN = bin
SRC = src

# Variable to hold generated object file
OBJS=$(OBJ)/main.o $(OBJ)/LinkList.o

# Compiler variables
CC := gcc
CFLAGS := -Wall

# Include mak files

# Include dir
INCLUDE_DIR = ./inc

################## Build the application ###############################
all: $(TARGET)

deps:= $(patsubst %.o, %.d, $(OBJS))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(BIN)/$@
	size $(BIN)/$(TARGET)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE_DIR) -o $@ $(DEPFLAGS)

######################## END #############################################

$(BUILD):
	mkdir $@


# Run the code
run:
	$(BIN)/$(TARGET)

# Clean up everything
clean:
	rm -f $(OBJ)/* $(BIN)/$(TARGET) $(deps)


############ Learning MakeFile ##############################
print: $(wildcard *.c $(SRC)/*.c)
	ls -al $?
	echo $(deps)
	echo "Object that needs to build $(OBJS) $(OBJ)/%.o"