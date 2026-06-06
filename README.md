# qt-snippets
Code snippets for Qt and QML.

Some snippets use `CMake` to compile. Others use `qmake`.

Both set of snippets can be opened using Qt Creator. Just select `File -> Open Project...` and open the `CMakeLists.txt` or `qt-snippets.pro` file.

## build

    $ mkdir build
    $ cmake -DCMAKE_PREFIX_PATH=/opt/Qt/6.11.1/gcc_64 ..
    $ cmake --build .
