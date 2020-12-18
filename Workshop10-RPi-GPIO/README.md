# **Utilización**

## **Compilación de la biblioteca**
* Ingresar a la carpeta `libdgpio`.
* Ejecutar los siguientes comandos para crear las carpetas necesarias:

```shell
$ mkdir -p build/usr
$ cd build
```

* Ejecutar el script de configuración de las herramientas de compilación cruzada:
```shell
. /opt/poky
```

* Ejecutar Autoconf:
```shell
autoreconf --install
```

* Ejecutar el script de configuración de AutoTools:
```shell
$ ../configure --prefix=/path/to/dir/T10_ErickObregon/libdgpio/build/usr
```

* Construir la biblioteca:
```shell
$ make
```

* Instalar la biblioteca:
```shell
$ make install
$ cd usr
$ ls
```
