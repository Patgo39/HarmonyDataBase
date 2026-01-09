# HarmonyDataBase
Base de datos musical que recopila etiquetas id3 de archivos MP3 y  permite editar ciertos datos de las canciones

### Requerimientos
- vcpkg package management
  
### Instalación de taglib con vcpkg
```bash
vcpkg install taglib
```

### Clonación del repositorio 
```bash
git clone git@github.com:Patgo39/HarmonyDataBase.git
cd HarmonyDataBase
```
### Configuración y compilación
```bash
cmake -S . -B build \-DCMAKE_TOOLCHAIN_FILE=$(vcpkg env --get-toolchain)
cmake --build build
```
