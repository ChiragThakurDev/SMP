# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source files
SRC = src/main.cpp src/Student.cpp

# Output executable
TARGET = build/StudentManagementSystem

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del /Q build\StudentManagementSystem.exe 2>nul || exit 0