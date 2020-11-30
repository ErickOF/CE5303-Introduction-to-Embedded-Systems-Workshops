# **GPIO LIB 1.0.0**


## **Acerca de**
* **Autor**: Erick Andrés Obregón Fonseca.
* **Carné**: 2016123157.


## **Investigación**
1. ¿Qué pasos debe seguir antes de escribir o leer de un puerto de entrada/salida general (GPIO)?

Primero, se debe exportar el pin que se desea usar en el archivo `/sys/class/gpio/export`. Luego, en el archivo perteneciente a la dirección de dicho pin (`/sys/class/gpio/gpio%d/direction`, donde `%d` corresponde al pin que se usará), se debe escribir si este será una entrada (`in`) o una salida (`out`).


2. ¿Qué comando podría utilizar, bajo Linux, para escribir a un GPIO específico?

```shell
$ echo 24 > /sys/class/gpio/export
$ echo out > /sys/class/gpio/gpio24/direction
$ echo 1 > /sys/class/gpio/gpio24/value
$ echo 24 > /sys/class/gpio/unexport
```


## **SDK**

### **Instalación**
Una vez que ha terminado de construir la versión de Poky Dunfell, se deben seguir los siguientes pasos para construir el SDK.

En el directorio raíz de Yocto (poky-dunfell)

1. Ejecutar el script de configuración del ambiente:
```shell
$ source oe-init-build-env rpi4
```

2. Construir el toolchain.
```shell
$ bitbake rpi-basic-image -c populate_sdk
```

3. Instalar el toolchain. Ejecutar:

```shell
$ . tmp/deploy/sdk/poky-glibc-i686-meta-toolchain-cortexa7hf-vfp-vfpv4-neon-toolchain-2.0.sh
```

### **Cross-Compilar la biblioteca**

1. Ejecutar el script para la configuración del ambiente de compilación:
```shell
$ . /opt/poky/3.1.2/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabii
```

2. Probar que el ambiente de compilación esté bien configurado:
```shell
$ echo $CC
```

La salida del comando debería verse simlar a esta:
```shell
arm-poky-linux-gnueabi-gcc -mthumb -mfpu=neon-vfpv4 -mfloat-abi=hard -mcpu=cortex-a7 -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/poky/3.1.2/sysroots/cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi
```

3. Ejecutar:
```shell
$ autoreconf --install
```

4. Crear un entorno de compilación e instalación virtual
```shell
$ mkdir build
$ mkdir usr
```

5. Ejecutar el script de configuración dentro de la carpeta `build`
```shell
$ ../configure --prefix=/path/to/folder/libgpio/build/usr --host=arm-poky-linux-gnueabi
```

6. Una vez terminada la configuración, se procede a construir la biblioteca dentro del directorio `build`:
```shell
$ make -jN
```
donde `N` corresponde a la cantidad de núcleos a usar para la construcción.

7. Finalmente se realiza la instalación de la biblioteca dentro del directory `build`:
```shell
$ make install
```

8. Ahora se copian los archivos generados en la carpeta `usr` dentro de la microSD.

### **Utilización**
Una vez en la Raspberry Pi, ir a la carpeta donde fueron copiados los archivos y ejecutar `src/main.o`
```shell
$ ./main.o
```

