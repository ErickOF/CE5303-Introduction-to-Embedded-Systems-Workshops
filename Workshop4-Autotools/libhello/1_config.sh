# Creating structure
mkdir ~/libhello

# Copy files
cp -r ./* ~/libhello/

# Go to the directory
cd ~/libhello/

# Run Autoconf
autoreconf --install

# Set installation
mkdir build
cd build
mkdir usr

# Config
../configure --prefix=/home/erickof/libhello/build/usr
