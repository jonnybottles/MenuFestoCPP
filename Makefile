# Compiler
# Specify the compiler to use, g++ in this case
CC = g++

# Compiler flags
# Specify the compiler flags to use
# -Wall enables all compiler's warning messages
# -std=c++20 sets the C++ standard to C++20
CFLAGS = -Wall -std=c++20

# The build target executable:
# This specifies the name of the executable file that will be created
TARGET = menufesto

# The library target:
# This specifies the name of the library file that will be created
LIBTARGET = libmenufesto.a

# The 'all' target
# By typing 'make', the 'all' target is made by default
# This will build both the TARGET and LIBTARGET
all: $(TARGET) $(LIBTARGET)

# The TARGET build rule
# This will build the TARGET executable file
# The executable depends on main.cpp and menu.cpp files
# The command to build TARGET is the command after the tab (\t)
$(TARGET): main.cpp menufesto.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp menufesto.cpp

# The LIBTARGET build rule
# This will build the LIBTARGET library file
# The library depends on menu.cpp file
# The first command compiles the menu.cpp file into an object file (menu.o)
# The second command packages the object file into a library file
$(LIBTARGET): menufesto.cpp
	$(CC) $(CFLAGS) -c menufesto.cpp -o menufesto.o
	ar rvs $(LIBTARGET) menufesto.o

# The 'clean' target
# This is used to clean up the files that were created during the build process
# By typing 'make clean', the TARGET, LIBTARGET, and all object files are removed
clean:
	$(RM) $(TARGET) $(LIBTARGET) *.o
