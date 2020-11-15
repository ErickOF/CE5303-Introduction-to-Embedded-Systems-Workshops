# Essential Packages, Graphics, Support, Doc and extras
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm bmap-tools

# Download Yocto
wget http://downloads.yoctoproject.org/releases/yocto/yocto-3.1.2/poky-dunfell-23.0.2.tar.bz2

# Install Yocto
tar -xvf poky-dunfell-23.0.2.tar.bz2

# Remove tar.bz2
rm poky-dunfell-23.0.2.tar.bz2

# Download Meta Raspberry
cd poky-dunfell-23.0.2
git clone -b dunfell git://git.yoctoproject.org/meta-raspberrypi
cd ..


