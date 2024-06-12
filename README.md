# MenufestoCPP

MenuFesto is a limited C++ menu library that has a clear, defined purpose (much like a manifesto) and set of features to provide for creating and managing menus.

## Files

- **main.cpp**: The main driver code for the program.
- **menufesto.cpp**: Implementation of the menu library.
- **menufesto.h**: Header file for the menu library.
- **install.sh**: Script to install the library and header file to the system.

## Installation

To install the Menufesto library, run the following command:

```sh
sudo ./install.sh
```

This script will copy the library and header file to `/usr/local/lib` and `/usr/local/include` respectively. If necessary, run `sudo ldconfig` after installation.

## Usage

Include the header file in your C++ code:

```cpp
#include "menufesto.h"
```

Link against the library when compiling your program:

```sh
g++ -o myprogram main.cpp -lmenufesto
```
