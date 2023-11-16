# Simple Makefile for polymorphism and inheritance example

# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS =

# Files
HEADER_FILES = Animal.h ChienEtChat.h
SOURCES = Animal.cpp ChienEtChat.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = polymorphism_example

# Default make
all: $(EXECUTABLE)

# Rule for linking the final executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

# Rule for compiling the source files to object files
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

# Dependencies
Animal.o: Animal.h
ChienEtChat.o: ChienEtChat.h Animal.h
main.o: ChienEtChat.h Animal.h

