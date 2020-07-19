/usr/bin/x86_64-w64-mingw32-g++-win32 -c -DBUILD_MY_DLL shared_lib.cpp
/usr/bin/x86_64-w64-mingw32-g++-win32 -shared -o shared_lib.dll shared_lib.o -Wl,--out-implib,libshared_lib.a
