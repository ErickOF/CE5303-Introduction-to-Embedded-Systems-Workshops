# Create dirs
mkdir ~/cmake
mkdir ~/cmake/libsayhello

# Copy files
cp -r . ~/cmake/libsayhello

# Go to the directory
cd ~/cmake/libsayhello

# Create a build directory
mkdir build
cd build

# Create an installation directory
mkdir usr

# Setting the installation path and creating Makefile
cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=/home/erickof/cmake/libsayhello/build/usr

# Build code
make

# Install
make install

# Checking
cd usr/bin && ./hello

# Creating package
cd ../../
make package_source
