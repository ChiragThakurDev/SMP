# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source files
SRC = $(wildcard src/*.cpp)

# Output executable
TARGET = build/StudentManagementSystem

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del /Q build\StudentManagementSystem.exe 2>nul || exit 0