#!/bin/sh
git submodule update --remote --merge
ln -s tools/cmake-tool/init-build.sh init-build.sh
ln -s tools/cmake-tool/default-CMakeLists.txt CMakeLists.txt
ln -s tools/cmake-tool/init-build.sh init-build.sh
cd usr.bin/make && ./bootstrap
