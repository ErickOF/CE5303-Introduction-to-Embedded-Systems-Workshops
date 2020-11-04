DRIVER_NAME=nothing

# Compile with the kernel version
make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)

# In case of error, uncomment the follow line
#sudo apt-get install linux-headers-$(uname -r)

# Load driver in userspace
sudo insmod $DRIVER_NAME.ko

# Check the driver
echo -e "\033[0;32mAll modules\033[0m"
lsmod

echo -e "\033[0;32m$DRIVER_NAME module\033[0m"
lsmod | grep $DRIVER_NAME

# Remove driver
sudo rmmod $DRIVER_NAME
