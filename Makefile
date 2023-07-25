# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++20

# The build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): main.cpp menu.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp menu.cpp

clean:
	$(RM) $(TARGET)
