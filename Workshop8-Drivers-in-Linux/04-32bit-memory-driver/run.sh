DRIVER_NAME=memory
MAJOR_NUMBER=60

# Create file representing the memory space
sudo mknod /dev/$DRIVER_NAME c $MAJOR_NUMBER 0

# Change permisions
sudo chmod 666 /dev/$DRIVER_NAME

# Compile with the kernel version
make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)

# In case of error, uncomment the follow line
#sudo apt-get install linux-headers-$(uname -r)

# Load driver in userspace
sudo insmod $DRIVER_NAME.ko

# Message in system console
dmesg | tail

# Write in the device file
echo -n HOLAHOLA > /dev/$DRIVER_NAME

# Read device file
cat /dev/$DRIVER_NAME
echo -e "\n"

# Remove driver
sudo rmmod $DRIVER_NAME

# Message in system console
dmesg | tail
