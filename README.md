A tiny project to learn how link opencv to a c++ project through cmake and vcpkg.

First install cmake and vcpkg and add the corresponding paths to the system. 

Then clone the repo and create the new application on the repo path
```bash
vcpkg new --application
```
add opencv to the project
```bash
vcpkg add port opencv
```
The file CMakePresets.json set CMAKE_TOOLCHAIN_FILE to the vcpkg system, to do this set the VCPKG_ROOT enviroment variable. After that, each user must create a local file named CMakeUserPresets.json to set VCPKG_ROOT,  
```json
{
    "version": 3,
    "configurePresets": [
        {
            "name": "default",
            "inherits": "vcpkg",
            "environment": {
                "VCPKG_ROOT": "edit here"
            }
        }
    ]
}
```
CMakeLists.txt is already defined. So, we configure and generate (two steps at the same time) the build system files through cmake in different source & build folders,
```bash
cmake --preset=default -B  .\build -S . 
```
In build folder you can see the build system files which depend on your arch and compiler. Finally, make the build
```bash
cmake --build .\build
```
Find the program in build path and run
```bash
capcam [camera index]
```
try camera index 0, 1 and soon. To close window touch a key.

Useful links
* https://learn.microsoft.com/es-mx/vcpkg/get_started/get-started?pivots=shell-cmd
* https://learn.microsoft.com/es-mx/vcpkg/consume/manifest-mode?
