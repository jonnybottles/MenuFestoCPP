#!/bin/bash

# Define the library and header file
LIBFILE="libmenufesto.a"
HEADERFILE="menufesto.h"

# Define the target directories
LIBDIR="/usr/local/lib"
INCLUDEDIR="/usr/local/include"

# Check for root access
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root"
   exit 1
fi

# Copy the files
echo "Installing $LIBFILE to $LIBDIR"
cp $LIBFILE $LIBDIR

echo "Installing $HEADERFILE to $INCLUDEDIR"
cp $HEADERFILE $INCLUDEDIR

echo "Installation complete. Run 'sudo ldconfig' if necessary."

exit 0
