call swig -c++ -javascript -node -DV8_VERSION=0x040685 .\cxx\cpp_back.i
call node-gyp configure build --msvs_version=2015 --arch=ia32 -C .\cxx --python=C:\Python27\python.exe

@echo off
REM cd node_modules\serialport
REM node-pre-gyp rebuild --runtime=node-webkit --target=0.14.7 --msvs_version=2015 --target_arch=ia32 --target_platform=win32 --python=C:\Python27\python.exe