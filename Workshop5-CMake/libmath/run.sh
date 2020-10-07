# Create dirs
mkdir ~/cmake
mkdir ~/cmake/libmath

# Copy files
cp -r . ~/cmake/libmath

# Go to the directory
cd ~/cmake/libmath

# Create a build directory
mkdir build
cd build

# Create an installation directory
mkdir usr

# Setting the installation path and creating Makefile
cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=/home/erickof/cmake/libmath/build/usr

# Build code
make

# Install
make install

# Checking
cd usr/bin && ./main

# Creating package
cd ../../
make package_source
