# List of source files
SOURCES := start.cpp brandlogo.c

# Object files are the .cpp and .c files with .o extension
OBJECTS := $(SOURCES:.cpp=.o) $(SOURCES:.c=.o)

# Info for the include path
INC_DIR = Include 
LIB_DIR = Include/Lib

# Compiler
CC := g++

# Output executable
EXECUTABLE := fm

# The first rule is the default when running 'make'
all: $(EXECUTABLE)

# Rule to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Rule to create object files from .cpp
%.o: %.cpp
	$(CC) -c $< -o $@ -I$(INC_DIR)

# Rule to create object files from .c
%.o: %.c
	$(CC) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
