#!/bin/sh
git submodule init
git submodule update
#ln -s tools/cmake-tool/init-build.sh init-build.sh
#ln -s tools/cmake-tool/default-CMakeLists.txt CMakeLists.txt
#ln -s tools/cmake-tool/init-build.sh init-build.sh
cd usr.bin/make && ./bootstrap
