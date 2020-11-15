WORK_DIR=poky-dunfell-23.0.2
TIMER_MOD_DIR=$WORK_DIR/recipes-drivers/timer-mod

# Creating img dir
mkdir -p $WORK_DIR/rpi4

# Creating dir for downloads
mkdir -p $WORK_DIR/downloads

# Creating dir for drivers
mkdir -p $TIMER_MOD_DIR

# Copy timer module dir to recipes-drivers dir
cp -r timer-mod/* $TIMER_MOD_DIR/

# Config environment
# Run the next line inside of the poky-dunfell-23.0.2 dir
#source oe-init-build-env rpi4

# Add those lines to the poky-dunfell-23.0.2/rpi4/conf/local.conf file
#DL_DIR ?= "/home/usuario/poky-dunfell-23.0.2/downloads"
#INHERIT += "rm_work"
#MACHINE ?= "raspberrypi4"
#CORE IMAGE EXTRA INSTALL += "timer-mod"

# Add this lines to the poky-dunfell-23.0.2/rpi4/conf/bblayers.conf file
#/path/to/dir/poky-dunfell-23.0.2/meta-raspberrypi

