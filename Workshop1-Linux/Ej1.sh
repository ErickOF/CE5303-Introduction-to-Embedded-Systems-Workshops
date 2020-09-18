# Only text
echo $'Encabezado:\nErick Andrés Obregón Fonseca\n2016123157\n\nSolución del ejercicio1:' > Ejercicio1.txt

# Current system date
date >> Ejercicio1.txt

# Username
whoami >> Ejercicio1.txt

# Linux kernel version
uname -r >> Ejercicio1.txt

# Current user processes list
ps -u | grep $USER >> Ejercicio1.txt

# Displays
cat Ejercicio1.txt
