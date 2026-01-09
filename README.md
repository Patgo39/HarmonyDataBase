# HarmonyDataBase
Base de datos musical que recopila etiquetas id3 de archivos MP3 y  permite editar ciertos datos de las canciones

### Requerimientos y dependencias
**TagLib v2.1.1** [Descargar el .tar.gz](https://taglib.org/) y seguir la [guía de instalación](https://github.com/taglib/taglib/blob/master/INSTALL.md) con Zlib.  **Qt** [Siga la guía de instalación](https://www.qt.io/development/download-qt-installer) o aplique la instalación por distro.

### Clonación del repositorio 
```bash
git clone git@github.com:Patgo39/HarmonyDataBase.git
cd HarmonyDataBase
```
### Configuración y compilación
```bash
vcpkg install
cmake -S . -B build
cmake --build build
```
