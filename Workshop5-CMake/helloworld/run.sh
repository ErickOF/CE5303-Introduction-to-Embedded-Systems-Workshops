# Create dirs
mkdir ~/cmake
mkdir ~/cmake/helloworld

# Copy files
cp -r . ~/cmake/helloworld

# Go to the directory
cd ~/cmake/helloworld

# Create a build directory
mkdir build
cd build

# Create an installation directory
mkdir usr

# Setting the installation path and creating Makefile
cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=/home/erickof/cmake/helloworld/build/usr

# Build code
make

# Install
make install

# Checking
cd usr/bin && ./hello
