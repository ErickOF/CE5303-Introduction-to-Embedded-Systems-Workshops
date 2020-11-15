LIB_NAME=libtimer

# Creating structure
mkdir ~/$LIB_NAME

# Copy files
cp -r ./* ~/$LIB_NAME/

# Go to the directory
cd ~/$LIB_NAME/

# Run Autoconf
autoreconf --install

# Set installation
mkdir build
cd build
mkdir usr

# Config
../configure --prefix=/home/erickof/libtimer/build/usr
