### WARNING - DON'T STOP THIS SCRIPT UNTIL IT HAS FINISHED ###
### YOU COULD DAMAGE YOUR IMAGE ###

MICROSD_NAME=mmcblk0


# Run from this script dir
cd poky-dunfell-23.0.2/rpi4

# Clean microSD
# From 10 to 45 min depending on your microSD memory size
sudo dd if=/dev/zero of=/dev/$MICROSD_NAME bs=1M

# Copy image
cd tmp/deploy/images/raspberrypi4
sudo bmaptool copy rpi-basic-image-raspberrypi2.wic.bz2 /dev/$MICROSD_NAME
