# Creating structure
mkdir ~/helloworld

# Copy files
cp -r ./* ~/helloworld/

# Go to the directory
cd ~/helloworld/

# Run Autoconf
autoreconf --install

# Set installation
mkdir build
cd build
mkdir usr

# Config
../configure --prefix=/home/erickof/helloworld/build/usr
