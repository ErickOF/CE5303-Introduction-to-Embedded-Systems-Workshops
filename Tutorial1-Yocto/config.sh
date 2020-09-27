# Current directory
_dir="$PWD"

cd poky-dunfell-23.0.2

# Creating img dir
mkdir emuARM

# Creating dir for downloads
mkdir downloads

# Config environment
source oe-init-build-env emuARM

cd ..
