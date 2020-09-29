# Creating a directory for libpng
mkdir ~/libpng

# Download libpng
wget -P ~/libpng wget https://sourceforge.net/projects/libpng/files/libpng16/1.6.34/libpng-1.6.34.tar.gz

# Go to the folder
cd ~/libpng

# Decompress
tar -xvf libpng-1.6.34.tar.gz
rm libpng-1.6.34.tar.gz

cd libpng-1.6.34
